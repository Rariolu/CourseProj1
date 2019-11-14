#ifndef _SDLWINDOWMANAGER_H
#define _SDLWINDOWMANAGER_H

#include "SDL.h"
#include "glew.h"
#include "Aliases.h"

class SDLWindowManager
{
	public:
		static bool GenerateWindowManager(string windowTitle, float width, float height, SDLWindowManager* sdlwindowmanager);
		static SDLWindowManager* Instance();
		void ClearDisplay(float r, float g, float b, float a);
		float GetScreenHeight();
		float GetScreenWidth();
		void SwapBuffer();

	private:
		SDLWindowManager();
		~SDLWindowManager();
		bool Initialise(string windowTitle, float width, float height);
		static SDLWindowManager* instance;
		float screenHeight;
		float screenWidth;
		SDL_GLContext* openGLContext;
		SDL_Window* sdlWindow;
};

#endif
