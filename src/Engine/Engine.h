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
#define gResources gEngine->GetResources()
#define gTimer gEngine->GetTimer()
//#define gTimer gEngine->GetTimer()

#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>
#include "Timer.h"

#include "SDL.h"
#include "SDL_ttf.h"

#include "Utils.h"
#include "Input.h"
#include "Component.h"
#include "Resources.h"

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

	Resources* const GetResources() const
	{
		return resources;
	}

	Timer* const GetTimer() const
	{
		return timer;
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
		// Generate a number between 0 (inclusive) and number_of_possibility (exclusive).
		int NumberGenerated = rand() % number_of_possibility;

		return NumberGenerated;
	}
	
	void Init();
	void Init(char* title, int width, int height);
	void Start();
	int Run();
	void Stop();
	float deltaTime;

private:
	void Update();
	void Draw();

	float DeltaTime()
	{
		return timer->GetDeltaTime();
	}

	Uint32 Callback(Uint32 interval, void* param) 
	{
		//Print callback message
		printf("Callback called back with message: %s\n", (char*)param);

		return 0;
	}
	
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
	Resources* resources;
	Timer* timer;

};