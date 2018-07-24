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
 * @file VR_NCPhoneInfoProvider.h
 * @brief Declaration file of class VR_NCPhoneInfoProvider.
 *
 * This file includes the declaration of class VR_NCPhoneInfoProvider.
 *
 * @attention used for C++ only.
 */

#ifndef VR_NCPHONEINFOPROVIDER_H
#define VR_NCPHONEINFOPROVIDER_H

#ifndef __cplusplus
#    error ERROR: This file requires C++ compilation (use a .cpp suffix)
#endif

#include "contentprovider/NCContentProvider.h"
#include "VR_NCPhoneInfoDatabaseHelper.h"
#include "ncore/NCUriMatcher.h"


#ifndef VR_DEF_H
#   include "VR_Def.h"
#endif


/**
 * @brief The VR_NCPhoneInfoProvider class
 *
 * class declaration.
 */
class VR_NCPhoneInfoProvider : public nutshell::NCContentProvider
{
public:
    VR_NCPhoneInfoProvider(const nutshell::NCString& serviceName);
    virtual ~VR_NCPhoneInfoProvider();

    virtual nutshell::NCCursor* query(
        const nutshell::NCUri& uri,
        const nutshell::NCList<nutshell::NCString>& select,
        const nutshell::NCString& where,
        const nutshell::NCList<nutshell::NCString>& whereArgs,
        const nutshell::NCString& sort);

    virtual nutshell::INT64 insert(
        const nutshell::NCUri& uri,
        const nutshell::NCContentValues& values);

    virtual nutshell::INT32 update(
        const nutshell::NCUri& uri,
        const nutshell::NCContentValues& values,
        const nutshell::NCString& where,
        const nutshell::NCList<nutshell::NCString>& whereArgs);

    virtual nutshell::INT32 remove(
        const nutshell::NCUri& uri,
        const nutshell::NCString& where,
        const nutshell::NCList<nutshell::NCString>& whereArgs);

    virtual nutshell::NCString getType(const nutshell::NCUri& uri);

protected:
    virtual VOID onInitialize();
    virtual VOID onStart();
    virtual VOID onStop();
    virtual VOID onDeinitialize();

private:
    VR_NCPhoneInfoProvider(const VR_NCPhoneInfoProvider&);
    VR_NCPhoneInfoProvider& operator=(const VR_NCPhoneInfoProvider&);

    VR_NCPhoneInfoDatabaseHelper* m_dbHelper;
    nutshell::NCUriMatcher m_uriMatcher;

    typedef VoiceMap<nutshell::INT, nutshell::NCString>::type UriMatchRelateMap;
    static UriMatchRelateMap m_MatchRelate;
};


#endif // VR_NCPHONEINFOPROVIDER_H
/* EOF */
