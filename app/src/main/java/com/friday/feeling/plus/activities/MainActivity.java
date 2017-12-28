package com.friday.feeling.plus.activities;

import android.app.Activity;
import android.os.Bundle;

import com.friday.feeling.plus.R;
import com.friday.feeling.plus.fragment.CameraFragment;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        if (null == savedInstanceState) {
            getFragmentManager().beginTransaction()
                    .replace(R.id.container, CameraFragment.getInstance())
                    .commit();
        }
    }
}
