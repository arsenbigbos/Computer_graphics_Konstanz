#version 330

in vec2 in_position;

out VertexData {
    vec3 color;
}
OUT;

void main() {
    OUT.color = vec3(0, 0, 0);
    gl_Position = vec4(in_position, 0, 1);
}
