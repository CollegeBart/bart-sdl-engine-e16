#include "Engine.h"

// Redéclaration statique
Engine* Engine::instance = nullptr;

Engine::Engine()
	: isRunning(false)
	, isPaused(false)
	, window(nullptr)
	, screen(nullptr)
{
	memset(keys, 0, sizeof(bool) * SDL_NUM_SCANCODES);
	memset(lastKeys, 0, sizeof(bool) * SDL_NUM_SCANCODES);
}

Engine::~Engine()
{
	Stop();

	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Engine::Init()
{
	Init(DEFAULT_TITLE, DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);
}

void Engine::Init(char * title, int width, int height)
{
	// Initialisation
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow(
			title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width, height, SDL_WINDOW_SHOWN);

		if (window == nullptr)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			screen = SDL_GetWindowSurface(window);
		}
	}
}

void Engine::Start()
{
	isRunning = true;
	isPaused = false;
}

int Engine::Run()
{
	Start();
	
	// Boucle de jeu
	while (isRunning)
	{
		// Pompe a message
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				keys[event.key.keysym.scancode] = true;
				break;
			case SDL_KEYUP:
				keys[event.key.keysym.scancode] = false;
				break;
			case SDL_QUIT:
				Kill();
				return 0;
			default:
				break;
			}
		}

		if (keys[SDL_SCANCODE_ESCAPE])
		{
			Kill();
		}

		if (!isPaused)
		{
			Update();
			Draw();
		}

		SDL_UpdateWindowSurface(window);
	}

	return 0;
}

void Engine::Stop()
{
	isPaused = true;
}

void Engine::Update()
{
	FOREACH_COMPONENT(Update());
}

void Engine::Draw()
{
	FOREACH_COMPONENT(Draw());
}
