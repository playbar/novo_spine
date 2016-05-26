#include <stdlib.h>
#include <jni.h>
#include <android/log.h>
#include <string>
#include "platform/android/jni/JniHelper.h"
#include "platform/android/CCFileUtils-android.h"
#include "android/asset_manager_jni.h"
#include "deprecated/CCString.h"
#include "platform/android/jni/Java_org_cocos2dx_lib_ManagerLayer.h"
#include "base/ccUTF8.h"
#define  LOG_TAG    "Java_org_cocos2dx_lib_ManagerLayer.cpp"

#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

using namespace cocos2d;
using namespace std;


extern "C" {

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxLayer_nativeAddLayer(JNIEnv*  env, jobject thiz, jstring jstrName) {
        string strName = JniHelper::jstring2string(jstrName);
    }

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxLayer_nativeDelLayer(JNIEnv*  env, jobject thiz, jstring jstrName) {
    		string strName = JniHelper::jstring2string(jstrName);
    }


}


