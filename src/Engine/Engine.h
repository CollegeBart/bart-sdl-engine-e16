#pragma once

#define DEFAULT_SCREEN_WIDTH 800
#define DEFAULT_SCREEN_HEIGHT 600
enum ResolutionSide
{
	WIDTH,
	HEIGHT,
	SIZE
};

#define DEFAULT_TITLE "SDL"

#define gEngine Engine::GetInstance()

#include <iostream>
#include <vector>
#include <math.h>

#include "SDL.h"

#include "Utils.h"
#include "Component.h"

class Engine
{
#pragma region SINGLETON
public:
	static Engine* GetInstance()
	{
		if (!instance)
		{
			instance = new Engine();
		}
		return instance;
	}

	static void Kill()
	{
		delete instance;
		instance = nullptr;
	}

private:
	Engine();
	~Engine();

	static Engine* instance;
#pragma endregion
public:

	SDL_Renderer* const GetRenderer() const
	{
		return renderer;
	}

	void const GetScreenRes(int res[SIZE])
	{		
		res[WIDTH] = resolution[WIDTH];
		res[HEIGHT] = resolution[HEIGHT];
	}

	void SetScreenRes(int w, int h, int fullScreen)
	{				
		resolution[WIDTH] = w;
		resolution[HEIGHT] = h;
		SDL_SetWindowSize(window, w, h);
		SDL_SetWindowFullscreen(window, fullScreen);
	}

	void Init();
	void Init(char* title, int width, int height);
	void Start();
	int Run();
	void Stop();

private:
	void Update();
	void Draw();
	
	// States
	bool isRunning;
	bool isPaused;
	SDL_Event event;

	// Rendering
	SDL_Window* window;
	SDL_Renderer* renderer;
	int resolution[SIZE];

};