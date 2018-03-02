#version 330

in vec3 position;
in vec4 inColor;

out vec4 ex_Color;

uniform mat4 mvp;
void main(void) {
	gl_Position = mvp * vec4(position.x, position.y, position.z, 1.0);

	ex_Color = inColor;
}