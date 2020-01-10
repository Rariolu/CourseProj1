#include "SDLWindowManager.h"

SDLWindowManager* SDLWindowManager::instance = nullptr;

SDLWindowManager::SDLWindowManager()
{
	screenHeight = screenWidth = 0; 
	openGLContext = 0;
	sdlWindow = 0;
}

SDLWindowManager::~SDLWindowManager()
{
	SDL_GL_DeleteContext(openGLContext); // delete context
	SDL_DestroyWindow(sdlWindow); // detete window (make sure to delete the context and the window in the opposite order of creation in initDisplay())
	SDL_Quit();
}

bool SDLWindowManager::GenerateWindowManager(string windowTitle, float width, float height, SDLWindowManager* sdlWindowManager)
{
	sdlWindowManager =  new SDLWindowManager();
	instance = sdlWindowManager;
	return sdlWindowManager->Initialise(windowTitle, width, height);
}

SDLWindowManager* SDLWindowManager::Instance()
{
	return instance;
}

void SDLWindowManager::ClearDisplay(float r, float g, float b, float a)
{
	//Clear the display so that only the given RGBA colour is displayed.
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

float SDLWindowManager::GetScreenHeight()
{
	return screenHeight;
}

float SDLWindowManager::GetScreenWidth()
{
	return screenWidth;
}

void SDLWindowManager::SwapBuffer()
{
	SDL_GL_SwapWindow(sdlWindow);
}

bool SDLWindowManager::Initialise(string windowTitle, float width, float height)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	screenHeight = height;
	screenWidth = width;

	const int bufferSize = 8;

	//Set RGB buffer sizes
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, bufferSize);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, bufferSize);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, bufferSize);

	//Create a double buffer (two RGB buffers that are alternated between).
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	sdlWindow = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)width, (int)height, SDL_WINDOW_OPENGL);
	if (!sdlWindow)
	{
		Log("SDL Window was not created.");
		return false;
	}

	openGLContext = new SDL_GLContext(SDL_GL_CreateContext(sdlWindow));
	if (!(*openGLContext))
	{
		Log("OpenGL context was not created.");
		return false;
	}

	GLenum glState = glewInit();
	if (glState != GLEW_OK)
	{
		Log("OpenGL failed to initialise.");
		return false;
	}

	glClearColor(0.0f, 1.0f, 1.0f, 1.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	return true;
}