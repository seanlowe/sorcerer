#version 330

precision highp float;

in vec4 ex_Color;

out vec4 outColor;

float rand(vec2 co);

bool randomColor = false;

void main(void) {
	//if (randomColor) {
		//outColor.r = (ex_Color.r * 0.5) + ( rand(ex_Color.ra) * 0.5);
		//outColor.g = (ex_Color.g * 0.5) + ( rand(ex_Color.bg) * 0.5);
		//outColor.b = (ex_Color.b * 0.5) + ( rand(ex_Color.gb) * 0.5);
		//outColor.a = ex_Color.a;
	//} else {
		//outColor = ex_Color;
		gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
	//}
}


float rand(vec2 co) {
	highp float a = 12.9898;
	highp float b = 78.233;
	highp float c = 43758.5453;
	highp float dt = dot(co.xy, vec2(a,b));
	highp float sn = mod(dt, 3.14);
	return fract(sin(sn) * c);
}