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
#define gInput gEngine->GetInput()

#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>

#include "SDL.h"

#include "Utils.h"
#include "Input.h"
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

	Input* const GetInput() const
	{
		return input;
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

	int GenerateRandomNumber(const int number_of_possibility)
	{
		// Used for random
		std::srand(time(0));

		// Generate a number between 0 (inclusive) and number_of_possibility (exclusive).
		int NumberGenerated = rand() % number_of_possibility;

		return NumberGenerated;
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

	// Inputs
	Input* input;

};