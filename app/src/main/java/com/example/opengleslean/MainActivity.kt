package com.example.opengleslean

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }

    /**
     * A native method that is implemented by the 'opengleslean' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String
}