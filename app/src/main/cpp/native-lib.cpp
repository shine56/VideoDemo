#include <jni.h>
#include <string>

#include "render_impl.h"

#define LOGD(...) __android_log_print(ANDROID_LOG_WARN,"yuvOpenGlDemo",__VA_ARGS__)

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_opengleslean_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_opengleslean_YuvPlayer_drawTriangle(
        JNIEnv *env, jobject thiz, jobject surface) {
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_opengleslean_NativeRender_native_1OnInit(JNIEnv *env, jobject thiz) {
    RenderImpl::getInstance();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_opengleslean_NativeRender_native_1OnUnInit(JNIEnv *env, jobject thiz) {
    RenderImpl::release();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_opengleslean_NativeRender_native_1SetImageData(JNIEnv *env, jobject thiz,
                                                                jint format, jint width,
                                                                jint height, jbyteArray bytes) {
    int len = env->GetArrayLength (bytes);
    uint8_t* buf = new uint8_t[len];
    env->GetByteArrayRegion(bytes, 0, len, reinterpret_cast<jbyte*>(buf));
    RenderImpl::getInstance()->SetImageData(format, width, height, buf);
    delete[] buf;
    env->DeleteLocalRef(bytes);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_opengleslean_NativeRender_native_1onSurfaceCreated(JNIEnv *env, jobject thiz) {
    RenderImpl::getInstance()->onSurfaceCreated();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_opengleslean_NativeRender_native_1onSurfaceChanged(
        JNIEnv *env,
        jobject thiz,
        jint width,
        jint height) {
    RenderImpl::getInstance()->onSurfaceChanged(width, height);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_opengleslean_NativeRender_native_1onDrawFrame(JNIEnv *env, jobject thiz) {
    RenderImpl::getInstance()->onDrawFrame();
}