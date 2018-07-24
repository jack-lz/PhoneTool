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
 * @file VR_NCPhoneInfoDatabaseHelper.h
 * @brief Declaration file of class VR_NCPhoneInfoDatabaseHelper.
 *
 * This file includes the declaration of class VR_NCPhoneInfoDatabaseHelper.
 *
 * @attention used for C++ only.
 */

#ifndef VR_NCPHONEINFODATABASEHELPER_H
#define VR_NCPHONEINFODATABASEHELPER_H

#ifndef __cplusplus
#   error ERROR: This file requires C++ compilation (use a .cpp suffix)
#endif

#include "dbhelper/NCSQLiteOpenHelper.h"


#define VR_TABLE_OF_PHONE_CALLHISTORY     "phone_callhistory"
#define VR_TABLE_OF_PHONE_CONTACTS        "phone_contacts"
#define VR_TABLE_OF_PHONE_FAVORITES       "phone_favorites"
#define VR_TABLE_OF_PHONE_VOICE_TAGS      "phone_voice_tags"
#define VR_TABLE_OF_PHONE_WIDGETS         "phone_widgets"

// phone_callhistory
#define VR_PHONE_CREATE_TABLE_OF_CALLHISTORY_SQL \
    "CREATE TABLE IF NOT EXISTS "VR_TABLE_OF_PHONE_CALLHISTORY" (" \
    "_id                  INTEGER PRIMARY KEY AUTOINCREMENT," \
    "contact_id           INTEGER,"  \
    "firstname            TEXT," \
    "lastname             TEXT," \
    "phone_type           INTEGER,"  \
    "phone_index          INTEGER,"  \
    "phone_number         TEXT," \
    "phone_domesticnumber TEXT," \
    "calltype             INTEGER,"  \
    "calltime             TEXT," \
    "timezone             TEXT," \
    "count                INTEGER,"  \
    "is_targettime        INTEGER"   \
    ");"

// phone_contacts
#define VR_PHONE_CREATE_TABLE_OF_CONTACTS_SQL \
    "CREATE TABLE IF NOT EXISTS "VR_TABLE_OF_PHONE_CONTACTS" (" \
    "_id                   INTEGER PRIMARY KEY AUTOINCREMENT," \
    "contact_id            INTEGER,"   \
    "firstname             TEXT," \
    "lastname              TEXT," \
    "sort_fl               TEXT,"  \
    "sort_lf               TEXT,"  \
    "phone_number          TEXT,"  \
    "phone1_type           INTEGER,"   \
    "phone1_index          INTEGER,"   \
    "phone1_number         TEXT,"  \
    "phone1_domesticnumber TEXT,"  \
    "phone1_widget         INTEGER,"   \
    "phone2_type           INTEGER,"   \
    "phone2_index          INTEGER,"   \
    "phone2_number         TEXT,"  \
    "phone2_domesticnumber TEXT," \
    "phone2_widget         INTEGER,"   \
    "phone3_type           INTEGER,"   \
    "phone3_index          INTEGER,"   \
    "phone3_number         TEXT,"  \
    "phone3_domesticnumber TEXT,"  \
    "phone3_widget         INTEGER,"   \
    "phone4_type           INTEGER,"   \
    "phone4_index          INTEGER,"   \
    "phone4_number         TEXT,"  \
    "phone4_domesticnumber TEXT,"  \
    "phone4_widget         INTEGER,"   \
    "email1_type           INTEGER,"   \
    "email1_addr           TEXT,"  \
    "email2_type           INTEGER,"   \
    "email2_addr           TEXT,"  \
    "email3_type           INTEGER,"   \
    "email3_addr           TEXT,"  \
    "email4_type           INTEGER,"   \
    "email4_addr           TEXT,"  \
    "address1              TEXT,"  \
    "address2              TEXT,"  \
    "address3              TEXT,"  \
    "address4              TEXT,"  \
    "is_favor              INTEGER,"   \
    "voicetag              INTEGER,"   \
    "photo_status          INTEGER,"   \
    "is_selected           INTEGER"   \
    ");"

// phone_favorites
#define VR_PHONE_CREATE_TABLE_OF_FAVORITES_SQL \
    "CREATE TABLE IF NOT EXISTS "VR_TABLE_OF_PHONE_FAVORITES" (" \
    "_id    INTEGER PRIMARY KEY AUTOINCREMENT," \
    "contact_id            INTEGER,"   \
    "firstname             TEXT," \
    "lastname              TEXT," \
    "sort_fl               TEXT,"  \
    "sort_lf               TEXT,"  \
    "phone_number          TEXT,"  \
    "phone1_type           INTEGER,"   \
    "phone1_index          INTEGER,"   \
    "phone1_number         TEXT,"  \
    "phone2_type           INTEGER,"   \
    "phone2_index          INTEGER,"   \
    "phone2_number         TEXT,"  \
    "phone3_type           INTEGER,"   \
    "phone3_index          INTEGER,"   \
    "phone3_number         TEXT,"  \
    "phone4_type           INTEGER,"   \
    "phone4_index          INTEGER,"   \
    "phone4_number         TEXT,"  \
    "email1_type           INTEGER,"   \
    "email1_addr           TEXT,"  \
    "email2_type           INTEGER,"   \
    "email2_addr           TEXT,"  \
    "email3_type           INTEGER,"   \
    "email3_addr           TEXT,"  \
    "email4_type           INTEGER,"   \
    "email4_addr           TEXT,"  \
    "address1              TEXT,"  \
    "address2              TEXT,"  \
    "address3              TEXT,"  \
    "address4              TEXT,"  \
    "is_selected           INTEGER"   \
    ");"

// phone_voice_tags
#define VR_PHONE_CREATE_TABLE_OF_VOICE_TAGS_SQL \
    "CREATE TABLE IF NOT EXISTS "VR_TABLE_OF_PHONE_VOICE_TAGS" (" \
    "_id      INTEGER PRIMARY KEY AUTOINCREMENT," \
    "contact_id            INTEGER,"   \
    "voicetag_id           INTEGER,"   \
    "firstname             TEXT," \
    "lastname              TEXT," \
    "phone1_number         TEXT,"  \
    "phone2_number         TEXT,"  \
    "phone3_number         TEXT,"  \
    "phone4_number         TEXT,"  \
    "is_selected           INTEGER"   \
    ");"

// phone_widgets
#define VR_PHONE_CREATE_TABLE_OF_WIDGETS_SQL \
    "CREATE TABLE IF NOT EXISTS "VR_TABLE_OF_PHONE_WIDGETS" (" \
    "_id         INTEGER PRIMARY KEY AUTOINCREMENT," \
    "contact_id            INTEGER,"   \
    "sub_id                INTEGER,"   \
    "firstname             TEXT," \
    "lastname              TEXT," \
    "phone_type            INTEGER,"   \
    "phone_index           INTEGER,"   \
    "phone_number          TEXT,"  \
    "phone_domesticnumber  TEXT"  \
    ");"

/**
 * @brief The VR_NCPhoneInfoDatabaseHelper class
 *
 * class declaration.
 */

class VR_NCPhoneInfoDatabaseHelper : public nutshell::NCSQLiteOpenHelper
{
public:
    VR_NCPhoneInfoDatabaseHelper(const nutshell::NCString& name, nutshell::INT version);
    virtual ~VR_NCPhoneInfoDatabaseHelper();
    virtual VOID onCreate(nutshell::NCSQLiteDatabase* db);
    virtual VOID onUpgrade(nutshell::NCSQLiteDatabase* db, nutshell::INT oldVersion, nutshell::INT newVersion);
    virtual VOID onDowngrade(nutshell::NCSQLiteDatabase* db, nutshell::INT oldVersion, nutshell::INT newVersion);
    virtual VOID onOpen(nutshell::NCSQLiteDatabase* db);

private:
    VR_NCPhoneInfoDatabaseHelper(const VR_NCPhoneInfoDatabaseHelper&);
    VR_NCPhoneInfoDatabaseHelper& operator=(const VR_NCPhoneInfoDatabaseHelper&);
    void createTable(nutshell::NCSQLiteDatabase* db);

private:
    nutshell::INT m_PhoneProviderVersion;
    static const nutshell::NCCHAR* g_createSQLTemplate[];
};


#endif // VR_NCPHONEINFODATABASEHELPER_H
/* EOF */
