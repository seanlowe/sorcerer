#include "shader.h"
using namespace std;

// create vertex shader
//const GLchar* vertexSource = R"glsl(
//		#version 330
//
//		in vec3 position;
//		in vec4 inColor;
//
//		out vec4 outColor;
//
//		uniform mat4 mvp;
//		void main() {
//			gl_Position = mvp * vec4(position.x, position.y, position.z, 1.0);
//
//			outColor = inColor;
//		}
//	)glsl";
//
// create fragment shader
//const GLchar* fragmentSource = R"glsl(
//		#version 330
//
//		in vec4 inColor;
//		out vec4 outColor;
//		void main() {
//			outColor = vec4(1.0, 1.0, 1.0, 1.0);
//		}
//	)glsl";


shader::shader() {}

// creates shader program and loads each shader file, then links them.
bool shader::shaderInit() {
	// create shader. putting it like this puts the ID in shaderProgram
	shaderProgram = glCreateProgram();

	if (!loadShader("vert.glsl", GL_VERTEX_SHADER)) {
		return false;
	}
	//if (!loadShader("geom.glsl", GL_GEOMETRY_SHADER)) {
	//	return false;
	//}
	if (!loadShader("frag.glsl", GL_FRAGMENT_SHADER)) {
		return false;
	}

	return linkShaders();
}

//void shader::trythisinit() {
//
//	// create vertex shader
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexSource, NULL);
//	glCompileShader(vertexShader);
//	
//	GLint statusVertex;
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &statusVertex);
//	if (statusVertex != true) {
//		cerr << "Could not compile shaders" << endl;
//	}
//	// end vertex shader creation and check
//	
//	
//	
//	// begin fragment shader creation
//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
//	glCompileShader(fragmentShader);
//	
//	GLint statusFragment;
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &statusFragment);
//	if (statusFragment != true) {
//		cerr << "Could not compile fragment shaders" << endl;
//	}
//	// end fragment shader creation and check
//	
//	
//	
//	// create a ' program ' out of the various shader pieces
//	shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glBindFragDataLocation(shaderProgram, 0, "outColor");
//	
//	// use ' glDrawBuffers' when rendering to multiple buffers, because
//	// only the first output will be enabled by default.
//	
//	glLinkProgram(shaderProgram);
//	glUseProgram(shaderProgram);
//	// only one shader can be active at a time in a program
//	// end shader 'program' creation */
//	
//	
//	posAttrib = glGetAttribLocation(shaderProgram, "position");
//	colAttrib = glGetAttribLocation(shaderProgram, "inColor");
//	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
//	glEnableVertexAttribArray(posAttrib);
//	glVertexAttribPointer(colAttrib, 4, GL_FLOAT, GL_FALSE, 0, 0);
//	glEnableVertexAttribArray(colAttrib);
//}

// creates a shader, loads info from text file and attaches it to the shader program
bool shader::loadShader(const string & filename, GLenum shaderType) {
	// cout << "Loading Shader: "" << filename << endl;
	
	int shaderID = createShader(filename, shaderType);

	if (tryCompile(shaderID)) {
		glAttachShader(shaderProgram, shaderID);
		shaderIDs.push_back(shaderID);

		return true;
	}

	return false;
}

void shader::useProgram() {
	glUseProgram(shaderProgram);
}

void shader::close() {

	// clean up stuff that was bound / allocated
	glUseProgram(0);

	for (auto i : shaderIDs) {
		glDetachShader(shaderProgram, i);
	}
	glDeleteProgram(shaderProgram);

	for (auto i : shaderIDs) {
		glDeleteShader(i);
	}
}

bool shader::tryCompile(int shaderID) {
	glCompileShader(shaderID);

	GLint statusVertex;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &statusVertex);
	if (statusVertex != true) {
		cerr << "Could not compile shaders" << endl;
		printCompileError(shaderID);
		return false;
	}
	return true;
}

int shader::createShader(const string & filename, GLenum shaderType) {
	// read file as string
	string str = readFile(filename.c_str());

	// c_str() gives a const char* -- we need non const
	char* src = const_cast<char*>(str.c_str());
	int32_t size = str.length();

	// create empty vertex shader handle
	int shaderID = glCreateShader(shaderType);

	// send vertex shader source code to OpenGL
	glShaderSource(shaderID, 1, &src, &size);

	return shaderID;
}

bool shader::linkShaders() {

	glLinkProgram(shaderProgram);

	GLint statusProgram;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &statusProgram);
	if (statusProgram != true) {
		printLinkError(shaderProgram);
		return false;
	}
	return true;
}

string shader::readFile(const char* file) {

	ifstream fin(file);
	string content ((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
	return content;
}

void shader::printLinkError(int32_t shaderID) {
	cout << "Shader Linking Failed: " << endl;

	// find length of shader info log
	int maxLength;
	glGetProgramiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);

	cout << "Info Length: " << maxLength << endl;

	// get shader info log
	char* shaderProgramInfoLog = new char[maxLength];
	glGetProgramInfoLog(shaderProgram, maxLength, &maxLength, shaderProgramInfoLog);

	// handle the error by printing it to console and deleting ptr
	cout << "Linker error message: " << shaderProgramInfoLog << endl;

	delete [] shaderProgramInfoLog;
	return;
}

void shader::printCompileError(int32_t shaderID) {
	int maxLength;
	glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);

	char* shaderInfoLog = new char[maxLength];
	glGetShaderInfoLog(shaderID, maxLength, &maxLength, shaderInfoLog);

	string log = shaderInfoLog;

	if (log.length()) {
		cout << shaderInfoLog << endl;
	}
	delete [] shaderInfoLog;
	return;
}
