LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := libnv liboncrpc
LOCAL_SHARED_LIBRARIES  += libcutils

LOCAL_SRC_FILES:= readmac.c
LOCAL_MODULE:= libreadmac
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)

