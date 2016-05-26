LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos/audio/include)

LOCAL_MODULE := novo

LOCAL_MODULE_FILENAME := libnovo

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/NovoScene.cpp \
                   ../../Classes/ParticleLayer.cpp \
                   ../../Classes/SkeletonLayer.cpp \
                   ../../Classes/Sprite3DLayer.cpp \
                   ../../Classes/VisibleRect.cpp \
                   ../../Classes/PlayInfo.cpp \
                   ../../Classes/LayerManager.cpp \
                   ../../Classes/Java_org_cocos2dx_lib_ManagerLayer.cpp \
				   

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := novo2d_static
LOCAL_LDFLAGS += -ljnigraphics

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
