package com.friday.feeling.plus.camera;

import android.content.Context;
import android.opengl.GLSurfaceView;

/**
 * Create asus on 2017/12/27.
 */

public class CameraSurfaceView extends GLSurfaceView {
    private static final String TAG = "CameraGLSurfaceView";
    private CameraRender mCameraRender;

    public CameraSurfaceView(Context context) {
        super(context);
        setEGLContextClientVersion(2);
        mCameraRender = new CameraRender(context);
        setRenderer(mCameraRender);
    }

    @Override
    public void onResume() {
        super.onResume();
    }

    @Override
    public void onPause() {
        super.onPause();
    }

    public void onDestroy() {
    }
}
