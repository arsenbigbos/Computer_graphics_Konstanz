#include <vector>

struct vec2 {
    vec2(float nx, float ny) {
        x = nx;
        y = ny;
    }
    float x, y;
};

class Polygon {
private:
    std::vector<vec2> points;

public:
    Polygon();
    void addPoint(vec2);
    unsigned int getPointCount();
    void clear();
    float getArea();
    float* asVertexArray(int& vertex_array_size);
};
