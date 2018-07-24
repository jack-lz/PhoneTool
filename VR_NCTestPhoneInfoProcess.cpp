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
#include <iostream>
#include <ncapp/NCApplicationProcess.h>
#include "VR_Log.h"
#include "VR_NCPhoneInfoProvider.h"
#include "VR_NCTestPhoneInfoProcess.h"
#include "contentresolver/NCContentResolver.h"
#include "VR_NCPhoneInfoOperator.h"

using namespace std;
using namespace nutshell;

#define  VR_PHONE_INFO_XMLFILE_PATH      "/udisk/phoneTool"
#define  VR_PHONE_CALLHISTORY_XMLFILE_NAME    "callhistory.xml"
#define  VR_PHONE_CONTACTS_XMLFILE_NAME       "contacts.xml"
#define  VR_PHONE_FAVORITES_XMLFILE_NAME      "favorites.xml"
#define  VR_PHONE_VOICE_TAGS_XMLFILE_NAME     "voicetags.xml"
#define  VR_PHONE_WIDGETS_XMLFILE_NAME        "widgets.xml"

callhistoryData GetCallhistoryFromEnter();
contactsData GetContactsFromEnter();

int main()
{
    VR_NCTestPhoneInfoProcess process;
    process.initialize();
    process.start();

    VR_NCPhoneInfoOperator PIOperator;
    while (1) {
        std::cout << "please enter your command(break/insert/loadxml/update/clean): " << std::endl;
        std::string strComand;
        std::cin >> strComand;
        if ("break" == strComand) {
            break;
        }
        else if ("insert" == strComand) {
            std::cout << "please enter tableName(callhistory/contacts):" << std::endl;
            std::string strtableName;
            std::cin >> strtableName;
            if ("callhistory" == strtableName) {

                callhistoryData callhistory = GetCallhistoryFromEnter();

                BOOL result = PIOperator.InsertPhoneCallhistoryData(callhistory);
                if (result) {
                    std::cout << "insert callhistory table succeed" << std::endl;
                }
                else {
                    std::cout << "insert callhistory table failed" << std::endl;
                }
            }
            else if ("contacts"  == strtableName) {

                contactsData contacts = GetContactsFromEnter();
                BOOL result = PIOperator.InsertPhoneContactsData(contacts);
                if (result) {
                    std::cout << "insert contacts table succeed" << std::endl;
                }
                else {
                    std::cout << "insert contacts table failed" << std::endl;
                }
            }
        }
        else if ("loadxml" == strComand) {
            std::cout << "please enter tableName(callhistory/contacts):" << std::endl;
            std::string strtableName;
            std::cin >> strtableName;
            if ("callhistory" == strtableName) {

                BOOL result = PIOperator.UpgradeDateBaseFromXMLFile(VR_PHONE_INFO_XMLFILE_PATH, VR_PHONE_CALLHISTORY_XMLFILE_NAME);
                if (result) {
                    std::cout << "update callhistory table from XML succeed" << std::endl;
                }
                else {
                    std::cout << "update callhistory table from XML failed" << std::endl;
                }
            }
            else if ("contacts" == strtableName) {

                BOOL result = PIOperator.UpgradeDateBaseFromXMLFile(VR_PHONE_INFO_XMLFILE_PATH, VR_PHONE_CONTACTS_XMLFILE_NAME);
                if (result) {
                    std::cout << "update contacts table from XML succeed" << std::endl;
                }
                else {
                    std::cout << "update contacts table from XML failed" << std::endl;
                }
            }
        }
        else if ("update" == strComand) {
            std::cout << "please enter tableName(callhistory/contacts):" << std::endl;
            std::string strtableName;
            std::cin >> strtableName;
            if ("callhistory" == strtableName) {
                callhistoryData callhistory = GetCallhistoryFromEnter();
                INT rowId = PIOperator.UpdatePhoneCallhistoryData(callhistory);
                if (0 == rowId) {
                    std::cout << "update callhistory table failed" << std::endl;
                }
                else {
                    std::cout << "update callhistory table succeed" << std::endl;
                }
            }
            else if ("contacts" == strtableName) {
                contactsData contacts = GetContactsFromEnter();
                INT rowId = PIOperator.UpdatePhoneContactsData(contacts);
                if (0 == rowId) {
                    std::cout << "update contacts table failed" << std::endl;
                }
                else {
                    std::cout << "update contacts table succeed" << std::endl;
                }
            }
        }
        else if ("clean" == strComand) {
            std::cout << "please enter tableName(callhistory/contacts):" << std::endl;
            std::string strtableName;
            std::cin >> strtableName;
            if ("callhistory" == strtableName) {
                INT numChanges = PIOperator.ClearCallhistoryTableData();
                std::cout << "There are" << numChanges << "rows data is cleared"<<std::endl;
            }
            else if ("contacts" == strtableName) {
                INT numChanges = PIOperator.ClearContactsTableData();
                std::cout << "There are" << numChanges << "rows data is cleared"<<std::endl;
            }
        }
    }

    process.stop();
    process.deinitialize();
    return 0;
}

NCString GetNCStringFromCin()
{
    string firstname;
    cin >> firstname;
    return(NCString(firstname.c_str()));
}

callhistoryData GetCallhistoryFromEnter()
{
    callhistoryData callhistory;

    cout << "please ender _id [int] :" << endl;
    cin >> callhistory._id;
    cout << "please ender contact_id [int] :" << endl;
    cin >> callhistory.contact_id;
    cout << "please ender firstname [TEXT] :" << endl;
    callhistory.firstname = GetNCStringFromCin();
    cout << "please ender lastname [TEXT] :" << endl;
    callhistory.lastname = GetNCStringFromCin();
    cout << "please ender phone_type [int] :" << endl;
    cin >> callhistory.phone_type;
    cout << "please ender phone_index [int] :" << endl;
    cin >> callhistory.phone_index;
    cout << "please ender phone_number [TEXT] :" << endl;
    callhistory.phone_number = GetNCStringFromCin();
    cout << "please ender phone_domesticnumber [TEXT] :" << endl;
    callhistory.phone_domesticnumber = GetNCStringFromCin();
    cout << "please ender calltype [int] :" << endl;
    cin >> callhistory.calltype;
    cout << "please ender calltime [TEXT] :" << endl;
    callhistory.calltime = GetNCStringFromCin();
    cout << "please ender timezone [TEXT] :" << endl;
    callhistory.timezone = GetNCStringFromCin();
    cout << "please ender count [int] :" << endl;
    cin >> callhistory.count;
    cout << "please ender is_targettime [int] :" << endl;
    cin >> callhistory.is_targettime;

    return callhistory;
}

contactsData GetContactsFromEnter()
{
    contactsData contacts;
    cout << "please ender _id [int] :" << endl;
    cin >> contacts._id;
    cout << "please ender contact_id [int] :" << endl;
    cin >> contacts.contact_id;
    cout << "please ender firstname [TEXT] :" << endl;
    contacts.firstname = GetNCStringFromCin();
    cout << "please ender lastname [TEXT] :" << endl;
    contacts.lastname = GetNCStringFromCin();
    cout << "please ender sort_fl [TEXT] :" << endl;
    contacts.sort_fl = GetNCStringFromCin();
    cout << "please ender sort_lf [TEXT] :" << endl;
    contacts.sort_lf = GetNCStringFromCin();
    cout << "please ender phone_number [TEXT] :" << endl;
    contacts.phone_number = GetNCStringFromCin();
    cout << "please ender phone1_type [int] :" << endl;
    cin >> contacts.phone1_type;
    cout << "please ender phone1_index [int] :" << endl;
    cin >> contacts.phone1_index;
    cout << "please ender phone1_number [TEXT] :" << endl;
    contacts.phone1_number = GetNCStringFromCin();
    cout << "please ender phone1_domesticnumber [TEXT] :" << endl;
    contacts.phone1_domesticnumber = GetNCStringFromCin();
    cout << "please ender phone1_widget [int] :" << endl;
    cin >> contacts.phone1_widget;
    cout << "please ender phone2_type [int] :" << endl;
    cin >> contacts.phone2_type;
    cout << "please ender phone2_index [int] :" << endl;
    cin >> contacts.phone2_index;
    cout << "please ender phone2_number [TEXT] :" << endl;
    contacts.phone2_number = GetNCStringFromCin();
    cout << "please ender phone2_domesticnumber [TEXT] :" << endl;
    contacts.phone2_domesticnumber = GetNCStringFromCin();
    cout << "please ender phone2_widget [int] :" << endl;
    cin >> contacts.phone2_widget;
    cout << "please ender phone3_type [int] :" << endl;
    cin >> contacts.phone3_type;
    cout << "please ender phone3_index [int] :" << endl;
    cin >> contacts.phone3_index;
    cout << "please ender phone3_number [TEXT] :" << endl;
    contacts.phone3_number = GetNCStringFromCin();
    cout << "please ender phone3_domesticnumber [TEXT] :" << endl;
    contacts.phone3_domesticnumber = GetNCStringFromCin();
    cout << "please ender phone3_widget [int] :" << endl;
    cin >> contacts.phone3_widget;
    cout << "please ender phone4_type [int] :" << endl;
    cin >> contacts.phone4_type;
    cout << "please ender phone4_index [int] :" << endl;
    cin >> contacts.phone4_index;
    cout << "please ender phone4_number [TEXT] :" << endl;
    contacts.phone4_number = GetNCStringFromCin();
    cout << "please ender phone4_domesticnumber [TEXT] :" << endl;
    contacts.phone4_domesticnumber = GetNCStringFromCin();
    cout << "please ender phone4_widget [int] :" << endl;
    cin >> contacts.phone4_widget;
    cout << "please ender email1_type [int] :" << endl;
    cin >> contacts.email1_type;
    cout << "please ender email1_addr [TEXT] :" << endl;
    contacts.email1_addr = GetNCStringFromCin();
    cout << "please ender email2_type [int] :" << endl;
    cin >> contacts.email2_type;
    cout << "please ender email2_addr [TEXT] :" << endl;
    contacts.email2_addr = GetNCStringFromCin();
    cout << "please ender email3_type [int] :" << endl;
    cin >> contacts.email3_type;
    cout << "please ender email3_addr [TEXT] :" << endl;
    contacts.email3_addr = GetNCStringFromCin();
    cout << "please ender email4_type [int] :" << endl;
    cin >> contacts.email4_type;
    cout << "please ender email4_addr [TEXT] :" << endl;
    contacts.email4_addr = GetNCStringFromCin();
    cout << "please ender address1 [TEXT] :" << endl;
    contacts.address1 = GetNCStringFromCin();
    cout << "please ender address2 [TEXT] :" << endl;
    contacts.address2 = GetNCStringFromCin();
    cout << "please ender address3 [TEXT] :" << endl;
    contacts.address3 = GetNCStringFromCin();
    cout << "please ender address4 [TEXT] :" << endl;
    contacts.address4 = GetNCStringFromCin();
    cout << "please ender is_favor [int] :" << endl;
    cin >> contacts.is_favor;
    cout << "please ender voicetag [int] :" << endl;
    cin >> contacts.voicetag;
    cout << "please ender photo_status [int] :" << endl;
    cin >> contacts.photo_status;
    cout << "please ender is_selected [int] :" << endl;
    cin >> contacts.is_selected;

    return contacts;
}

/* EOF */

