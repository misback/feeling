package com.friday.feeling.plus.camera;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;

/**
 * Create asus on 2017/12/27.
 */

public class CameraSurfaceView extends GLSurfaceView {
    private CameraRender mCameraRender;
    private Context mContext;

    public CameraSurfaceView(Context context, AttributeSet attrs) {
        super(context, attrs);
        mContext = context;
        setEGLContextClientVersion(2);
        mCameraRender = new CameraRender(context);
        setRenderer(mCameraRender);
    }

    @Override
    public void onResume() {
        super.onResume();
        mCameraRender.onResume();
    }

    @Override
    public void onPause() {
        super.onPause();
        mCameraRender.onPause();
    }

    public void onDestroy() {
        mCameraRender.onDestroy();
    }
}
