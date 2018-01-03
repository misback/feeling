package com.friday.feeling.plus.camera.render;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.Log;

/**
 * @authon by DELL
 * Create on 2018/1/3.
 */

public class TestSurfaceView extends GLSurfaceView {
    private static final String TAG = "TestSurfaceView";
    private MyRenderer mMyRenderer;

    public TestSurfaceView(Context context) {
        super(context);
        mMyRenderer = new MyRenderer();
        setRenderer(mMyRenderer);
    }

    @Override
    public void onResume() {
        super.onResume();
        Log.d(TAG, "onResume: " + "11111111111111");
    }

    @Override
    public void onPause() {
        super.onPause();
        Log.d(TAG, "onPause: " + "222222222222222222");
    }
}
