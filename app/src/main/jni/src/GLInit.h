#ifndef __GLINIT_H__
#define __GLINIT_H__
#include <jni.h>
#include <errno.h>
#include <stdio.h>
#include <android/log.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <EGL/egl.h>
#include <GLES/gl.h>
#include "Common.h"
#include "Singleton.h"
class GLInit : public Singleton<GLInit> {
public:
    GLInit();
    ~GLInit();
    bool                                initDisplay();
    void		                        swapBuffers() { eglSwapBuffers(_mDisplay, _mSurface); }
    void                                onDestroy();

private:
    ANativeWindow*                      _mWindow;
    EGLDisplay	                        _mDisplay;
    EGLContext	                        _mContext;
    EGLSurface	                        _mSurface;
    EGLConfig	                        _mConfig;
    int 		                        _mWindowWidth;
    int 		                        _mWindowHeight;
};

#endif /* __GLINIT_H__ */