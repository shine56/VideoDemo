#include <android/log.h>
#include <stdlib.h>

#include "gl_util.h"

#define LOGD(...) __android_log_print(ANDROID_LOG_WARN,"yuvOpenGlDemo",__VA_ARGS__)

GLuint GLUtils::LoadShader(const char *pSource, GLint shaderType) {
    GLuint shader = 0;
    LOGD("GLUtils::LoadShader");
    shader = glCreateShader(shaderType);
    LOGD("GLUtils::LoadShader1");
    if (shader)
    {
        glShaderSource(shader, 1, &pSource, NULL);
        glCompileShader(shader);
        GLint compiled = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled)
        {
            GLint infoLen = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
            if (infoLen)
            {
                char* buf = (char*) malloc((size_t)infoLen);
                if (buf)
                {
                    glGetShaderInfoLog(shader, infoLen, NULL, buf);
                    LOGD("GLUtils::LoadShader Could not compile shader %d:\n%s\n", shaderType, buf);
                    free(buf);
                }
                glDeleteShader(shader);
                shader = 0;
            }
        }
    }
    return shader;
}

GLuint GLUtils::CreateProgram(
        const char *pVertexShaderSource,
        const char *pFragShaderSource,
        GLuint &vertexShaderHandle,
        GLuint &fragShaderHandle)
{


    LOGD("GLUtils::CreateProgram");
    GLuint program = 0;
    LOGD("GLUtils::CreateProgram0 %d", pVertexShaderSource == nullptr);
    vertexShaderHandle = LoadShader(pVertexShaderSource, GL_VERTEX_SHADER);
    if (!vertexShaderHandle) return program;

    fragShaderHandle = LoadShader(pFragShaderSource, GL_FRAGMENT_SHADER);
    if (!fragShaderHandle) return program;

    program = glCreateProgram();
    if (program)
    {
        glAttachShader(program, vertexShaderHandle);
        CheckGLError("glAttachShader");
        glAttachShader(program, fragShaderHandle);
        CheckGLError("glAttachShader");
        glLinkProgram(program);
        GLint linkStatus = GL_FALSE;
        glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);

        glDetachShader(program, vertexShaderHandle);
        glDeleteShader(vertexShaderHandle);
        vertexShaderHandle = 0;
        glDetachShader(program, fragShaderHandle);
        glDeleteShader(fragShaderHandle);
        fragShaderHandle = 0;
        if (linkStatus != GL_TRUE)
        {
            GLint bufLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLength);
            if (bufLength)
            {
                char* buf = (char*) malloc((size_t)bufLength);
                if (buf)
                {
                    glGetProgramInfoLog(program, bufLength, NULL, buf);
                    LOGD("GLUtils::CreateProgram Could not link program:\n%s\n", buf);
                    free(buf);
                }
            }
            glDeleteProgram(program);
            program = 0;
        }
    }
    LOGD("GLUtils::CreateProgram program = %d", program);
    return program;
}

void GLUtils::DeleteProgram(GLuint &program)
{
    LOGD("GLUtils::DeleteProgram");
    if (program)
    {
        glUseProgram(0);
        glDeleteProgram(program);
        program = 0;
    }
}

void GLUtils::CheckGLError(const char *pGLOperation)
{
    for (GLint error = glGetError(); error; error = glGetError())
    {
        LOGD("GLUtils::CheckGLError GL Operation %s() glError (0x%x)\n", pGLOperation, error);
    }

}

