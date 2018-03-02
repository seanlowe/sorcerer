// OPENGL MAIN
#include "head.h"
using namespace std;

int main(int argc, char* argv[]) {
	head mainl;
	GLfloat rotation = 0.0f;


	if (!mainl.inithead()) {
		cerr << "Could not initialize" << endl;
		return 1;
	}
	
	//glDisable(GL_CULL_FACE);

	SDL_Event event, windowEvent;
	while (!mainl.getRunState()) {
		SDL_PollEvent(&event);
		
		if (SDL_PollEvent(&windowEvent)) {
			if (windowEvent.type == SDL_QUIT) { 
				mainl.changeRunState();
				break;
			}
		}

		switch (event.type) {
		case SDL_QUIT:
			mainl.changeRunState();
			break;
		case SDL_KEYDOWN:
			mainl.keyDown(event);
			break;
		case SDL_MOUSEMOTION:
			// set sprite position to position of the mouse
			mainl.setPos(event.motion.x, event.motion.y);
			mainl.setWindowTitle();
			break;
		}
		//trying 3d stuff
		mainl.camera();

		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0, (640.0 / 480.0), 0.1, 100.0);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();



		glTranslatef(0.0f, 0.0f, -6.0f);
		glRotatef(rotation, 1.0f, 1.0f, 0.0f);

		glBegin(GL_QUADS);

		/* Cube Top */
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);


		/* Cube Bottom */
		glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);

		/* Cube Front */
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);

		/* Cube Back */
		glColor4f(0.0f, 1.0f, 0.5f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);

		/* Cube Left Side */
		glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);

		/* Cube Right Side */
		glColor4f(0.15f, 0.25f, 0.75f, 1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);


		glEnd();
		glLoadIdentity();

		rotation = -0.5f;
		//SDL_GL_SwapWindow(mainl.getWindow());

		mainl.renderLoop();
	}
	mainl.close();	
	return 0;
}