//#include <SDL.h>
//#include <iostream>
//#include <sstream>
//#include "globals.h"
//
//using namespace std;
//
//int main(int argc, char* argv[]) {
//	globals setup;
//
//
//	if (!setup.init()) {
//		cout << "Failed to initialize" << endl;
//		return 1;
//	}
//
//	if (!setup.loadBackground("starbackground.bmp")) {
//		cout << "Failed to load background!" << endl;
//		return 1;
//	}
//
//	if (!setup.loadActor("figure.bmp")) {
//		cout << "Failed to load actor!" << endl;
//		return 1;
//	}
//
//	SDL_SetRenderDrawColor(setup.getRenderer(), 255, 255, 255, 255);
//
//	SDL_Event event;
//	while (!setup.getRunStatus()) {
//		setup.setDT();
//		SDL_PollEvent(&event);
//
//		switch (event.type) {
//		case SDL_QUIT:
//			setup.changeRunStatus();
//			break;
//		case SDL_KEYDOWN:
//			setup.setLast();
//			setup.KeyDown(event);
//			break;
//		/*case SDL_MOUSEMOTION:
//			setup.setPos(event.motion.x, event.motion.y);
//			setup.setWindowTitle();*/
//		}
//		setup.setLast();
//		setup.checkPosition();
//		
//		if (setup.pY < 700) {
//			setup.updateMovement(setup.pY, setup.vY, setup.aY, setup.dt);
//		}
//
//		SDL_Rect dstrect = { setup.getXPos(), setup.getYPos(),  64, 64 };
//
//		// print the background and player picture to back buffer (SDL)
//		SDL_RenderCopy(setup.getRenderer(), setup.getBackground(), NULL, NULL);
//		SDL_RenderCopy(setup.getRenderer(), setup.getActor(), NULL, &dstrect);
//		SDL_RenderPresent(setup.getRenderer());
//	}
//	setup.close();
//
//	return EXIT_SUCCESS;
//}