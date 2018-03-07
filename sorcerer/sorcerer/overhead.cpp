//#include "overhead.h"
//
//using namespace std;
//
//overhead::overhead() {
//	dead = false;
//	xx = 288;
//	yy = 208;
//}
//
//int overhead::initsetup() {
//
//	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//		cout << "Could not Initialize SDL_VIDEO: " << SDL_GetError() << endl;
//		return 1;
//	}
//
//	/* Creation and Checking of Parts */
//	window = SDL_CreateWindow("My SDL Empty Window",
//		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800,
//		SDL_WINDOW_OPENGL);
//	if (window == NULL) {
//		cerr << "Could not create window: " << SDL_GetError() << endl;
//		return 1;
//	}
//
//	setGLattributes();
//
//	// GL Context canNOT be a ptr. SDL_GL_CreateContext won't work.
//	context = SDL_GL_CreateContext(window);
//
//	// sync buffer swap with monitor's vertical refresh (v-sync)
//	SDL_GL_SetSwapInterval(1);
//
//	// initialize GLEW
//	// these functions need to be AFTER you have created the SDL_GLContext. If you
//	// put it before then functions will point to NULL pointers and nothing will initialize
//	glewExperimental = GL_TRUE; // this line is required
//	glewInit();
//
//	renderer = SDL_CreateRenderer(window, -1, 0);
//	if (renderer == NULL) {
//		cerr << "Could not create renderer: " << SDL_GetError() << endl;
//		return 1;
//	}
//
//	background = SDL_LoadBMP("starbackground.bmp");
//	if (background == NULL) {
//		cerr << "Could not set background: " << SDL_GetError() << endl;
//		return 1;
//	}
//
//	actor = SDL_LoadBMP("spaceship.bmp");
//	if (actor == NULL) {
//		cerr << "Could not set actor image: " << SDL_GetError() << endl;
//		return 1;
//	}
//
//	texture = SDL_CreateTextureFromSurface(renderer, background);
//	if (texture == NULL) {
//		cerr << "Could not create texture: " << SDL_GetError() << endl;
//		return 1;
//	}
//	SDL_FreeSurface(background);
//
//	player = SDL_CreateTextureFromSurface(renderer, actor);
//	if (player == NULL) {
//		cerr << "Could not create texture: " << SDL_GetError() << endl;
//		return 1;
//	}
//	SDL_FreeSurface(actor);
//
//	if (!opengl_init()) {
//		return 1;
//	}
//
//	return 0;
//}
//
//bool overhead::opengl_init() {
//	glClearColor(0, 0, 0, 0);
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
//	return true;
//}
//
//void overhead::beforeShaderSetup() {
//	// enable the vertex arribute array
//	glGenVertexArrays(1, &vao);
//	glBindVertexArray(vao);  // bind vertex array
//
//							 // create "vertex buffer object"
//	glGenBuffers(1, &vbo);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo); // make 'vbo' the active object
//	glBufferData(GL_ARRAY_BUFFER, sizeof(diamond), diamond, GL_DYNAMIC_DRAW); // copy vertex data to the active buffer
//
//// tags for the 4th param of glBufferData:
////
////	GL_STATIC_DRAW		= vertex data uploaded once and used many times (the world)
////  GL_DYNAMIC_DRAW		= vertex data created once, changed from time to time, but drawn a bunch
////  GL_STREAM_DRAW		= vertex data uploaded once and drawn once
//}
//
//void overhead::setGLattributes() {
//	// SDL GL set attributes
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
//	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
//
//	// sets at least 5 bits for RGB color info
//	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
//	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
//	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
//
//	// sets a 16 bit (2 byte) color depth
//	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
//
//	// 1 turns on double buffer, 0 turns it off
//	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
//
//	// enable multisampling for antialiased effect
//	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
//	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
//
//	// enable "z depth"
//	// objects closest to viewport are "in front" of objects further away
//	glEnable(GL_DEPTH_TEST);
//	//glDepthFunc(GL_LESS);
//	glDepthFunc(GL_LEQUAL);
//}
//
////void overhead::createshaders() {
//	// create vertex shader */
//	//vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	//glShaderSource(vertexShader, 1, &vertexSource, NULL);
//	//glCompileShader(vertexShader);
//	//
//	//GLint statusVertex;
//	//glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &statusVertex);
//	//if (statusVertex != true) {
//	//	cerr << "Could not compile shaders" << endl;
//	//}
//	// end vertex shader creation and check */
//	//
//	//
//	//
//	// begin fragment shader creation */
//	//fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	//glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
//	//glCompileShader(fragmentShader);
//	//
//	//GLint statusFragment;
//	//glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &statusFragment);
//	//if (statusFragment != true) {
//	//	cerr << "Could not compile fragment shaders" << endl;
//	//}
//	// end fragment shader creation and check */
//	//
//	//
//	//
//	// create a ' program ' out of the various shader pieces */
//	//shaderProgram = glCreateProgram();
//	//glAttachShader(shaderProgram, vertexShader);
//	//glAttachShader(shaderProgram, fragmentShader);*/
//	//glBindFragDataLocation(shaderProgram, 0, "outColor");
//	//
//	// use ' glDrawBuffers' when rendering to multiple buffers, because
//	// only the first output will be enabled by default.
//	//
//	//glLinkProgram(shaderProgram);
//	//glUseProgram(shaderProgram);
//	// only one shader can be active at a time in a program
//	// end shader 'program' creation */
//	//
//	//
//	//posAttrib = glGetAttribLocation(shaderProgram, "position");
//	//colAttrib = glGetAttribLocation(shaderProgram, "inColor");
//	//glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
//	//glEnableVertexAttribArray(posAttrib);
//	//glVertexAttribPointer(colAttrib, 4, GL_FLOAT, GL_FALSE, 0, 0);
//	//glEnableVertexAttribArray(colAttrib);
////}
//
//void overhead::keyDown(SDL_Event event) {
//	switch (event.key.keysym.sym) {
//	case SDLK_LEFT:
//	case SDLK_a: xx--; break;
//
//	case SDLK_RIGHT:
//	case SDLK_d: xx++; break;
//
//	case SDLK_UP:
//	case SDLK_w: yy--; break;
//
//	case SDLK_DOWN:
//	case SDLK_s: yy++; break;
//
//	case SDLK_r:
//		changeShape(1); // rectangle
//		break;
//	case SDLK_t:
//		changeShape(0); // triangle
//		break;
//	case SDLK_k:
//		camX++;
//		break;
//	case SDLK_l:
//		camX--;
//		break;
//	case SDLK_v:
//		camY++;
//		break;
//	case SDLK_b:
//		camY--;
//		break;
//	case SDLK_n:
//		camZ++;
//		break;
//	case SDLK_m:
//		camZ--;
//		break;
//	case SDLK_p:
//		changeRunState();
//		break;
//	}
//}
//
//void overhead::renderLoop() {
//	//SDL_Rect dstrect = { xx, yy, 64, 64 };
//
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glDrawArrays(GL_QUADS, 0, 3);	// triangle
//	SDL_GL_SwapWindow(getWindow());
//
//
//	//glClearColor(0.0, 0.0, 0.0, 0.0);
//	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	//glLoadIdentity();
//	//drawPicture(getI());
//	/*glTranslatef(-1.5f, 0.0f, -6.0f);
//	glBegin(GL_TRIANGLES);
//	  glVertex3f(0.0f, 1.0f, 0.0f);
//	  glVertex3f(-1.0f, -1.0f, 0.0f);
//	  glVertex3f(1.0f, -1.0f, 0.0f);
//	glEnd();
//	glTranslatef(3.0f, 0.0f, 0.0f);
//	glBegin(GL_QUADS);
//	  glVertex3f(-1.0f, 1.0f, 0.0f);
//	  glVertex3f(1.0f, 1.0f, 0.0f);
//	  glVertex3f(1.0f, -1.0f, 0.0f);
//	  glVertex3f(-1.0f, -1.0f, 0.0f);
//	glEnd();*/
//
//	//SDL_GL_SwapWindow(getWindow());
//}
//
//bool overhead::SetupBufferObjects() {
//	positions = ReadFile("positions.txt");
//	colors = ReadFile("colors.txt");
//
//	// Generate and assign two Vertex Buffer Objects to our handle
//	glGenBuffers(2, vbo);
//
//	// Generate and assign a Vertex Array Object to our handle
//	glGenVertexArrays(1, vao);
//
//	// Bind our Vertex Array Object as the current used object
//	glBindVertexArray(vao[0]);
//
//	// Colors
//	// =======================
//	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
//
//	// Copy the vertex data from diamond to our buffer
//	glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(GLfloat), &colors[0], GL_STATIC_DRAW);
//
//	// Specify that our coordinate data is going into attribute index 0, and contains three floats per vertex
//	glVertexAttribPointer(colorAttributeIndex, 4, GL_FLOAT, GL_FALSE, 0, 0);
//
//	// Positions
//	// ===================
//	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
//
//	// Copy the vertex data from diamond to our buffer
//	glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(GLfloat), &positions[0], GL_STATIC_DRAW);
//
//	// Specify that our coordinate data is going into attribute index 0, and contains three floats per vertex
//	glVertexAttribPointer(positionAttributeIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);
//
//	// Enable our attributes within the current VAO
//	glEnableVertexAttribArray(positionAttributeIndex);
//	glEnableVertexAttribArray(colorAttributeIndex);
//
//	// Set up shader 
//	// ===================
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(vao[0]);
//
//	return true;
//}
//
//void overhead::changeShape(int i) {
//	switch (i) {
//	case 0:
//		GLfloat verticesTri[9];
//		// triangle
//		verticesTri[0] = 0.0f;
//		verticesTri[1] = 0.5f;
//		verticesTri[2] = 0.0f;
//
//		verticesTri[3] = 0.5f;
//		verticesTri[4] = -0.5f;
//		verticesTri[5] = 0.0f;
//
//		verticesTri[6] = -0.5f;
//		verticesTri[7] = -0.5f;
//		verticesTri[8] = 0.0f;
//		bufferFunc(verticesTri);
//		break;
//	case 1:
//		GLfloat verticesRect[12];
//		// rectangle
//		// renders points in clockwise order
//		verticesRect[0] = 0.5f;		// x
//		verticesRect[1] = 0.5f;		// y
//		verticesRect[2] = 0.0f;		// z
//
//		verticesRect[3] = 0.5f;
//		verticesRect[4] = -0.5f;
//		verticesRect[5] = 0.0f;
//
//		verticesRect[6] = -0.5f;
//		verticesRect[7] = -0.5f;
//		verticesRect[8] = 0.0f;
//
//		verticesRect[9] = -0.5f;
//		verticesRect[10] = 0.5f;
//		verticesRect[11] = 0.0f;
//		bufferFunc(verticesRect);
//		break;
//	default:
//		break;
//	}
//}
//
//void overhead::drawPicture(int i) {
//	switch (i) {
//	case 0:
//		glDrawArrays(GL_TRIANGLES, 0, 3);	// triangle
//		break;
//	case 1:
//		glDrawArrays(GL_QUADS, 0, 4);		// rectangle
//		break;
//	default:
//		break;
//	}
//}
//
//void overhead::bufferFunc(GLfloat verticesX[]) {
//	glBufferSubData(GL_ARRAY_BUFFER, posAttrib, sizeof(verticesX), verticesX); // update vertex data to the active buffer
//}
//
//void overhead::close() {
//
//	SDL_DestroyTexture(texture);
//	SDL_DestroyTexture(player);
//	SDL_DestroyRenderer(renderer);
//
//	glDeleteBuffers(1, &vbo);
//	glDeleteVertexArrays(1, &vao);
//
//	SDL_GL_DeleteContext(context);
//	SDL_DestroyWindow(window);
//
//	SDL_Quit();
//}
//
//
///* setters */
//void overhead::changeRunState() {
//	dead = !dead;
//}
//
//void overhead::setWindowTitle() {
//	/* set window title to cursor's XY coordinates */
//	stringstream ss;
//	ss << "X: " << xx << " Y: " << yy;
//	SDL_SetWindowTitle(getWindow(), ss.str().c_str());
//}
//
//void overhead::setPos(float x, float y) {
//	xx = x;
//	yy = y;
//}
//
//
///* getters */
//bool overhead::getRunState() const {
//	return dead;
//}
//
//int overhead::getI() const {
//	return i;
//}
//
//SDL_Window* overhead::getWindow() const {
//	return window;
//}
//
//SDL_Renderer* overhead::getRenderer() const {
//	return renderer;
//}
//
//SDL_Texture* overhead::getTexture() const {
//	return texture;
//}
//
//SDL_Texture* overhead::getPlayer() const {
//	return player;
//}
//
//SDL_GLContext overhead::getContext() const {
//	return context;
//}
//
//GLuint overhead::getShaderProgram() const {
//	return shaderProgram;
//}
//
//GLuint overhead::getVertexShader() const {
//	return vertexShader;
//}
