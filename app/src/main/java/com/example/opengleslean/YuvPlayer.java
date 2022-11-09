package com.example.opengleslean;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;
import android.view.SurfaceHolder;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * Created by Shine56 on 2022/11/4 23:11
 * Description：
 */
public class YuvPlayer extends GLSurfaceView
        implements GLSurfaceView.Renderer, Runnable, SurfaceHolder.Callback {

    public YuvPlayer(Context context, AttributeSet attrs) {
        super(context, attrs);
        setRenderer(this);
    }

    @Override
    public void run() {
        drawTriangle(getHolder().getSurface());
    }

    public native void drawTriangle(Object surface);


    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        new Thread(this).start();
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int w, int h) {

    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {

    }

    @Override
    public void onSurfaceCreated(GL10 gl10, EGLConfig eglConfig) {

    }

    @Override
    public void onSurfaceChanged(GL10 gl10, int i, int i1) {

    }

    @Override
    public void onDrawFrame(GL10 gl10) {

    }
}
