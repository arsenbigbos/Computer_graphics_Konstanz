#version 330

in vec3 in_position;
in vec3 in_color;

out VertexData {
    vec3 color;
}
OUT;

// Using in_color to set a color to be sent to the fragment shader.
void main() {
    OUT.color = in_color;
    gl_Position = vec4(in_position, 1);
}
