// main for " openglbook.com " tutorials

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>

using namespace std;

int screenWidth = 800;
int screenHeight = 600;
int WindowHandle = 0;


void initialize(int, char*[]);
void initwindow(int, char*[]);
void resizefunction(int, int);
void renderfunction(void);


void initialize(int i, char* c[]) {
	initwindow(i, c);
	cout << "INFO: OpenGL Version: " << glGetString(GL_VERSION) << endl;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void initwindow(int i, char* c[]) {
	glutInit(&i, c);

	glutInitContextVersion(4, 0);
	glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutSetOption(
		GLUT_ACTION_ON_WINDOW_CLOSE,
		GLUT_ACTION_GLUTMAINLOOP_RETURNS
	);

	glutInitWindowSize(screenWidth, screenHeight);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	WindowHandle = glutCreateWindow("Chapter 1");

	if (WindowHandle < 1) {
		cerr << "ERROR: Could not create a new rendering window." << endl;
		return;
	}

	glutReshapeFunc(resizefunction);
	glutDisplayFunc(renderfunction);
}

void resizefunction(int width, int height) {
	screenWidth = width;
	screenHeight = height;
	glViewport(0, 0, screenWidth, screenHeight);
}

void renderfunction(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glutSwapBuffers();
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
	initialize(argc, argv);

	glutMainLoop();

	return EXIT_SUCCESS;
}