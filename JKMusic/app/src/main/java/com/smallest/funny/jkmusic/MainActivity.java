package com.smallest.funny.jkmusic;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.smallest.funny.jkmusicplayer.Demo;

public class MainActivity extends AppCompatActivity {

    private Demo mDemo;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mDemo = new Demo();
        mDemo.testMusicPlayer();
        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);

        tv.setText("");
    }


}
