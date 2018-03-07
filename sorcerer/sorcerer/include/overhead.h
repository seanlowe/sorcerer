//#pragma once
//#include "includes.h"
//
//// mean for this to be the overarching "end-all" for the game
//// i.e. everything is descended from this
//class overhead {
//public: GLfloat vertices[9];	// temp value, triangle
//	/* constructor */
//public: overhead();
//
//		/* class methods */
//public: virtual int initsetup();
//public: virtual bool opengl_init();
//public: virtual void beforeShaderSetup();
//public: virtual void setGLattributes();
//		//public: virtual void createshaders();
//public: virtual void keyDown(SDL_Event event);
//public: virtual void renderLoop();
//public: virtual bool SetupBufferObjects();
//public: virtual void changeShape(int i);
//public: virtual void drawPicture(int i);
//public: virtual void bufferFunc(GLfloat array[]);
//public: virtual void close();
//
//		/* setters */
//public: virtual void changeRunState();
//public: virtual void setWindowTitle();
//public: virtual void setPos(float x, float y);
//
//		/* getters */
//public: bool getRunState() const;
//public: int getI() const;
//public: SDL_Window * getWindow() const;
//public: SDL_Renderer * getRenderer() const;
//public: SDL_Texture * getTexture() const;
//public: SDL_Texture * getPlayer() const;
//public: SDL_GLContext getContext() const;
//public: GLuint getShaderProgram() const;
//public: GLuint getVertexShader() const;
//
//		/**************************************************/
//
//protected: bool dead;
//protected: float xx;			// sprite position
//protected: float yy;			// sprite position
//protected: int i = 0;
//
//protected: SDL_Window * window;
//protected: SDL_Renderer * renderer;
//protected: SDL_Surface * background;
//protected: SDL_Surface * actor;
//protected: SDL_Texture * texture;
//protected: SDL_Texture * player;
//protected: SDL_GLContext context;
//
//protected: GLuint *vao = NULL;
//protected: GLuint *vbo = NULL;
//protected: GLint posAttrib = NULL;
//protected: GLint colAttrib = NULL;
//
//protected: GLuint vertexShader;
//protected: GLuint fragmentShader;
//protected: GLuint shaderProgram;
//
//protected: std::vector<GLfloat> positions;
//protected: std::vector<GLfloat> colors;
//
//protected: float camX = 0;
//protected: float camY = 0;
//protected: float camZ = -100;
//
//protected: const GLfloat diamond[12][3] = {
//   { 0.2f,  0.2f,  0.5f }, // Top right
//   { -0.2f,  0.2f,  0.5f }, // Top left
//   { 0.0f,  0.0f,  0.5f }, // Center
//
//   { 0.2f,  0.2f,  0.5f }, // Top right
//   { 0.2f, -0.2f,  0.5f }, // Bottom right 
//   { 0.0f,  0.0f,  0.5f }, // Center
//
//   { -0.2f, -0.2f,  0.5f }, // Bottom left
//   { 0.2f, -0.2f,  0.5f }, // Bottom right 
//   { 0.0f,  0.0f,  0.5f }, // Center
//
//   { -0.2f, -0.2f,  0.5f }, // Bottom left
//   { -0.2f,  0.2f,  0.5f }, // Top left
//   { 0.0f,  0.0f,  0.5f }, // Center
//};
//};