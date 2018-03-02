#version 330

layout(triangles) in;
layout(triangle_strip, max_vertices = 100) out;

in vec4 color[];

out vec4 ex_Color;

void MakeEar(vec4 v);
void MakeBasicTriangle();
void MakeSplitTriangle(float dist);
void MakeTriangle(vec4 v1, vec4 v2, vec4 v3);

vec4 corner1 = gl_in[0].gl_Position;
vec4 corner2 = gl_in[1].gl_Position;
vec4 center  = gl_in[2].gl_Position;


float explodeDist = 0.66;

bool makeNormal = true;
bool makeExploded = true;
bool makeEars = true;

void main() {
	if (makeNormal) { MakeBasicTriangle(); }
	if (makeExploded) { MakeSplitTriangle(explodeDist); }
	if (makeEars) { MakeEar(corner1); MakeEar(corner2); }
}

void MakeSplitTriangle(float dist) {
	vec4 diff = (corner1 - corner2) * dist;

	vec4 offset = vec4(0.0f);

	// flip in order to get a 'normal'
	// this is direction the triangles will move
	offset.x = diff.y;
	offset.y = diff.x;

	// set new positions
	corner1 += offset;
	corner2 += offset;
	center += offset;

	MakeTriangle(center, corner1, corner2);
}

// Basic geometry shader (akin to calling the standard OpenGL Shader)
void MakeBasicTriangle() {
	vec4 v1 = gl_in[0].gl_Position;
	vec4 v2 = gl_in[1].gl_Position;
	vec4 v3 = gl_in[2].gl_Position;

	MakeTriangle(v1, v2, v3);
}

// draws a symmetric triangle on the corners of the square (a.k.a. "ears")
void MakeEar(vec4 v) {
	vec4 v1 = v + vec4(0.0, 1.0*v.y, 0.0, 0.0);
	vec4 v2 = v + vec4(1.0*v.x, 0.0, 0.0, 0.0);
	vec4 v3 = v + vec4(0.0, 0.0, 0.0, 0.0);

	MakeTriangle(v1, v2, v3);
}

// makes a triangle with the colors passed in from previous shaders
void MakeTriangle(vec4 v1, vec4 v2, vec4 v3) {

	// set position of new vertex
	gl_Position = v1;

	// set color of new vertex
	ex_Color = color[0];

	// create new vertex
	// gl_Position & ex_Color are basically temp variables for every vertex made
	EmitVertex();

	gl_Position = v2;
	ex_Color = color[1];
	EmitVertex();

	gl_Position = v3;
	ex_Color = color[2];
	EmitVertex();

	// need to tell OpenGL "We're done"
	// after this, any call to MakeTriangle will make a new triangle
	EndPrimitive();
}