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

#include "VR_NCPhoneInfoOperator.h"
#include "VR_Log.h"

using namespace nutshell;


VR_NCPhoneInfoOperator::VR_NCPhoneInfoOperator()
    :m_resolver(VR_new NCContentResolver)
{
    VR_LOGD_FUNC();
}

VR_NCPhoneInfoOperator::~VR_NCPhoneInfoOperator()
{
    VR_LOGD_FUNC();
}

BOOL VR_NCPhoneInfoOperator::InsertPhoneCallhistoryData(const callhistoryData& callhistory)
{
    NCContentValues values;
    values.put("_id", callhistory._id);
    values.put("contact_id", callhistory.contact_id);
    values.put("firstname", callhistory.firstname);
    values.put("lastname", callhistory.lastname);
    values.put("phone_type", callhistory.phone_type);
    values.put("phone_index", callhistory.phone_index);
    values.put("phone_number", callhistory.phone_number);
    values.put("phone_domesticnumber", callhistory.phone_domesticnumber);
    values.put("calltype", callhistory.calltype);
    values.put("calltime", callhistory.calltime);
    values.put("timezone", callhistory.timezone);
    values.put("count", callhistory.count);
    values.put("is_targettime", callhistory.is_targettime);

    INT64 rowId = m_resolver->insert(NCUri(VR_TABLE_OF_PHONE_CALLHISTORY_URL), values);
    if (-1 == rowId) {
        VR_LOGD("insert PHONE_CALLHISTORY data failed");
        return FALSE;
    }
    else {
        VR_LOGD("insert PHONE_CALLHISTORY data succeed");
        return TRUE;
    }
}

BOOL VR_NCPhoneInfoOperator::InsertPhoneContactsData(const contactsData& contacts)
{
    NCContentValues values;
    values.put("_id", contacts._id);
    values.put("contact_id", contacts.contact_id);
    values.put("firstname", contacts.firstname);
    values.put("lastname", contacts.lastname);
    values.put("sort_fl", contacts.sort_fl);
    values.put("sort_lf", contacts.sort_lf);
    values.put("phone_number", contacts.phone_number);
    values.put("phone1_type", contacts.phone1_type);
    values.put("phone1_index", contacts.phone1_index);
    values.put("phone1_number", contacts.phone1_number);
    values.put("phone1_domesticnumber", contacts.phone1_domesticnumber);
    values.put("phone1_widget", contacts.phone1_widget);
    values.put("phone2_type", contacts.phone2_type);
    values.put("phone2_index", contacts.phone2_index);
    values.put("phone2_number", contacts.phone2_number);
    values.put("phone2_domesticnumber", contacts.phone2_domesticnumber);
    values.put("phone2_widget", contacts.phone2_widget);
    values.put("phone3_type", contacts.phone3_type);
    values.put("phone3_index", contacts.phone3_index);
    values.put("phone3_number", contacts.phone3_number);
    values.put("phone3_domesticnumber", contacts.phone3_domesticnumber);
    values.put("phone3_widget", contacts.phone3_widget);
    values.put("phone4_type", contacts.phone4_type);
    values.put("phone4_index", contacts.phone4_index);
    values.put("phone4_number", contacts.phone4_number);
    values.put("phone4_domesticnumber", contacts.phone4_domesticnumber);
    values.put("phone4_widget", contacts.phone4_widget);
    values.put("email1_type", contacts.email1_type);
    values.put("email1_addr", contacts.email1_addr);
    values.put("email2_type", contacts.email2_type);
    values.put("email2_addr", contacts.email2_addr);
    values.put("email3_type", contacts.email3_type);
    values.put("email3_addr", contacts.email3_addr);
    values.put("email4_type", contacts.email4_type);
    values.put("email4_addr", contacts.email4_addr);
    values.put("address1", contacts.address1);
    values.put("address2", contacts.address2);
    values.put("address3", contacts.address3);
    values.put("address4", contacts.address4);
    values.put("is_favor", contacts.is_favor);
    values.put("voicetag", contacts.voicetag);
    values.put("photo_status", contacts.photo_status);
    values.put("is_selected", contacts.is_selected);

    INT64 rowId = m_resolver->insert(NCUri(VR_TABLE_OF_PHONE_CONTACTS_URL), values);
    if (-1 == rowId) {
        VR_LOGD("insert PHONE_CONTACTS data failed");
        return FALSE;
    }
    else {
        VR_LOGD("insert PHONE_CONTACTS data succeed");
        return TRUE;
    }
}

BOOL VR_NCPhoneInfoOperator::InsertPhoneFavoritesData(const favoritesData& favorites)
{
    NCContentValues values;
    values.put("_id", favorites._id);
    values.put("contact_id", favorites.contact_id);
    values.put("firstname", favorites.firstname);
    values.put("lastname", favorites.lastname);
    values.put("sort_fl", favorites.sort_fl);
    values.put("sort_lf", favorites.sort_lf);
    values.put("phone_number", favorites.phone_number);
    values.put("phone1_type", favorites.phone1_type);
    values.put("phone1_index", favorites.phone1_index);
    values.put("phone1_number", favorites.phone1_number);
    values.put("phone2_type", favorites.phone2_type);
    values.put("phone2_index", favorites.phone2_index);
    values.put("phone2_number", favorites.phone2_number);
    values.put("phone3_type", favorites.phone3_type);
    values.put("phone3_index", favorites.phone3_index);
    values.put("phone3_number", favorites.phone3_number);
    values.put("phone4_type", favorites.phone4_type);
    values.put("phone4_index", favorites.phone4_index);
    values.put("phone4_number", favorites.phone4_number);
    values.put("email1_type", favorites.email1_type);
    values.put("email1_addr", favorites.email1_addr);
    values.put("email2_type", favorites.email2_type);
    values.put("email2_addr", favorites.email2_addr);
    values.put("email3_type", favorites.email3_type);
    values.put("email3_addr", favorites.email3_addr);
    values.put("email4_type", favorites.email4_type);
    values.put("email4_addr", favorites.email4_addr);
    values.put("address1", favorites.address1);
    values.put("address2", favorites.address2);
    values.put("address3", favorites.address3);
    values.put("address4", favorites.address4);
    values.put("is_selected", favorites.is_selected);

    INT64 rowId = m_resolver->insert(NCUri(VR_TABLE_OF_PHONE_FAVORITES_URL), values);
    if (-1 == rowId) {
        VR_LOGD("insert PHONE_FAVORITES data failed");
        return FALSE;
    }
    else {
        VR_LOGD("insert PHONE_FAVORITES data succeed");
        return TRUE;
    }
}

BOOL VR_NCPhoneInfoOperator::InsertPhoneVoiceTagsData(const voiceTagsData& voiceTags)
{
    NCContentValues values;
    values.put("_id", voiceTags._id);
    values.put("contact_id", voiceTags.contact_id);
    values.put("voicetag_id", voiceTags.voicetag_id);
    values.put("firstname", voiceTags.firstname);
    values.put("lastname", voiceTags.lastname);
    values.put("phone1_number", voiceTags.phone1_number);
    values.put("phone2_number", voiceTags.phone2_number);
    values.put("phone3_number", voiceTags.phone3_number);
    values.put("phone4_number", voiceTags.phone4_number);
    values.put("is_selected", voiceTags.is_selected);

    INT64 rowId = m_resolver->insert(NCUri(VR_TABLE_OF_PHONE_VOICE_TAGS_URL), values);
    if (-1 == rowId) {
        VR_LOGD("insert PHONE_VOICE_TAGS data failed");
        return FALSE;
    }
    else {
        VR_LOGD("insert PHONE_VOICE_TAGS data succeed");
        return TRUE;
    }
}

BOOL VR_NCPhoneInfoOperator::InsertPhoneWidgetsData(const widgetsData& widgets)
{
    NCContentValues values;
    values.put("_id", widgets._id);
    values.put("contact_id", widgets.contact_id);
    values.put("sub_id", widgets.sub_id);
    values.put("firstname", widgets.firstname);
    values.put("lastname", widgets.lastname);
    values.put("phone_type", widgets.phone_type);
    values.put("phone_index", widgets.phone_index);
    values.put("phone_number", widgets.phone_number);
    values.put("phone_domesticnumber", widgets.phone_domesticnumber);

    INT64 rowId = m_resolver->insert(NCUri(VR_TABLE_OF_PHONE_WIDGETS_URL), values);
    if (-1 == rowId) {
        VR_LOGD("insert PHONE_WIDGETS data failed");
        return FALSE;
    }
    else {
        VR_LOGD("insert PHONE_WIDGETS data succeed");
        return TRUE;
    }
}



INT32 VR_NCPhoneInfoOperator::UpdatePhoneCallhistoryData(const callhistoryData& callhistory)
{
    NCContentValues values;
    values.put("_id", callhistory._id);
    values.put("contact_id", callhistory.contact_id);
    values.put("firstname", callhistory.firstname);
    values.put("lastname", callhistory.lastname);
    values.put("phone_type", callhistory.phone_type);
    values.put("phone_index", callhistory.phone_index);
    values.put("phone_number", callhistory.phone_number);
    values.put("phone_domesticnumber", callhistory.phone_domesticnumber);
    values.put("calltype", callhistory.calltype);
    values.put("calltime", callhistory.calltime);
    values.put("timezone", callhistory.timezone);
    values.put("count", callhistory.count);
    values.put("is_targettime", callhistory.is_targettime);


    NCString select = "_id = ?";
    NCList<NCString> whereArgs;
    NCString* arg1 = VR_new NCString();
    arg1->format("%d", callhistory._id);
    whereArgs << arg1;
    INT32 rowId = m_resolver->update(NCUri(VR_TABLE_OF_PHONE_CALLHISTORY_URL), values, select, whereArgs);
    if (0 == rowId) {
        VR_LOGD("Update PHONE_CALLHISTORY data failed");
    }
    else {
        VR_LOGD("Update PHONE_CALLHISTORY data succeed");
    }
    return rowId;
}

INT32 VR_NCPhoneInfoOperator::UpdatePhoneContactsData(const contactsData& contacts)
{
    NCContentValues values;
    values.put("_id", contacts._id);
    values.put("contact_id", contacts.contact_id);
    values.put("firstname", contacts.firstname);
    values.put("lastname", contacts.lastname);
    values.put("sort_fl", contacts.sort_fl);
    values.put("sort_lf", contacts.sort_lf);
    values.put("phone_number", contacts.phone_number);
    values.put("phone1_type", contacts.phone1_type);
    values.put("phone1_index", contacts.phone1_index);
    values.put("phone1_number", contacts.phone1_number);
    values.put("phone1_domesticnumber", contacts.phone1_domesticnumber);
    values.put("phone1_widget", contacts.phone1_widget);
    values.put("phone2_type", contacts.phone2_type);
    values.put("phone2_index", contacts.phone2_index);
    values.put("phone2_number", contacts.phone2_number);
    values.put("phone2_domesticnumber", contacts.phone2_domesticnumber);
    values.put("phone2_widget", contacts.phone2_widget);
    values.put("phone3_type", contacts.phone3_type);
    values.put("phone3_index", contacts.phone3_index);
    values.put("phone3_number", contacts.phone3_number);
    values.put("phone3_domesticnumber", contacts.phone3_domesticnumber);
    values.put("phone3_widget", contacts.phone3_widget);
    values.put("phone4_type", contacts.phone4_type);
    values.put("phone4_index", contacts.phone4_index);
    values.put("phone4_number", contacts.phone4_number);
    values.put("phone4_domesticnumber", contacts.phone4_domesticnumber);
    values.put("phone4_widget", contacts.phone4_widget);
    values.put("email1_type", contacts.email1_type);
    values.put("email1_addr", contacts.email1_addr);
    values.put("email2_type", contacts.email2_type);
    values.put("email2_addr", contacts.email2_addr);
    values.put("email3_type", contacts.email3_type);
    values.put("email3_addr", contacts.email3_addr);
    values.put("email4_type", contacts.email4_type);
    values.put("email4_addr", contacts.email4_addr);
    values.put("address1", contacts.address1);
    values.put("address2", contacts.address2);
    values.put("address3", contacts.address3);
    values.put("address4", contacts.address4);
    values.put("is_favor", contacts.is_favor);
    values.put("voicetag", contacts.voicetag);
    values.put("photo_status", contacts.photo_status);
    values.put("is_selected", contacts.is_selected);

    NCString select = "_id = ?";
    NCList<NCString> whereArgs;
    NCString* arg1 = VR_new NCString();
    arg1->format("%d", contacts._id);
    whereArgs << arg1;
    INT64 rowId = m_resolver->update(NCUri(VR_TABLE_OF_PHONE_CONTACTS_URL), values, select, whereArgs);
    if (0 == rowId) {
        VR_LOGD("Update Phone_Contacts data failed");
    }
    else {
        VR_LOGD("Update Phone_Contacts data succeed");
    }
    return rowId;
}

INT32 VR_NCPhoneInfoOperator::UpdatePhoneFavoritesData(const favoritesData& favorites)
{
    NCContentValues values;
    values.put("_id", favorites._id);
    values.put("contact_id", favorites.contact_id);
    values.put("firstname", favorites.firstname);
    values.put("lastname", favorites.lastname);
    values.put("sort_fl", favorites.sort_fl);
    values.put("sort_lf", favorites.sort_lf);
    values.put("phone_number", favorites.phone_number);
    values.put("phone1_type", favorites.phone1_type);
    values.put("phone1_index", favorites.phone1_index);
    values.put("phone1_number", favorites.phone1_number);
    values.put("phone2_type", favorites.phone2_type);
    values.put("phone2_index", favorites.phone2_index);
    values.put("phone2_number", favorites.phone2_number);
    values.put("phone3_type", favorites.phone3_type);
    values.put("phone3_index", favorites.phone3_index);
    values.put("phone3_number", favorites.phone3_number);
    values.put("phone4_type", favorites.phone4_type);
    values.put("phone4_index", favorites.phone4_index);
    values.put("phone4_number", favorites.phone4_number);
    values.put("email1_type", favorites.email1_type);
    values.put("email1_addr", favorites.email1_addr);
    values.put("email2_type", favorites.email2_type);
    values.put("email2_addr", favorites.email2_addr);
    values.put("email3_type", favorites.email3_type);
    values.put("email3_addr", favorites.email3_addr);
    values.put("email4_type", favorites.email4_type);
    values.put("email4_addr", favorites.email4_addr);
    values.put("address1", favorites.address1);
    values.put("address2", favorites.address2);
    values.put("address3", favorites.address3);
    values.put("address4", favorites.address4);
    values.put("is_selected", favorites.is_selected);

    NCString select = "_id = ?";
    NCList<NCString> whereArgs;
    NCString* arg1 = VR_new NCString();
    arg1->format("%d", favorites._id);
    whereArgs << arg1;
    INT64 rowId = m_resolver->update(NCUri(VR_TABLE_OF_PHONE_FAVORITES_URL), values, select, whereArgs);
    if (0 == rowId) {
        VR_LOGD("Update Phone_Favorites data failed");
    }
    else {
        VR_LOGD("Update Phone_Favorites data succeed");
    }
    return rowId;
}

INT32 VR_NCPhoneInfoOperator::UpdatePhoneVoiceTagsData(const voiceTagsData& voiceTags)
{
    NCContentValues values;
    values.put("_id", voiceTags._id);
    values.put("contact_id", voiceTags.contact_id);
    values.put("voicetag_id", voiceTags.voicetag_id);
    values.put("firstname", voiceTags.firstname);
    values.put("lastname", voiceTags.lastname);
    values.put("phone1_number", voiceTags.phone1_number);
    values.put("phone2_number", voiceTags.phone2_number);
    values.put("phone3_number", voiceTags.phone3_number);
    values.put("phone4_number", voiceTags.phone4_number);
    values.put("is_selected", voiceTags.is_selected);


    NCString select = "_id = ?";
    NCList<NCString> whereArgs;
    NCString* arg1 = VR_new NCString();
    arg1->format("%d", voiceTags._id);
    whereArgs << arg1;
    INT64 rowId = m_resolver->update(NCUri(VR_TABLE_OF_PHONE_VOICE_TAGS_URL), values, select, whereArgs);
    if (0 == rowId) {
        VR_LOGD("Update Phone_Voicetags data failed");
    }
    else {
        VR_LOGD("Update Phone_Voicetags data succeed");
    }
    return rowId;
}

INT32 VR_NCPhoneInfoOperator::UpdatePhoneWidgetsData(const widgetsData& widgets)
{
    NCContentValues values;
    values.put("_id", widgets._id);
    values.put("contact_id", widgets.contact_id);
    values.put("sub_id", widgets.sub_id);
    values.put("firstname", widgets.firstname);
    values.put("lastname", widgets.lastname);
    values.put("phone_type", widgets.phone_type);
    values.put("phone_index", widgets.phone_index);
    values.put("phone_number", widgets.phone_number);
    values.put("phone_domesticnumber", widgets.phone_domesticnumber);

    NCString select = "_id = ?";
    NCList<NCString> whereArgs;
    NCString* arg1 = VR_new NCString();
    arg1->format("%d", widgets._id);
    whereArgs << arg1;
    INT64 rowId = m_resolver->update(NCUri(VR_TABLE_OF_PHONE_WIDGETS_URL), values, select, whereArgs);
    if (0 == rowId) {
        VR_LOGD("Update Phone_Widgets data failed");
    }
    else {
        VR_LOGD("Update Phone_Widgets data succeed");
    }
    return rowId;
}

// delete some table by URI
INT32 VR_NCPhoneInfoOperator::
DeletePhoneInfoData(const NCUri& uri, const NCString& where, const NCList<NCString>& whereArgs)
{
    VR_LOGD_FUNC();
    INT64 numChanges = m_resolver->remove(NCUri(uri), where, whereArgs);
    if (0 == numChanges) {
        VR_LOGD("no data is cleared");
    }
    return numChanges;
}

NCCursor* VR_NCPhoneInfoOperator::
QueryPhoneInfoData(const NCUri &uri, const NCList<NCString> &select, const NCString &where,
                        const NCList<NCString> &whereArgs, const NCString &sort)
{
    VR_LOGD_FUNC();
    NCCursor* cursor = m_resolver->query(NCUri(uri), select, where, whereArgs, sort);
    return cursor;
}

INT32 VR_NCPhoneInfoOperator::
updateSelectPhoneInfoData(const NCUri &uri, const NCContentValues &values,
                          const NCString &selection, const NCList<NCString> &selectionArgs)
{
    VR_LOGD_FUNC();
    INT64 rowId = m_resolver->update(NCUri(uri), values, selection, selectionArgs);
    if (0 == rowId) {
        VR_LOGD("Update [%s] data failed", uri.toString().getString());
    }
    else {
        VR_LOGD("Update [%s] data succeed", uri.toString().getString());
    }
    return rowId;
}


// Clear table
INT32 VR_NCPhoneInfoOperator::
ClearCallhistoryTableData()
{
    VR_LOGD_FUNC();
    INT64 numChanges = m_resolver->remove(NCUri(VR_TABLE_OF_PHONE_CALLHISTORY_URL), NCString(), NCList<NCString>());
    if (0 == numChanges) {
        VR_LOGD("no data is cleared");
    }
    return numChanges;
}

INT32 VR_NCPhoneInfoOperator::
ClearContactsTableData()
{
    VR_LOGD_FUNC();
    INT64 numChanges = m_resolver->remove(NCUri(VR_TABLE_OF_PHONE_CONTACTS_URL), NCString(), NCList<NCString>());
    if (0 == numChanges) {
        VR_LOGD("no data is cleared");
    }
    return numChanges;
}

INT32 VR_NCPhoneInfoOperator::
ClearFavoritesTableData()
{
    VR_LOGD_FUNC();
    INT64 numChanges = m_resolver->remove(NCUri(VR_TABLE_OF_PHONE_FAVORITES_URL), NCString(), NCList<NCString>());
    if (0 == numChanges) {
        VR_LOGD("no data is cleared");
    }
    return numChanges;
}

INT32 VR_NCPhoneInfoOperator::
ClearVoicetagsTableData()
{
    VR_LOGD_FUNC();
    INT64 numChanges = m_resolver->remove(NCUri(VR_TABLE_OF_PHONE_VOICE_TAGS_URL), NCString(), NCList<NCString>());
    if (0 == numChanges) {
        VR_LOGD("no data is cleared");
    }
    return numChanges;
}

INT32 VR_NCPhoneInfoOperator::
ClearWidgetsTableData()
{
    VR_LOGD_FUNC();
    INT64 numChanges = m_resolver->remove(NCUri(VR_TABLE_OF_PHONE_WIDGETS_URL), NCString(), NCList<NCString>());
    if (0 == numChanges) {
        VR_LOGD("no data is cleared");
    }
    return numChanges;
}




// Pugi XML analyzer

BOOL VR_NCPhoneInfoOperator::UpgradeDateBaseFromXMLFile(const NCString& phoneInfoXmlPath, const NCString& phoneInfoXmlName)
{
    NCString XmlFilePath = phoneInfoXmlPath + "/" + phoneInfoXmlName;

    BOOL result = FALSE;

    pugi::xml_document        diffDocument;
    pugi::xml_parse_result loadResult = diffDocument.load_file(XmlFilePath.getString());
    if (!loadResult) {
        VR_LOGD("Failed load file::[%s];error is [%s]", XmlFilePath.getString(), loadResult.description());
        result = FALSE;
    }
    else if (VR_PHONE_CALLHISTORY_XMLFILE == phoneInfoXmlName) {
        // clear all data
        DeletePhoneInfoData(NCUri(VR_TABLE_OF_PHONE_CALLHISTORY_URL), NCString(), NCList<NCString>());
        // update all data
        pugi::xml_node callhistory_root_node = diffDocument.child("root");
        pugi::xml_node callhistory_infos_node = callhistory_root_node.child("infos");
        for (pugi::xml_node person_node = callhistory_infos_node.child("person");
             person_node; person_node = person_node.next_sibling("person")) {

            callhistoryData callhistory = { atoi(person_node.child_value("_id")), atoi(person_node.child_value("contact_id")),
                                            person_node.child_value("firstname"), person_node.child_value("lastname"),
                                            atoi(person_node.child_value("phone_type")), atoi(person_node.child_value("phone_index")),
                                            person_node.child_value("phone_number"), person_node.child_value("phone_domesticnumber"),
                                            atoi(person_node.child_value("calltype")), person_node.child_value("calltime"),
                                            person_node.child_value("timezone"), atoi(person_node.child_value("count")),
                                            atoi(person_node.child_value("is_targettime")) };

            INT64 rowId = InsertPhoneCallhistoryData(callhistory);
            if (-1 == rowId) {
                VR_LOGD("Upgrade PHONE_CALLHISTORY data failed at _id is [%d]", person_node.child_value("_id"));
                result = FALSE;
            }
        }
        VR_LOGD("Upgrade PHONE_CALLHISTORY data succeed");
        result = TRUE;
    }
    else if (VR_PHONE_CONTACTS_XMLFILE == phoneInfoXmlName) {
        // clear all data
        DeletePhoneInfoData(NCUri(VR_TABLE_OF_PHONE_CONTACTS_URL), NCString(), NCList<NCString>());
        // update all data
        pugi::xml_node contacts_root_node = diffDocument.child("root");
        pugi::xml_node contacts_infos_node = contacts_root_node.child("infos");
        for (pugi::xml_node person_node = contacts_infos_node.child("person");
             person_node; person_node = person_node.next_sibling("person")) {

            contactsData contacts = { atoi(person_node.child_value("_id")), atoi(person_node.child_value("contact_id")),
                                      person_node.child_value("firstname"), person_node.child_value("lastname"),
                                      person_node.child_value("sort_fl"), person_node.child_value("sort_lf"),
                                      person_node.child_value("phone_number"), atoi(person_node.child_value("phone1_type")),
                                      atoi(person_node.child_value("phone1_index")), person_node.child_value("phone1_number"),
                                      person_node.child_value("phone1_domesticnumber"), atoi(person_node.child_value("phone1_widget")),
                                      atoi(person_node.child_value("phone2_type")), atoi(person_node.child_value("phone2_index")),
                                      person_node.child_value("phone2_number"), person_node.child_value("phone2_domesticnumber"),
                                      atoi(person_node.child_value("phone2_widget")), atoi(person_node.child_value("phone3_type")),
                                      atoi(person_node.child_value("phone3_index")), person_node.child_value("phone3_number"),
                                      person_node.child_value("phone3_domesticnumber"), atoi(person_node.child_value("phone3_widget")),
                                      atoi(person_node.child_value("phone4_type")), atoi(person_node.child_value("phone4_index")),
                                      person_node.child_value("phone4_number"), person_node.child_value("phone4_domesticnumber"),
                                      atoi(person_node.child_value("phone4_widget")), atoi(person_node.child_value("email1_type")),
                                      person_node.child_value("email1_addr"), atoi(person_node.child_value("email2_type")),
                                      person_node.child_value("email2_addr"), atoi(person_node.child_value("email3_type")),
                                      person_node.child_value("email3_addr"), atoi(person_node.child_value("email4_type")),
                                      person_node.child_value("email4_addr"), person_node.child_value("address1"),
                                      person_node.child_value("address2"), person_node.child_value("address3"),
                                      person_node.child_value("address4"), atoi(person_node.child_value("is_favor")),
                                      atoi(person_node.child_value("voicetag")), atoi(person_node.child_value("photo_status")),
                                      atoi(person_node.child_value("is_selected")) };

            INT64 rowId = InsertPhoneContactsData(contacts);
            if (-1 == rowId) {
                VR_LOGD("Upgrade PHONE_CONTACTS data failed at index is [%d]", person_node.child_value("_id"));
                result = FALSE;
            }
        }
        VR_LOGD("Upgrade PHONE_CONTACTS data succeed");
        result = TRUE;
    }
    else if (VR_PHONE_FAVORITES_XMLFILE == phoneInfoXmlName) {
        // clear all data
        DeletePhoneInfoData(NCUri(VR_TABLE_OF_PHONE_FAVORITES_URL), NCString(), NCList<NCString>());
        // update all data
        pugi::xml_node favorites_root_node = diffDocument.child("root");
        pugi::xml_node favorites_infos_node = favorites_root_node.child("infos");
        for (pugi::xml_node person_node = favorites_infos_node.child("person");
             person_node; person_node = person_node.next_sibling("person")) {

            favoritesData favorites = { atoi(person_node.child_value("_id")), atoi(person_node.child_value("contact_id")),
                                        person_node.child_value("firstname"), person_node.child_value("lastname"),
                                        person_node.child_value("sort_fl"), person_node.child_value("sort_lf"),
                                        person_node.child_value("phone_number"), atoi(person_node.child_value("phone1_type")),
                                        atoi(person_node.child_value("phone1_index")), person_node.child_value("phone1_number"),
                                        atoi(person_node.child_value("phone2_type")), atoi(person_node.child_value("phone2_index")),
                                        person_node.child_value("phone2_number"), atoi(person_node.child_value("phone3_type")),
                                        atoi(person_node.child_value("phone3_index")), person_node.child_value("phone3_number"),
                                        atoi(person_node.child_value("phone4_type")), atoi(person_node.child_value("phone4_index")),
                                        person_node.child_value("phone4_number"), atoi(person_node.child_value("email1_type")),
                                        person_node.child_value("email1_addr"), atoi(person_node.child_value("email2_type")),
                                        person_node.child_value("email2_addr"), atoi(person_node.child_value("email3_type")),
                                        person_node.child_value("email3_addr"), atoi(person_node.child_value("email4_type")),
                                        person_node.child_value("email4_addr"), person_node.child_value("address1"),
                                        person_node.child_value("address2"), person_node.child_value("address3"),
                                        person_node.child_value("address4"), atoi(person_node.child_value("is_selected")) };

            INT64 rowId = InsertPhoneFavoritesData(favorites);
            if (-1 == rowId) {
                VR_LOGD("Upgrade PHONE_FAVORITES data failed at index is [%d]", person_node.child_value("_id"));
                result = FALSE;
            }
        }
        VR_LOGD("Upgrade PHONE_FAVORITES data succeed");
        result = TRUE;
    }
    else if (VR_PHONE_VOICE_TAGS_XMLFILE == phoneInfoXmlName) {
        // clear all data
        DeletePhoneInfoData(NCUri(VR_TABLE_OF_PHONE_VOICE_TAGS_URL), NCString(), NCList<NCString>());
        // update all data
        pugi::xml_node voice_tags_root_node = diffDocument.child("root");
        pugi::xml_node voice_tags_infos_node = voice_tags_root_node.child("infos");
        for (pugi::xml_node person_node = voice_tags_infos_node.child("person");
             person_node; person_node = person_node.next_sibling("person")) {

            voiceTagsData voiceTags = { atoi(person_node.child_value("_id")), atoi(person_node.child_value("contact_id")),
                                        atoi(person_node.child_value("voicetag_id")), person_node.child_value("firstname"),
                                        person_node.child_value("lastname"), person_node.child_value("phone1_number"),
                                        person_node.child_value("phone2_number"), person_node.child_value("phone3_number"),
                                        person_node.child_value("phone4_number"), atoi(person_node.child_value("is_selected")) };

            INT64 rowId = InsertPhoneVoiceTagsData(voiceTags);
            if (-1 == rowId) {
                VR_LOGD("Upgrade PHONE_VOICE_TAGS_ data failed at index is [%d]", person_node.child_value("_id"));
                result = FALSE;
            }
        }
        VR_LOGD("Upgrade PHONE_VOICE_TAGS_ data succeed");
        result = TRUE;
    }
    else if (VR_PHONE_WIDGETS_XMLFILE == phoneInfoXmlName) {
        // clear all data
        DeletePhoneInfoData(NCUri(VR_TABLE_OF_PHONE_WIDGETS_URL), NCString(), NCList<NCString>());
        // update all data
        pugi::xml_node widgets_root_node = diffDocument.child("root");
        pugi::xml_node widgets_infos_node = widgets_root_node.child("infos");
        for (pugi::xml_node person_node = widgets_infos_node.child("person");
             person_node; person_node = person_node.next_sibling("person")) {

            widgetsData widgets = { atoi(person_node.child_value("_id")), atoi(person_node.child_value("contact_id")),
                                    atoi(person_node.child_value("sub_id")), person_node.child_value("firstname"),
                                    person_node.child_value("lastname"), atoi(person_node.child_value("phone_type")),
                                    atoi(person_node.child_value("phone_index")), person_node.child_value("phone_number"),
                                    person_node.child_value("phone_domesticnumber") };

            INT64 rowId = InsertPhoneWidgetsData(widgets);
            if (-1 == rowId) {
                VR_LOGD("Upgrade PHONE_WIDGETS data failed at index is [%d]", person_node.child_value("_id"));
                result = FALSE;
            }
        }
        VR_LOGD("Upgrade PHONE_WIDGETS data succeed");
        result = TRUE;
    }

    return result;
}
/* EOF */

