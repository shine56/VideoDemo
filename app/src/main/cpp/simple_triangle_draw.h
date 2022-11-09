#include <EGL/egl.h>
#include <GLES3/gl3.h>

class SimpleTriAngle {
private:
    GLuint m_ProgramObj;
    GLuint vertexShaderHandler;
    GLuint fragShaderHandler;
public:

    SimpleTriAngle();

    ~SimpleTriAngle();

    void init();

    void startDraw();
};
