package com.friday.feeling.plus.activities;

import android.Manifest;
import android.app.Activity;
import android.content.pm.PackageManager;
import android.graphics.Point;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.view.ViewGroup;
import android.widget.ImageButton;
import android.widget.Toast;

import com.friday.feeling.plus.R;
import com.friday.feeling.plus.camera.CameraSurfaceView;
import com.friday.feeling.plus.util.DisplayUtil;

public class MainActivity extends Activity {
    private static final int REQUEST_CAMERA_PERMISSION = 1;
    CameraSurfaceView mCameraSurfaceView = null;
    ImageButton mImageButton;
    float previewRate = -1.0f;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        if (ContextCompat.checkSelfPermission(MainActivity.this,
                Manifest.permission.CAMERA) != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(MainActivity.this,
                    new String[]{Manifest.permission.CAMERA}, REQUEST_CAMERA_PERMISSION);
        }
        initUI();
        initViewParams();
    }

    private void initViewParams() {
        ViewGroup.LayoutParams params = mCameraSurfaceView.getLayoutParams();
        Point p = DisplayUtil.getScreenMetrics(this);
        params.width = p.x;
        params.height = p.y;
        previewRate = DisplayUtil.getScreenRate(this); // 默认全屏的比例预览
        mCameraSurfaceView.setLayoutParams(params);
        // 手动设置拍照ImageButton的大小为120dip×120dip,原图片大小是64×64
        ViewGroup.LayoutParams p2 = mImageButton.getLayoutParams();
        p2.width = DisplayUtil.dip2px(this, 80);
        p2.height = DisplayUtil.dip2px(this, 80);
        mImageButton.setLayoutParams(p2);
    }

    private void initUI() {
        mCameraSurfaceView = findViewById(R.id.camera_surfaceview);
        mImageButton = findViewById(R.id.btn_shutter);
    }

    @Override
    protected void onResume() {
        super.onResume();
        mCameraSurfaceView.onResume();
    }

    @Override
    protected void onPause() {
        super.onPause();
        mCameraSurfaceView.onPause();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mCameraSurfaceView.onDestroy();
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        switch (requestCode) {
            case REQUEST_CAMERA_PERMISSION:
                if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {

                } else {
                    Toast.makeText(this, "You denied the permission", Toast.LENGTH_SHORT).show();
                }
                break;
            default:
                break;
        }
    }

}
