#define where is source file ,my-dir refers to current path
LOCAL_PATH := $(call my-dir)

#clean local vars
include $(CLEAR_VARS)

#refers this module is compiled in all versions
#define this module name is testPhoneInfo
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE := testPhoneInfo

#define this module will be compiled to executable file
include $(BUILD_NAVI_TARGET_EXCUTABLE)


