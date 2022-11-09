package com.example.opengleslean;

/**
 * Created by Shine56 on 2022/11/5 16:56
 * Description：
 */
public class NativeRender {

    static {
        System.loadLibrary("opengleslean");
    }

    public native void native_OnInit();

    public native void native_OnUnInit();

    public native void native_SetImageData(int format, int width, int height, byte[] bytes);

    public native void native_onSurfaceCreated();
    public native void native_onSurfaceChanged(int width, int height);
    public native void native_onDrawFrame();
}
