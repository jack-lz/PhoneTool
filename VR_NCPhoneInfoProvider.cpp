/**
 * Copyright @ 2014 - 2017 Suntec Software(Shanghai) Co., Ltd.
 * All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are NOT permitted except as agreed by
 * Suntec Software(Shanghai) Co., Ltd.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 */

#include <boost/assign.hpp>
#include "VR_Log.h"
#include "BL_File.h"
#include "BL_Dir.h"
#include "VR_NCPhoneInfoProvider.h"

using namespace nutshell;

#define VR_NCPHONE_INFO_DATABASE_PATH      "/var/user/navi/.VDATA/RW"
#define VR_NCPHONE_INFO_PROVIDER_NAME      "phoneinfo"
#define VR_NCPHONE_INFO_DATABASE_NAME      "phoneprovider.db"
#define VR_NCPhone_DATABASE_VERSION        1

// Phone Table Flag
enum VR_NCPhoneInfoMatcherStatus
{
    VR_MATCHER_ID_PHONE_CALLHISTORY_DATA = 0, // Callhistory Table
    VR_MATCHER_ID_Phone_PHONE_CONTACTS_DATA,  // Contacts Table
    VR_MATCHER_ID_Phone_PHONE_FAVORITES_DATA, // Favorites Table
    VR_MATCHER_ID_Phone_PHONE_VOICE_TAGS_DATA,// Voice_Tags Table
    VR_MATCHER_ID_Phone_PHONE_WIDGETS_DATA    // Widgets Table
};

VR_NCPhoneInfoProvider::UriMatchRelateMap VR_NCPhoneInfoProvider::m_MatchRelate = boost::assign::map_list_of
         ((INT)VR_MATCHER_ID_PHONE_CALLHISTORY_DATA, VR_TABLE_OF_PHONE_CALLHISTORY)
         ((INT)VR_MATCHER_ID_Phone_PHONE_CONTACTS_DATA, VR_TABLE_OF_PHONE_CONTACTS)
         ((INT)VR_MATCHER_ID_Phone_PHONE_FAVORITES_DATA, VR_TABLE_OF_PHONE_FAVORITES)
         ((INT)VR_MATCHER_ID_Phone_PHONE_VOICE_TAGS_DATA, VR_TABLE_OF_PHONE_VOICE_TAGS)
         ((INT)VR_MATCHER_ID_Phone_PHONE_WIDGETS_DATA, VR_TABLE_OF_PHONE_WIDGETS);

VR_NCPhoneInfoProvider::VR_NCPhoneInfoProvider(const NCString& serviceName)
    : NCContentProvider(VR_NCPHONE_INFO_PROVIDER_NAME, serviceName)
    , m_uriMatcher()
{
    // add URL
    m_uriMatcher.addURI(VR_NCPHONE_INFO_PROVIDER_NAME,
                        m_MatchRelate[(INT)VR_MATCHER_ID_PHONE_CALLHISTORY_DATA] + "/data",
                        (INT)VR_MATCHER_ID_PHONE_CALLHISTORY_DATA);
    m_uriMatcher.addURI(VR_NCPHONE_INFO_PROVIDER_NAME,
                        m_MatchRelate[(INT)VR_MATCHER_ID_Phone_PHONE_CONTACTS_DATA] + "/data",
                        (INT)VR_MATCHER_ID_Phone_PHONE_CONTACTS_DATA);
    m_uriMatcher.addURI(VR_NCPHONE_INFO_PROVIDER_NAME,
                        m_MatchRelate[(INT)VR_MATCHER_ID_Phone_PHONE_FAVORITES_DATA] + "/data",
                        (INT)VR_MATCHER_ID_Phone_PHONE_FAVORITES_DATA);
    m_uriMatcher.addURI(VR_NCPHONE_INFO_PROVIDER_NAME,
                        m_MatchRelate[(INT)VR_MATCHER_ID_Phone_PHONE_VOICE_TAGS_DATA] + "/data",
                        (INT)VR_MATCHER_ID_Phone_PHONE_VOICE_TAGS_DATA);
    m_uriMatcher.addURI(VR_NCPHONE_INFO_PROVIDER_NAME,
                        m_MatchRelate[(INT)VR_MATCHER_ID_Phone_PHONE_WIDGETS_DATA] + "/data",
                        (INT)VR_MATCHER_ID_Phone_PHONE_WIDGETS_DATA);

    BL_String phoneInfoDBFullPath;
    phoneInfoDBFullPath = NCString(VR_NCPHONE_INFO_DATABASE_PATH) + "/" + VR_NCPHONE_INFO_DATABASE_NAME;

    VR_LOGD("Phone provider db path:%s", phoneInfoDBFullPath.GetString());
    m_dbHelper = VR_new VR_NCPhoneInfoDatabaseHelper(NCString(phoneInfoDBFullPath.GetString()), VR_NCPhone_DATABASE_VERSION);
}

VR_NCPhoneInfoProvider::~VR_NCPhoneInfoProvider()
{
    if (NULL != m_dbHelper) {
        delete m_dbHelper;
    }
}

NCCursor* VR_NCPhoneInfoProvider::query(const NCUri& uri, const NCList<NCString>& select,
                                           const NCString& where, const NCList<NCString>& whereArgs,
                                           const NCString& sort)
{
    VR_LOGD("VR_NCPhoneInfoProvider::query");
    if (NULL == m_dbHelper) {
        VR_LOGD("VR_NCPhoneInfoProvider m_dbHelper does not exist");
        return NULL;
    }

    // 1.get database object
    NCSQLiteDatabase* db = m_dbHelper->getDatabase();
    if (NULL == db) {
        VR_LOGD("VR_NCPhoneInfoProvider database does not exist");
        return NULL;
    }

    // 2.match uri
    INT result = m_uriMatcher.match(uri);
    if (NCUriMatcher::NO_MATCH == result) {
        VR_LOGD("VR_NCPhoneInfoProvider uri is not supported");
        return NULL;
    }

    // 3.query table all data
    NCString table = m_MatchRelate[result];

    VR_LOGD("begin query table:%s", table.getString());
    NCCursor* cursor = db->query(table, select, where, whereArgs, sort);
    VR_LOGD("end query table.cursorAddr:%p", cursor);
    return cursor;
}

INT64 VR_NCPhoneInfoProvider::insert(const NCUri& uri, const NCContentValues& values)
{
    VR_LOGD("VR_NCPhoneInfoProvider::insert");
    if (NULL == m_dbHelper) {
        VR_LOGD("VR_NCPhoneInfoProvider m_dbHelper does not exist");
        return -1;
    }

    // 1.get database object
    NCSQLiteDatabase* db = m_dbHelper->getDatabase();
    if (NULL == db) {
        VR_LOGD("VR_NCPhoneInfoProvider database does not exist");
        return -1;
    }

    // 2.match uri
    INT result = m_uriMatcher.match(uri);
    if (NCUriMatcher::NO_MATCH == result) {
        VR_LOGD("VR_NCPhoneInfoProvider uri is not supported");
        return -1;
    }

    // 3.insert table data
    NCString table = m_MatchRelate[result];

    VR_LOGD("begin insert table:%s", table.getString());
    INT64 rowId = db->insert(table, values);
    if (-1 == rowId) {
        VR_LOGD("%s table insert failed,Error is [%d]", table.getString(), db->getLastError());
    }
    else {
        VR_LOGD("Notify table insert table succeed");
        //   NCVariant Variant("available");
        //   notifyInsert(NCUri(uri.toString() + "?Notify"), Variant);
        NCVariant Variant("true");
        notifyUpdate(NCUri(uri.toString() + "?Notify"), Variant);
        VR_LOGD("Notify succeed is [%s]", NCUri(uri.toString() + "?Notify").toString().getString());
    }
    VR_LOGD("end insert table");
    return rowId;
}

INT32 VR_NCPhoneInfoProvider::update(const NCUri& uri, const NCContentValues& values,
                                        const NCString& where, const NCList<NCString>& whereArgs)
{
    VR_LOGD("VR_NCPhoneInfoProvider::update");
    if (NULL == m_dbHelper) {
        VR_LOGD("VR_NCPhoneInfoProvider m_dbHelper does not exist");
        return 0;
    }

    // 1.get database object
    NCSQLiteDatabase* db = m_dbHelper->getDatabase();
    if (NULL == db) {
        VR_LOGD("VR_NCPhoneInfoProvider database does not exist");
        return 0;
    }

    // 2.match uri
    INT result = m_uriMatcher.match(uri);
    if (NCUriMatcher::NO_MATCH == result) {
        VR_LOGD("VR_NCPhoneInfoProvider uri is not supported");
        return 0;
    }

    // 3.update table data by index
    NCString table = m_MatchRelate[result];

    VR_LOGD("begin update table:%s", table.getString());
    INT numChanges = db->update(table, values, where, whereArgs);
    if (0 == numChanges) {
        VR_LOGD("%s table update failed,Error is [%d]", table.getString(), db->getLastError());
    }
    else {
        VR_LOGD("notify table update");
        NCVariant Variant("available");
        notifyUpdate(NCUri(uri.toString() + "?Notify"), Variant);
        VR_LOGD("uri = [%s]", uri.toString().getString());
    }
    VR_LOGD("end update table");
    return numChanges;
}

INT32 VR_NCPhoneInfoProvider::remove(const NCUri& uri, const NCString& where,
                                        const NCList<NCString>& whereArgs)
{
    VR_LOGD("VR_NCPhoneInfoProvider::remove");
    if (NULL == m_dbHelper) {
        VR_LOGD("VR_NCPhoneInfoProvider m_dbHelper does not exist");
        return 0;
    }

    // 1.get database object
    NCSQLiteDatabase* db = m_dbHelper->getDatabase();
    if (NULL == db) {
        VR_LOGD("VR_NCPhoneInfoProvider database does not exist");
        return 0;
    }

    // 2.match uri
    INT result = m_uriMatcher.match(uri);
    if (NCUriMatcher::NO_MATCH == result) {
        VR_LOGD("VR_NCPhoneInfoProvider uri is not supported");
        return 0;
    }

    // 3.delete table data by index
    NCString table = m_MatchRelate[result];

    VR_LOGD("begin remove table:%s", table.getString());
    INT numChanges = db->remove(table, where, whereArgs);
    if (0 == numChanges) {
        VR_LOGD("%s table remove failed,Error is [%d]", table.getString(), db->getLastError());
    }
    else {
        VR_LOGD("Notify table remove succeed by notifyupdate");
        // notifyRemove(NCUri(uri.toString() + "?Notify"));
        NCVariant Variant("available");
        notifyUpdate(NCUri(uri.toString() + "?Notify"), Variant);
    }
    VR_LOGD("end remove table");
    return numChanges;
}

NCString VR_NCPhoneInfoProvider::getType(const NCUri& uri)
{
    VR_LOGD("VR_NCPhoneInfoProvider::getType");
    return NCString(VR_NCPHONE_INFO_PROVIDER_NAME);
}

VOID VR_NCPhoneInfoProvider::onInitialize()
{
    VR_LOGD("VR_NCPhoneInfoProvider::onInitialize");
}

VOID VR_NCPhoneInfoProvider::onStart()
{
    VR_LOGD("VR_NCPhoneInfoProvider::onStart");
}

VOID VR_NCPhoneInfoProvider::onStop()
{
    VR_LOGD("VR_NCPhoneInfoProvider::onStop");
}

VOID VR_NCPhoneInfoProvider::onDeinitialize()
{
    VR_LOGD("VR_NCPhoneInfoProvider::onDeinitialize");
}


/* EOF */
