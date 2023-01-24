#version 330

out vec4 out_color;

in VertexData {
    vec3 color;
}
IN;

void main() {
    out_color = vec4(IN.color, 1);
}
