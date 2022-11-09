package com.example.opengleslean;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * Created by Shine56 on 2022/11/5 16:48
 * Description：
 */
public class DWGlSurfaceView extends GLSurfaceView {

    private DWRender dwRender;
    private NativeRender nativeRender;

    public DWGlSurfaceView(Context context) {
        super(context);
    }

    public DWGlSurfaceView(Context context, AttributeSet attrs) {
        super(context, attrs);
        this.setEGLContextClientVersion(3);
        nativeRender = new NativeRender();
        dwRender = new DWRender(nativeRender);
        setRenderer(dwRender);
        setRenderMode(RENDERMODE_WHEN_DIRTY);
        nativeRender.native_OnInit();
    }
}

class DWRender implements GLSurfaceView.Renderer{

    private NativeRender nativeRender;

    public DWRender(NativeRender nativeRender){
        this.nativeRender = nativeRender;
    }

    @Override
    public void onSurfaceCreated(GL10 gl10, EGLConfig eglConfig) {
        nativeRender.native_onSurfaceCreated();
    }

    @Override
    public void onSurfaceChanged(GL10 gl10, int w, int h) {
        nativeRender.native_onSurfaceChanged(w, h);
    }

    @Override
    public void onDrawFrame(GL10 gl10) {
        nativeRender.native_onDrawFrame();
    }
}
