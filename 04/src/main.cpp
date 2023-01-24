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

// Creates a triangle and stores it in points, also stores colors.
void triangle(std::vector<glm::vec3>& points, std::vector<glm::vec3>& colors, glm::vec3 a, glm::vec3 b, glm::vec3 c, size_t color_index) {

    // A set of base colors (RGB)
    std::vector<glm::vec3> base_color = { glm::vec3(1.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3(0.0f, 0.0f, 0.0f) };

    // Adding a color index each time we add a vertex location so 3D elements can be seen properly in the image.
    points.push_back(a);
    colors.push_back( base_color[color_index] );
    points.push_back(b);
    colors.push_back( base_color[color_index] );
    points.push_back(c);
    colors.push_back( base_color[color_index] );
}

// Creates four triangles from the given four points by calling the triangle function.
void tetra(std::vector<glm::vec3>& points, std::vector<glm::vec3>& colors, glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d) {
    triangle( points, colors, a, c, b, 0 );
    triangle( points, colors, a, c, d, 1 );
    triangle( points, colors, a, b, d, 2 );
    triangle( points, colors, b, c, d, 3 );
}

// Subdividing the tetrahedron similar to how it was done to the triangle for the 2D representation/ recursively splits a tetrahedron.
void divide_tetra(std::vector<glm::vec3>& points, std::vector<glm::vec3>& colors, glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d, unsigned int count) {
    // Draws only if count is zero, otherwise will subdivide with the help of divide_tetra.
    if ( count == 0 ) {
        tetra(points, colors, a, b, c, d);
    }

    else {
        // Subdivision of the tetrahedron.
        glm::vec ab = mix( a, b, 0.5 );
        glm::vec ac = mix( a, c, 0.5 );
        glm::vec ad = mix( a, d, 0.5 );
        glm::vec bc = mix( b, c, 0.5 );
        glm::vec bd = mix( b, d, 0.5 );
        glm::vec cd = mix( c, d, 0.5 );

        // Decreases count since one revision has been done.
        count--;

        divide_tetra( points, colors, a, ab, ac, ad, count );
        divide_tetra( points, colors, ab,  b, bc, bd, count );
        divide_tetra( points, colors, ac, bc,  c, cd, count );
        divide_tetra( points, colors, ad, bd, cd,  d, count );
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

    // Initial locations of the points for the 3D triangles.
    std::vector<glm::vec3> vertices = { glm::vec3(0.f, -0.1547f, -1.f),
                                    glm::vec3(0.f, 0.866f, 1.f),
                                    glm::vec3(-1.f, -0.866f, 1.f),
                                    glm::vec3(1.f, -0.866f, 1.f) };

    // Initialized for storage of points generated.
    std::vector<glm::vec3> points;

    // Initialized for storage of colors.
    std::vector<glm::vec3> colors;

    // Number of times recursion will be performed
    const unsigned int num_recursion = 3;

    divide_tetra( points, colors, vertices[0], vertices[1], vertices[2], vertices[3], num_recursion);

    //  Load shaders and initialize attribute buffers
    cg::Program program = { "shaders/gasket-2d.vert",
                            "shaders/gasket-2d.frag" };
    glUseProgram(program.id());

    // Load the data into the GPU
    cg::Buffer buffer;

    glBindBuffer(GL_ARRAY_BUFFER, buffer.id());
    glBufferData(GL_ARRAY_BUFFER, points.size() * sizeof(glm::vec3), &points[0],
                 GL_STATIC_DRAW);
    
    // Associate out shader variables with our data buffer
    GLuint in_position = glGetAttribLocation(program.id(), "in_position");
    glVertexAttribPointer(in_position, 3, GL_FLOAT, false, 0, 0);
    glEnableVertexAttribArray(in_position);

    // Loading the color buffer into the GPU.
    cg::Buffer buffer_color;

    glBindBuffer(GL_ARRAY_BUFFER, buffer_color.id());
    glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(glm::vec3), &colors[0],
                 GL_STATIC_DRAW);
                
    // Associate out shader variables with our color data buffer
    GLuint in_color = glGetAttribLocation(program.id(), "in_color");
    glVertexAttribPointer(in_color, 3, GL_FLOAT, false, 0, 0);
    glEnableVertexAttribArray(in_color);

    // Set clear color
    glClearColor(1.f, 1.f, 1.f, 1.f);

    // enable hidden-surface removal
    glEnable(GL_DEPTH_TEST);

    // Render loop
    view.loop([&](auto width, auto height, auto scaling) {
        glViewport(0, 0, static_cast<GLsizei>(width * scaling),
                   static_cast<GLsizei>(height * scaling));
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(points.size()));
    });

    return 0;
}
