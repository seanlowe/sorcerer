#pragma once
#include "overhead.h"
#include "shader.h"

// mean for this to be where main grabs the game
// and sets up windows and all that jazz
class head : public overhead {
public: head();
public: bool inithead();
public: void keyDown(SDL_Event event);
public: void camera();
public: void close();
	/* helpers */
public: void SetMatrix(const glm::mat4 mat);

protected: shader headShader;
};

