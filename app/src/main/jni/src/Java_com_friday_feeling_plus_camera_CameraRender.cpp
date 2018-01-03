#include <jni.h>
#include <android/native_window_jni.h>
#include "JniHelper.h"
#include "CameraManager.h"
#ifndef _Included_com_friday_feeling_plus_camera_CameraRender
#define _Included_com_friday_feeling_plus_camera_CameraRender
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_com_friday_feeling_plus_camera_CameraRender_nativeOnCreate(JNIEnv *env, jobject thiz)
{
    if (CameraManager::getSingletonPtr() == nullptr) {
        new CameraManager();
    }
    CameraManager::getSingleton().onCreate();
}

JNIEXPORT void JNICALL Java_com_friday_feeling_plus_camera_CameraRender_nativeOnResume(JNIEnv *env, jobject thiz)
{
    CameraManager::getSingleton().onResume();
}

JNIEXPORT void JNICALL Java_com_friday_feeling_plus_camera_CameraRender_nativeOnPause(JNIEnv *env, jobject thiz)
{
    CameraManager::getSingleton().onPause();
}

JNIEXPORT void JNICALL Java_com_friday_feeling_plus_camera_CameraRender_nativeOnStop(JNIEnv *env, jobject thiz)
{
    CameraManager::getSingleton().onStop();
}

JNIEXPORT void JNICALL Java_com_friday_feeling_plus_camera_CameraRender_nativeOnDestroy(JNIEnv *env, jobject thiz)
{
    CameraManager::getSingleton().onDestroy();
}

JNIEXPORT void JNICALL Java_com_friday_feeling_plus_camera_CameraRender_nativeInitGL(JNIEnv *env, jobject thiz, jint width, jint height)
{
    CameraManager::getSingleton().initGL(width, height);
}

JNIEXPORT void JNICALL Java_com_friday_feeling_plus_camera_CameraRender_nativeDrawFrame(JNIEnv *env, jobject thiz)
{
    CameraManager::getSingleton().drawFrame();
}

JNIEXPORT void JNICALL Java_com_friday_feeling_plus_camera_CameraRender_nativeOnSurfaceChanged(JNIEnv *env, jobject thiz, jint width, jint height)
{
    // Change();
}

JNIEXPORT jint JNICALL Java_com_friday_feeling_plus_camera_CameraRender_nativeGetTextureId(JNIEnv *env, jobject thiz)
{
    return CameraManager::getSingleton().getCameraTextureId();
}

#ifdef __cplusplus
}
#endif
#endif
