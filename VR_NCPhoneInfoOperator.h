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

/**
 * @file VR_NCPhoneInfoOperator.h
 * @brief Declaration file of class VR_NCPhoneInfoOperator.
 *
 * This file includes the declaration of class VR_NCPhoneInfoOperator.
 *
 * @attention used for C++ only.
 */

#ifndef VR_NCPHONEINFOOPERATOR_H
#define VR_NCPHONEINFOOPERATOR_H

#ifndef __cplusplus
#    error ERROR: This file requires C++ compilation (use a .cpp suffix)
#endif

#include "contentresolver/NCContentResolver.h"
#include "pugixml.hpp"
#include "pugiconfig.hpp"

#ifndef VR_DEF_H
#   include "VR_Def.h"
#endif


#define VR_TABLE_OF_PHONE_CALLHISTORY_URL     "content://phoneinfo/phone_callhistory/data"
#define VR_TABLE_OF_PHONE_CONTACTS_URL        "content://phoneinfo/phone_contacts/data"
#define VR_TABLE_OF_PHONE_FAVORITES_URL       "content://phoneinfo/phone_favorites/data"
#define VR_TABLE_OF_PHONE_VOICE_TAGS_URL      "content://phoneinfo/phone_voice_tags/data"
#define VR_TABLE_OF_PHONE_WIDGETS_URL         "content://phoneinfo/phone_widgets/data"

#define  VR_PHONE_CALLHISTORY_XMLFILE    "callhistory.xml"
#define  VR_PHONE_CONTACTS_XMLFILE       "contacts.xml"
#define  VR_PHONE_FAVORITES_XMLFILE      "favorites.xml"
#define  VR_PHONE_VOICE_TAGS_XMLFILE     "voicetags.xml"
#define  VR_PHONE_WIDGETS_XMLFILE        "widgets.xml"



typedef struct Callhistory
{
    nutshell::INT       _id;
    nutshell::INT       contact_id;
    nutshell::NCString  firstname;
    nutshell::NCString  lastname;
    nutshell::INT       phone_type;
    nutshell::INT       phone_index;
    nutshell::NCString  phone_number;
    nutshell::NCString  phone_domesticnumber;
    nutshell::INT       calltype;
    nutshell::NCString  calltime;
    nutshell::NCString  timezone;
    nutshell::INT       count;
    nutshell::INT       is_targettime;
}callhistoryData;

typedef struct Contacts
{
    nutshell::INT      _id;
    nutshell::INT      contact_id;
    nutshell::NCString firstname;
    nutshell::NCString lastname;
    nutshell::NCString sort_fl;
    nutshell::NCString sort_lf;
    nutshell::NCString phone_number;
    nutshell::INT      phone1_type;
    nutshell::INT      phone1_index;
    nutshell::NCString phone1_number;
    nutshell::NCString phone1_domesticnumber;
    nutshell::INT      phone1_widget;
    nutshell::INT      phone2_type;
    nutshell::INT      phone2_index;
    nutshell::NCString phone2_number;
    nutshell::NCString phone2_domesticnumber;
    nutshell::INT      phone2_widget;
    nutshell::INT      phone3_type;
    nutshell::INT      phone3_index;
    nutshell::NCString phone3_number;
    nutshell::NCString phone3_domesticnumber;
    nutshell::INT      phone3_widget;
    nutshell::INT      phone4_type;
    nutshell::INT      phone4_index;
    nutshell::NCString phone4_number;
    nutshell::NCString phone4_domesticnumber;
    nutshell::INT      phone4_widget;
    nutshell::INT      email1_type;
    nutshell::NCString email1_addr;
    nutshell::INT      email2_type;
    nutshell::NCString email2_addr;
    nutshell::INT      email3_type;
    nutshell::NCString email3_addr;
    nutshell::INT      email4_type;
    nutshell::NCString email4_addr;
    nutshell::NCString address1;
    nutshell::NCString address2;
    nutshell::NCString address3;
    nutshell::NCString address4;
    nutshell::INT      is_favor;
    nutshell::INT      voicetag;
    nutshell::INT      photo_status;
    nutshell::INT      is_selected;
}contactsData;

typedef struct Favorites
{
    nutshell::INT      _id;
    nutshell::INT      contact_id;
    nutshell::NCString firstname;
    nutshell::NCString lastname;
    nutshell::NCString sort_fl;
    nutshell::NCString sort_lf;
    nutshell::NCString phone_number;
    nutshell::INT      phone1_type;
    nutshell::INT      phone1_index;
    nutshell::NCString phone1_number;
    nutshell::INT      phone2_type;
    nutshell::INT      phone2_index;
    nutshell::NCString phone2_number;
    nutshell::INT      phone3_type;
    nutshell::INT      phone3_index;
    nutshell::NCString phone3_number;
    nutshell::INT      phone4_type;
    nutshell::INT      phone4_index;
    nutshell::NCString phone4_number;
    nutshell::INT      email1_type;
    nutshell::NCString email1_addr;
    nutshell::INT      email2_type;
    nutshell::NCString email2_addr;
    nutshell::INT      email3_type;
    nutshell::NCString email3_addr;
    nutshell::INT      email4_type;
    nutshell::NCString email4_addr;
    nutshell::NCString address1;
    nutshell::NCString address2;
    nutshell::NCString address3;
    nutshell::NCString address4;
    nutshell::INT      is_selected;
}favoritesData;

typedef struct VoiceTags
{
    nutshell::INT      _id;
    nutshell::INT      contact_id;
    nutshell::INT      voicetag_id;
    nutshell::NCString firstname;
    nutshell::NCString lastname;
    nutshell::NCString phone1_number;
    nutshell::NCString phone2_number;
    nutshell::NCString phone3_number;
    nutshell::NCString phone4_number;
    nutshell::INT      is_selected;
}voiceTagsData;

typedef struct Widgets
{
    nutshell::INT      _id;
    nutshell::INT      contact_id;
    nutshell::INT      sub_id;
    nutshell::NCString firstname;
    nutshell::NCString lastname;
    nutshell::INT      phone_type;
    nutshell::INT      phone_index;
    nutshell::NCString phone_number;
    nutshell::NCString phone_domesticnumber;

}widgetsData;


/**
 * @brief The VR_NCPhoneInfoOperator class
 *
 * class declaration.
 */
class VR_NCPhoneInfoOperator
{
public:
    VR_NCPhoneInfoOperator();
    ~VR_NCPhoneInfoOperator();


    // insert
    nutshell::BOOL InsertPhoneCallhistoryData(const callhistoryData& callhistory);
    nutshell::BOOL InsertPhoneContactsData(const contactsData& contacts);
    nutshell::BOOL InsertPhoneFavoritesData(const favoritesData& favorites);
    nutshell::BOOL InsertPhoneVoiceTagsData(const voiceTagsData& voiceTags);
    nutshell::BOOL InsertPhoneWidgetsData(const widgetsData& widgets);

    // update
    nutshell::INT32 UpdatePhoneCallhistoryData(const callhistoryData& callhistory);
    nutshell::INT32 UpdatePhoneContactsData(const contactsData& contacts);
    nutshell::INT32 UpdatePhoneFavoritesData(const favoritesData& favorites);
    nutshell::INT32 UpdatePhoneVoiceTagsData(const voiceTagsData& voiceTags);
    nutshell::INT32 UpdatePhoneWidgetsData(const widgetsData& widgets);

    nutshell::INT32 updateSelectPhoneInfoData(const nutshell::NCUri &uri, const nutshell::NCContentValues &values,
                              const nutshell::NCString &selection, const nutshell::NCList<nutshell::NCString> &selectionArgs);

    // delete
    nutshell::INT32 DeletePhoneInfoData(const nutshell::NCUri& uri, const nutshell::NCString& where, const nutshell::NCList<nutshell::NCString>& whereArgs);

    // query
    nutshell::NCCursor* QueryPhoneInfoData(const nutshell::NCUri &uri, const nutshell::NCList<nutshell::NCString> &select, const nutshell::NCString &where,
                            const nutshell::NCList<nutshell::NCString> &whereArgs, const nutshell::NCString &sort);




    // Upgrade all date
    nutshell::BOOL UpgradeDateBaseFromXMLFile(const nutshell::NCString& phoneInfoXmlPath, const nutshell::NCString& phoneInfoXmlName);


    // Clear table
    nutshell::INT32 ClearCallhistoryTableData();
    nutshell::INT32 ClearContactsTableData();
    nutshell::INT32 ClearFavoritesTableData();
    nutshell::INT32 ClearVoicetagsTableData();
    nutshell::INT32 ClearWidgetsTableData();


private:
    nutshell::NCContentResolver*        m_resolver;
};

#endif // VR_NCPHONEINFOOPERATOR_H
/* EOF */
