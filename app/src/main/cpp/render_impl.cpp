#include "render_impl.h"

RenderImpl* render_impl;

RenderImpl *RenderImpl::getInstance() {
    if (render_impl == nullptr){
        render_impl = new RenderImpl();
    }
    return render_impl;
}

void RenderImpl::SetImageData(int format, int width, int height, uint8_t *bytes) {

}

void RenderImpl::onSurfaceCreated() {
    glClearColor(1.0f,1.0f,0.5f, 1.0f);

}

void RenderImpl::onSurfaceChanged(int width, int height) {
    glViewport(0, 0, width, height);
}

void RenderImpl::onDrawFrame() {
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    simpleTriAngle.init();
    simpleTriAngle.startDraw();
}

void RenderImpl::release() {
    delete render_impl;
    render_impl = nullptr;
}

