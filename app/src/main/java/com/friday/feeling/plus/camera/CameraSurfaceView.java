package com.friday.feeling.plus.camera;

import android.content.Context;
import android.opengl.GLSurfaceView;

/**
 * Create asus on 2017/12/27.
 */

public class CameraSurfaceView extends GLSurfaceView {
    private CameraRender mCameraRender;
    private Context mContext;
    private static volatile CameraSurfaceView instance;

    public static CameraSurfaceView getInstance(Context context) {
        if (instance == null) {
            synchronized (CameraSurfaceView.class) {
                if (instance == null) {
                    instance = new CameraSurfaceView(context);
                }
            }
        }
        return instance;
    }

    private CameraSurfaceView(Context context) {
        super(context);
        mContext = context;
        setEGLContextClientVersion(2);
        mCameraRender = new CameraRender(context);
        setRenderer(mCameraRender);
    }

    @Override
    public void onResume() {
        super.onResume();
        mCameraRender.onResume();
//        mCameraRender.startCamera(mContext);
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
