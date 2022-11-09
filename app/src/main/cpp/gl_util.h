#include <EGL/egl.h>
#include <GLES3/gl3.h>

class GLUtils{

    static void CheckGLError(const char *pGLOperation);

public:
    static GLuint CreateProgram(const char *pVertexShaderSource, const char *pFragShaderSource,
                                GLuint &vertexShaderHandle, GLuint &fragShaderHandle);

    static GLuint LoadShader(const char *source, GLint type);

    static void DeleteProgram(GLuint &program);
};
