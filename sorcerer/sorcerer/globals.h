//#pragma once
//#include <SDL.h>
//#include <iostream>
//#include <sstream>
//
//using namespace std;
//
//class globals {
//public:
//	float aX;
//	float aY;
//	float vX;
//	float vY;
//	float pX;
//	float pY;
//	// variables for ticks for motion
//	float dt;
//	float last;
//
//	globals();
//
//	bool init();
//	bool loadBackground(const char* filename);
//	bool loadActor(const char* filename);
//	void close();
//	void KeyDown(SDL_Event event);
//	void checkPosition();
//	void updateMovement(float &pVar, float &vVar, float &aVar, float dt);
//
//	/* setters */
//	void setScreenDim(int w, int h);
//	void changeRunStatus() { dead = !dead; }
//	void setPos(float x, float y);
//	void setX(float x);
//	void setY(float y);
//	void setDT();
//	void setLast();
//
//	// special case setter
//	void setWindowTitle();
//	/* end setters */
//
//	/* getters */
//	SDL_Window* getWindow()			{ return window;		}
//	SDL_Renderer* getRenderer()		{ return renderer;		}
//	SDL_Texture* getBackground()	{ return background;	}
//	SDL_Texture* getActor()			{ return actor;			}
//
//	bool getRunStatus() { return dead; }
//	float getXPos() { return pX; }
//	float getYPos() { return pY; }
//	/* end getters */
//
//protected:
//	bool dead;
//	int SCREEN_WIDTH = 1200;
//	int SCREEN_HEIGHT = 800;
//	SDL_Window *window = NULL;
//	SDL_Renderer *renderer = NULL;
//	SDL_Texture *background = NULL;
//	SDL_Texture *actor = NULL;
//};