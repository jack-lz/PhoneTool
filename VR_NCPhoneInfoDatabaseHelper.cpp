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

#include "VR_Log.h"
#include "VR_NCPhoneInfoDatabaseHelper.h"

using namespace nutshell;

const NCCHAR* VR_NCPhoneInfoDatabaseHelper::g_createSQLTemplate[] = {
    VR_PHONE_CREATE_TABLE_OF_CALLHISTORY_SQL,
    VR_PHONE_CREATE_TABLE_OF_CONTACTS_SQL,
    VR_PHONE_CREATE_TABLE_OF_FAVORITES_SQL,
    VR_PHONE_CREATE_TABLE_OF_VOICE_TAGS_SQL,
    VR_PHONE_CREATE_TABLE_OF_WIDGETS_SQL
};

VR_NCPhoneInfoDatabaseHelper::VR_NCPhoneInfoDatabaseHelper(const NCString& name, INT version)
    :NCSQLiteOpenHelper(name, version)
{
}

VR_NCPhoneInfoDatabaseHelper::~VR_NCPhoneInfoDatabaseHelper()
{
}

void VR_NCPhoneInfoDatabaseHelper::onCreate(NCSQLiteDatabase *db)
{
    if (NULL == db) {
        return;
    }

    VR_LOGD("VR_NCPhoneInfoDatabaseHelper::onCreate");
    createTable(db);
}

void VR_NCPhoneInfoDatabaseHelper::onUpgrade(NCSQLiteDatabase *db, INT oldVersion, INT newVersion)
{
    if (NULL == db) {
        return;
    }

    // sample
    if (m_PhoneProviderVersion == oldVersion) {
        if (oldVersion != newVersion) {
            // TODO drop all tables
            // Create all tables again
            onCreate(db);
            m_PhoneProviderVersion = newVersion;
        }
    }
}

void VR_NCPhoneInfoDatabaseHelper::onDowngrade(NCSQLiteDatabase *db, INT oldVersion, INT newVersion)
{
    VR_LOGD("VR_NCPhoneInfoDatabaseHelper::onDowngrade");
}

void VR_NCPhoneInfoDatabaseHelper::onOpen(NCSQLiteDatabase *db)
{
    VR_LOGD("VR_NCPhoneInfoDatabaseHelper::onOpen");

      // 1.check param
    if (NULL == db) {
        return;
    }

    NCString  ncSQL = "select * from sqlite_master where name='Phone_category' and sql like '%update_status%';";
    NCList<NCString> list;
    NCCursor* cursor = db->rawQuery(ncSQL, list);
    if (NULL != cursor) {
        if (cursor->getCount() <= 0) {
            ncSQL = "alter table Phone_category add column update_status INTEGER DEFAULT 0;";
            db->execSQL(ncSQL);
        }
        delete cursor;
    }
    else {
        ncSQL = "alter table Phone_category add column update_status INTEGER DEFAULT 0;";
        db->execSQL(ncSQL);
    }
}

void VR_NCPhoneInfoDatabaseHelper::createTable(NCSQLiteDatabase *db)
{
    INT result = 0;

    // 1.check param
    if (NULL == db) {
        return;
    }

    // 2.create table set
    INT templateCount = sizeof(g_createSQLTemplate) / sizeof(NCCHAR*);
    for (INT i = 0; i < templateCount; i++) {
        result = db->execSQL(g_createSQLTemplate[i]);
        if (0 != result) {
            VR_LOGD("ErrCode:%d.%s failed", result, g_createSQLTemplate[i]);
            return;
        }
    }
}
/* EOF */

