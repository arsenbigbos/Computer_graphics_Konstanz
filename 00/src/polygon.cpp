#include "polygon.h"

#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;

Polygon::Polygon() {}

void Polygon::addPoint(vec2 new_point) {
    points.push_back(new_point);
}

unsigned int Polygon::getPointCount() {
    return static_cast<unsigned int>(points.size());
}

void Polygon::clear() {
    points.clear();
}

float Polygon::getArea() {
    float area = 0;

    for (int current_index = 0; current_index < points.size();
         ++current_index) {
        int previous_index = (current_index - 1) % points.size();

        vec2 prev = points.at(previous_index);
        vec2 curr = points.at(current_index);
        area += (prev.x + curr.x) * (prev.y - curr.y);

        // https://mathworld.wolfram.com/PolygonArea.html
        // (this example is incomplete)
    }
    return static_cast<float>(abs(area / 2.0));

    // const_cast: "I want to edit this"
    // dynamic_cast: "Turn this class instance into another class instance (within the same hierarchy)"
    // reinterpret_cast: "Hold my beer." (convert pointer types with no checks)
    // (type): Old C-style cast
}

float* Polygon::asVertexArray(int& vertex_array_size) {
    vertex_array_size = static_cast<int>(points.size()) * 3;
    float* vertex_array = new float[vertex_array_size];

    for (int i = 0; i < points.size(); ++i) { // array striding
        vertex_array[3 * i + 0] = points.at(i).x;
        vertex_array[3 * i + 1] = points.at(i).y;
        vertex_array[3 * i + 2] = 0.0f;
    }

    return vertex_array;
}
