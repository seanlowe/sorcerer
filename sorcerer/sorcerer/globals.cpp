//#include "globals.h"
//
//globals::globals() {
//	dead = false;
//	aX = 100.0;
//	aY = 100.0;
//	// velocity is in pixels per tick
//	vX = 100.0;
//	vY = 100.0;
//	pX = 100;
//	pY = 700; // "ground" level
//	dt = 0.0;
//	last = 0.0;
//
//	//	REMEMBER:
//	//			top of screen
//	//		x increases this way -->
//	//   -------------------------------
//	//	|								|	y increases
//	//	|								|   this way
//	//	|								|		|
//	//	|								|	  \ | /
//	//	|								|      \ /
//
//}
//
//void globals::setScreenDim(int w, int h) {
//	SCREEN_WIDTH = w;
//	SCREEN_HEIGHT = h;
//}
//
//void globals::setPos(float x, float y) {
//	pX = x;
//	pY = y;
//}
//
//void globals::setX(float x) {
//	pX = x;
//}
//
//void globals::setY(float y) {
//	pY = y;
//}
//
//void globals::setDT() {
//	dt = ((float)SDL_GetTicks() - last) / (float)1000.0;
//}
//
//void globals::setLast() {
//	last = SDL_GetTicks();
//}
//
//void globals::setWindowTitle() {
//	/* set window title to cursor's XY coordinates */
//	stringstream ss;
//	ss << "X: " << getXPos() << " Y: " << getYPos();
//	SDL_SetWindowTitle(getWindow(), ss.str().c_str());
//	return;
//}
//
//bool globals::init() {
//	bool success = true;
//	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//		cout << "Could not initialize SDL: " << SDL_GetError() << endl;
//		success = false;
//	}
//
//	window = SDL_CreateWindow("SDL Tutorial",
//		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
//		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
//
//	renderer = SDL_CreateRenderer(window, -1, 0);
//
//	if (window == NULL) {
//		cout << "Could not create window: " << SDL_GetError() << endl;
//		return false;
//	}
//	if (renderer == NULL) {
//		cout << "Could not create renderer: " << SDL_GetError() << endl;
//		return 1;
//	}
//
//	SDL_Surface* ScreenSurface = NULL;
//	ScreenSurface = SDL_GetWindowSurface(window);
//	return success;
//}
//
//bool globals::loadBackground(const char* filename) {
//	bool success = true;
//	SDL_Surface *temp = NULL;
//	temp = SDL_LoadBMP(filename);
//	if (temp == NULL) {
//		cout << "Could not load image: " << SDL_GetError() << endl;
//		return false;
//	}
//	background = SDL_CreateTextureFromSurface(renderer, temp);
//	SDL_FreeSurface(temp);
//	return success;
//}
//
//bool globals::loadActor(const char* filename) {
//	bool success = true;
//
//	SDL_Surface* temp = NULL;
//	temp = SDL_LoadBMP(filename);
//	if (temp == NULL) {
//		cout << "Could not load image: " << SDL_GetError() << endl;
//		return false;
//	}
//	// set a certain color to be transparent
//	//SDL_SetColorKey(temp, SDL_TRUE, SDL_MapRGB(temp->format, 255, 255, 255));
//	actor = SDL_CreateTextureFromSurface(renderer, temp);
//	SDL_FreeSurface(temp);
//	return success;
//}
//
//void globals::close() {
//	SDL_DestroyTexture(background);
//	background = NULL;
//
//	SDL_DestroyTexture(actor);
//	actor = NULL;
//
//	SDL_DestroyWindow(window);
//	window = NULL;
//
//	SDL_DestroyRenderer(renderer);
//	renderer = NULL;
//
//	SDL_Quit();
//}
//
//void globals::KeyDown(SDL_Event event) {
//	switch (event.key.keysym.sym) {
//	case SDLK_LEFT:
//	case SDLK_a:
//		if (vX > 0) {
//			vX = -vX;
//			aX = -aX;
//		}
//		setLast();
//		updateMovement(pX, vX, aX, dt);
//		break;
//
//	case SDLK_RIGHT:
//	case SDLK_d:
//		if (vX < 0) {
//			vX = -vX;
//			aX = -aX;
//		}
//		setLast();
//		updateMovement(pX, vX, aX, dt);
//		break;
//
//		// reenable when you can move "forward" along z-axis
//		//case SDLK_UP:
//		//case SDLK_w: pY--; break;
//
//		// reenable when you can move "forward" along z-axis
//		//case SDLK_DOWN:
//		//case SDLK_s: pY++; break;
//
//	case SDLK_SPACE:
//		if (aY > 0) {
//			aY = -aY;
//		}
//
//		setLast();
//		updateMovement(pY, vY, aY, dt);
//
//		break;
//
//	case SDLK_p:
//		changeRunStatus();
//		break;
//	}
//}
//
//void globals::checkPosition() {
//	if (pY < 700) {
//		if (aY < 0) {
//			aY = -aY;
//		}
//	}
//	if (pY <= 0) {
//		pY = 64;
//	}
//	if (pY > 700) {
//		vY = -400;
//	}
//	if (pX < 0) {
//		pX = 1;
//	}
//	if (pX > SCREEN_WIDTH - 64) {
//		pX = SCREEN_WIDTH - 65;
//	}
//}
//
//void globals::updateMovement(float &pVar, float &vVar, float &aVar, float dt) {
//	vVar = vVar + (aVar * dt);
//	pVar = pVar + (vVar * dt);
//}