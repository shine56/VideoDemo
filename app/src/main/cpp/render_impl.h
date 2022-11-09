#include "stdint.h"
#include "simple_triangle_draw.h"

class RenderImpl {
private:
    SimpleTriAngle simpleTriAngle = SimpleTriAngle();
public:

    static RenderImpl* getInstance();

    ~RenderImpl() = default;

    static void release();

    void SetImageData(int format, int width, int height, uint8_t* bytes);

    void onSurfaceCreated();
    void onSurfaceChanged(int width, int height);
    void onDrawFrame();
};
