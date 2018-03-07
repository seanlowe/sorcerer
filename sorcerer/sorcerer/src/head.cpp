//#include "head.h"
//using namespace std;
//
////#define DEBUG() {
////	if (glGetError() != GL_NO_ERROR) {
////	cerr << "error line " << __LINE__ << endl;
////	}
////}
//
//
//head::head() {
//	vertices[0] = 0.0f;
//	vertices[1] = 0.5f;
//	vertices[2] = 0.0f;
//
//	vertices[3] = 0.5f;
//	vertices[4] = -0.5f;
//	vertices[5] = 0.0f;
//
//	vertices[6] = -0.5f;
//	vertices[7] = -0.5f;
//	vertices[8] = 0.0f;
//}
//
//bool head::inithead() {
//	// overhead setup
//	
//	if (initsetup() == 1) {
//		return false;
//	}
//
//	if (glGetError() != GL_NO_ERROR) {
//		cerr << "error line " << __LINE__ << endl;
//	}
//
//	beforeShaderSetup();
//	if (glGetError() != GL_NO_ERROR) {
//		cerr << "error line " << __LINE__ << endl;
//	}
//
//	// shader init
//	if (!headShader.shaderInit()) {
//		return false;
//	}
//	// this will create the shader program, load the shaders, attach them to the prog
//	// and compile them
//
//	headShader.useProgram();
//	if (glGetError() != GL_NO_ERROR) {
//		cerr << "error line " << __LINE__ << endl;
//	}
//
//	const uint32_t positionAttributeIndex = 0, colorAttributeIndex = 1;
//
//	// transplanted from createshaders() that was originally in overhead
//	posAttrib = glGetAttribLocation(shaderProgram, "position");
//	if (glGetError() != GL_NO_ERROR) {
//		cerr << "error line " << __LINE__ << " posattrib = " << posAttrib << endl;
//	}
//
//	colAttrib = glGetAttribLocation(shaderProgram, "inColor");
//	if (glGetError() != GL_NO_ERROR) {
//		cerr << "error line " << __LINE__ << " colattrib = " << colAttrib << endl;
//	}
//
//	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
//	glEnableVertexAttribArray(posAttrib);
//	if (glGetError() != GL_NO_ERROR) {
//		cerr << "error line " << __LINE__ << endl;
//	}
//
//	glVertexAttribPointer(colAttrib, 4, GL_FLOAT, GL_FALSE, 0, 0);
//	if (glGetError() != GL_NO_ERROR) {
//		cerr << "error line " << __LINE__ << endl;
//	}
//
//	glEnableVertexAttribArray(colAttrib);
//	if (glGetError() != GL_NO_ERROR) {
//		cerr << "error line " << __LINE__ << endl;
//	}
//
//	return true;
//}
//
//void head::keyDown(SDL_Event event) {
//	overhead::keyDown(event);
//}
//
//void head::camera() {
//	// http://headerphile.com/sdl2/opengl-part-4-3d-basics/
//
//	// org.coloradomesa.edu/~kcastlet/CSCI445/demos/12/
//	if (glGetError() != GL_NO_ERROR) {
//		cerr << "error with something before the camera" << endl;
//	}
//	//----------------------------------------------------------------------
//	/*glClearColor(0, 0, 0, 0);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45.0, (640.0 / 480.0), 0.1, 100.0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	if (glGetError() != GL_NO_ERROR)
//	{
//		return false;
//	}
//
//	return true;*/
//	//----------------------------------------------------------------------
//
//	// translation matrix
//	glm::mat4 model = glm::translate(glm::vec3(3, 1, 5));
//	
//	// view matrix --> dictates the position and orientation of the game camera
//	// (what will end up on the screen)
//	glm::mat4 view = glm::lookAt
//	(
//		glm::vec3(0, 0, -5),	// camera is at (0, 0, -5) in world space
//		glm::vec3(0, 0, 0),		// looks at the center
//		glm::vec3(0, 1, 0)		// camera is rightside up
//	);
//	if (glGetError() != GL_NO_ERROR) {
//		cerr << "error with the view declaration" << endl;
//	}
//	// projection matrix
//	
//	glm::mat4 projection = glm::perspective
//	(
//		45.0f,					// 45 deg field of view
//		1920.0f / 1080.0f,		// 16:9 aspect ratio
//		0.1f,					// only render what's 0.1 or more away from the camera
//		100.0f					// only render what's 100 or less away from the camera
//	);
//	if (glGetError() != GL_NO_ERROR) {
//		cerr << "error with the projection" << endl;
//	}
//	// combine matrices into one so that we only have to multiply vertexes by 1 matrix
//	// instead of all three
//	glm::mat4 modelViewProjection = projection * view * model; // sometimes called ' mvp '
//	
//	SetMatrix(modelViewProjection);
//
//	if (glGetError() != GL_NO_ERROR) {
//		cerr << "error with the camera" << endl;
//	}
//}
//
//void head::close() {
//	// detaches and deletes shaders / shader programs
//	headShader.close();
//
//	// deletes SDL stuff and closes window.
//	overhead::close();
//}
//
//void head::SetMatrix(const glm::mat4 mat) {
//	int matrixID = glGetUniformLocation(getShaderProgram(), "mvp");
//
//	//glUniformMatrix4fv(matrixID, 1, GL_FALSE, &modelViewProjection[0][0]);
//
//	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &mat[0][0]);
//}
