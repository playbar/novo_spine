#include <stdlib.h>
#include <jni.h>
#include <android/log.h>
#include <string>
#include "platform/android/jni/JniHelper.h"
#include "platform/android/CCFileUtils-android.h"
#include "android/asset_manager_jni.h"
#include "deprecated/CCString.h"
#include "LayerManager.h"
#include "base/ccUTF8.h"
#include "globaldef.h"

#include "Java_org_cocos2dx_lib_LayerManager.h"
#define  LOG_TAG    "Java_org_cocos2dx_lib_LayerManager.cpp"

#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

using namespace cocos2d;
using namespace std;


extern "C" {

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxLayerManager_nativeAddLayer(JNIEnv*  env, jobject thiz,
    		jstring jstrName, jint type) {
        string strName = JniHelper::jstring2string(jstrName);
        LayerManager::getInstance()->addLayer( strName, (LayerManager::EnLayerType)type );
        return;
    }

    JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxLayerManager_nativeDelLayer(JNIEnv*  env, jobject thiz, jstring jstrName) {
    		string strName = JniHelper::jstring2string(jstrName);
    		LayerManager::getInstance()->delLayer( strName );
    		return;
    }

    void GFunSkeletonEnd(std::string strName){
			JniMethodInfo t;
			int ret = -1;
			if(JniHelper::getStaticMethodInfo(t, LAYERMANAGER_CLASSNAME,"skeletonEnd", "(Ljava/lang/String;)V"))
			{
				JniHelper::callStaticVoidMethod(LAYERMANAGER_CLASSNAME, "skeletonEnd", strName);
				//ret = t.env->CallStaticIntMethod(t.classID, t.methodID, JniHelper::convert(t, strName));
				t.env->DeleteLocalRef(t.classID);
			}
			return;
    }

}


