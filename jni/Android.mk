LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := rave
LOCAL_SRC_FILES := init.c
LOCAL_SRC_FILES += process.c
LOCAL_SRC_FILES += gpu_cm.c

include $(BUILD_SHARED_LIBRARY)
