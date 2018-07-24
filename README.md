PHONE TOOLS
================================================================================

Introduction
--------------------------------------------------------------------------------
        Establish an independent database based on contentProvider. reading XML
        file to update the corresponding table in database, then notify the 
        change of database to the phone related function and trigger different 
        case, analog phone access situation.

Instruction
--------------------------------------------------------------------------------
        before using this tool, you need to modify or add the following files in
        17Cy project.
### VoiceRecogService.cpp            modify

        #include "VR_NCPhoneInfoProvider.h"

        VOID VoiceRecogService::onInit()
        {
            // extend the idl stub
            VS_LOG("VoiceRecogService onInit");
            m_spVRStubImpl.force_set(new VoiceRecogStubImpl(this));
            registerInterface(m_spVRStubImpl);

            // register TutorialProvider
            registerProvider(new VR_NCTutorialInfoProvider(name()));
            // register PhoneProvider
            registerProvider(new VR_NCPhoneInfoProvider(name()));        
        }
        
### vr_stub-navi.cm            add

        "${USER_CONF_NAVILIB_SRC_DIR}/voice/voice/voicerecog/voicerecoglib/dialogmanger/testphoneinfo"
        
        "${USER_CONF_NAVILIB_SRC_DIR}/voice/voice/voicerecog/voicerecoglib/dialogmanger/testphoneinfo/VR_NCPhoneInfoDatabaseHelper.cpp"
        "${USER_CONF_NAVILIB_SRC_DIR}/voice/voice/voicerecog/voicerecoglib/dialogmanger/testphoneinfo/VR_NCPhoneInfoProvider.cpp"
        
### vr_dialog-navi.cm            add

        include(${USER_CONF_NAVILIB_SRC_DIR}/voice/voice/voicerecog/voicerecoglib/dialogmanger/testphoneinfo/TestPhoneInfo.cm)
        
        "${USER_CONF_NAVILIB_SRC_DIR}/voice/voice/voicerecog/voicerecoglib/dialogmanger/testphoneinfo/VR_NCPhoneInfoDatabaseHelper.cpp"
        "${USER_CONF_NAVILIB_SRC_DIR}/voice/voice/voicerecog/voicerecoglib/dialogmanger/testphoneinfo/VR_NCPhoneInfoProvider.cpp"
        
        
### VR_DataProviderComm.h            modify

        modify    #define VR_PHONE_BOOK_CONTACT_DATA_URI               "content://contacts/data?all"    
          to      #define VR_PHONE_BOOK_CONTACT_DATA_URI               "content://phoneinfo/phone_contacts/data?Notify"
       
        modify    #define VR_PHONE_BOOK_CALL_HISTORY_URI               "content://callhistory/data?all"
          to      #define VR_PHONE_BOOK_CALL_HISTORY_URI               "content://phoneinfo/phone_callhistory/data?Notify"
          
### VR_PhoneBookXMLFormat.cpp            modify 

        modify    const nutshell::NCString VR_PB_CONTACT_DATA_INFO_URI          = "content://contacts/fulldata";
          to      const nutshell::NCString VR_PB_CONTACT_DATA_INFO_URI          = "content://phoneinfo/phone_contacts/data";
          
        modify    const nutshell::NCString VR_PB_CALL_HISTORY_INFO_URI          = "content://callhistory/data";
          to      const nutshell::NCString VR_PB_CALL_HISTORY_INFO_URI          = "content://phoneinfo/phone_callhistory/data";        


### After these operation

        place this project source file at /voice/voice/voicerecog/voicerecoglib/dialogmanger/testphoneinfo/ ;
        compile libvoicerecog-navi and testPhoneInfo ;
        

### finish dates
        2016/12/15









        
        

