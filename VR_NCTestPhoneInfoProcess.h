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
 * @file VR_NCTestPhoneInfoProcess.h
 * @brief Declaration file of class VR_NCTestPhoneInfoProcess.
 *
 * This file includes the declaration of class VR_NCTestPhoneInfoProcess.
 *
 * @attention used for C++ only.
 */

#ifndef VR_NCTESTPHONEINFOPROCESS_H
#define VR_NCTESTPHONEINFOPROCESS_H

#ifndef __cplusplus
#    error ERROR: This file requires C++ compilation (use a .cpp suffix)
#endif

#include <ncapp/NCApplicationProcess.h>



/**
 * @brief The VR_NCTestPhoneInfoProcess class
 *
 * class declaration.
 */
class VR_NCTestPhoneInfoProcess : public nutshell::NCApplicationProcess
{
public:
    VR_NCTestPhoneInfoProcess() : NCApplicationProcess("vr_nctestphoneinfprocess")
    {
    }

    virtual ~VR_NCTestPhoneInfoProcess() {}
    // VOID OnInitialize() {}
    // VOID OnStart() {}
    // VOID OnStop() {}
    // VOID OnDeinitialize() {}
};

#endif // VR_NCTESTPHONEINFOPROCESS_H
/* EOF */
