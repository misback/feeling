#pragma once
#include <time.h>
#include <math.h>
#include <android/log.h>
#include <EGL/egl.h>
#include <GLES/gl.h>
#include "Singleton.h"
#include "android/asset_manager.h"
#include <android/asset_manager_jni.h>
#include <android/native_window_jni.h>
#include "glm.hpp"
#include "ext.hpp"
#include <thread>
#include "JniHelper.h"
class CameraManager : public Singleton<CameraManager> {
public:
    CameraManager();
    ~CameraManager();
    void                        onCreate();
    void                        onResume();
    void                        onPause();
    void                        onStop();
    void                        onDestroy();

    void                        initGL(float width, float height);
    void                        deInitGL();
    void                        drawFrame();

    GLint                       getCameraTextureId();

private:
    int                         _photoWidth;
    int                         _photoHeight;
    GLuint                      _sProgramPlay;
    GLuint						_textureId;
};