/*
 * Visual Computing
 * University of Konstanz
 * 2020
 *
 * main.cpp
 */

#include <cg/gl.h>

#include <cg/buffer.h>
#include <cg/config.h>
#include <cg/program.h>
#include <cg/vertex_array.h>
#include <cg/view.h>

#include <glm/glm.hpp>

void triangle(std::vector<glm::vec2>& points, glm::vec2 a, glm::vec2 b,
              glm::vec2 c) {
    // add vertices for one triangle

    points.push_back(a);
    points.push_back(b);
    points.push_back(c);
}

void divide_triangle(std::vector<glm::vec2>& points, glm::vec2 a, glm::vec2 b,
                     glm::vec2 c, unsigned int count) {
    // check for end of recursion

    if (count == 0) {
        triangle(points, a, b, c);
    } else {
        // bisect the sides

        glm::vec2 ab = glm::mix(a, b, 0.5f);
        glm::vec2 ac = glm::mix(a, c, 0.5f);
        glm::vec2 bc = glm::mix(b, c, 0.5f);

        --count;

        // three new triangles

        divide_triangle(points, a, ab, ac, count);
        divide_triangle(points, c, ac, bc, count);
        divide_triangle(points, b, bc, ab, count);
    }
}

int main(int argc, char* argv[]) {
    cg::set_working_directory();

    // Create canvas for rendering

    cg::View view(800, 800);

    // Create default vertex array object

    cg::VertexArray vao;

    // Initialize our data for the Sierpinski Gasket

    // First, initialize the corners of our gasket with three points.

    std::vector<glm::vec2> vertices = { glm::vec2(-1.f, -0.866f),
                                        glm::vec2(0.f, 0.866f),
                                        glm::vec2(1.f, -0.866f) };
    std::vector<glm::vec2> points;

    const unsigned int num_recursion = 3;
    divide_triangle(points, vertices[0], vertices[1], vertices[2],
                    num_recursion);

    //  Load shaders and initialize attribute buffers

    cg::Program program = { "shaders/gasket-2d.vert",
                            "shaders/gasket-2d.frag" };
    glUseProgram(program.id());

    // Load the data into the GPU

    cg::Buffer buffer;
    glBindBuffer(GL_ARRAY_BUFFER, buffer.id());
    glBufferData(GL_ARRAY_BUFFER, points.size() * sizeof(glm::vec2), &points[0],
                 GL_STATIC_DRAW);

    // Associate out shader variables with our data buffer

    GLuint in_position = glGetAttribLocation(program.id(), "in_position");
    glVertexAttribPointer(in_position, 2, GL_FLOAT, false, 0, 0);
    glEnableVertexAttribArray(in_position);

    // Set clear color

    glClearColor(1.f, 1.f, 1.f, 1.f);

    // Render loop

    view.loop([&](auto width, auto height, auto scaling) {
        glViewport(0, 0, static_cast<GLsizei>(width * scaling),
                   static_cast<GLsizei>(height * scaling));
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(points.size()));
    });

    return 0;
}
