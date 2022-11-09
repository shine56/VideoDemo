#include <android/log.h>

#include "simple_triangle_draw.h"
#include "gl_util.h"

#define LOGD(...) __android_log_print(ANDROID_LOG_WARN,"yuvOpenGlDemo",__VA_ARGS__)

void SimpleTriAngle::startDraw() {

    GLfloat vVertices[] = {
            0.0f,  0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
    };

    if(m_ProgramObj == 0){
        LOGD("m_ProgramObj is null");
        return;
    }

    // Use the program object 激活渲染程序
    glUseProgram (m_ProgramObj);

    // Load the vertex data
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, vVertices );
    glEnableVertexAttribArray (0);

    glDrawArrays (GL_TRIANGLES, 0, 3);
}

void SimpleTriAngle::init() {
    char vShaderStr[] =
            "#version 300 es                          \n"
            "layout(location = 0) in vec4 vPosition;  \n"
            "void main()                              \n"
            "{                                        \n"
            "   gl_Position = vPosition;              \n"
            "}                                        \n";

    char fShaderStr[] =
            "#version 300 es                              \n"
            "precision mediump float;                     \n"
            "out vec4 fragColor;                          \n"
            "void main()                                  \n"
            "{                                            \n"
            "   fragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );  \n"
            "}                                            \n";

    m_ProgramObj = GLUtils::CreateProgram(
            vShaderStr,
            fShaderStr,
            vertexShaderHandler,
            fragShaderHandler
            );
}

SimpleTriAngle::~SimpleTriAngle() {
    GLUtils::DeleteProgram(m_ProgramObj);
}

SimpleTriAngle::SimpleTriAngle() {

}
