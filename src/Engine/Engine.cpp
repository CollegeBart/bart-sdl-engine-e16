#include "Engine.h"

// Redéclaration statique
Engine* Engine::instance = nullptr;

Engine::Engine()
	: isRunning(false)
	, isPaused(false)
	, window(nullptr)
	, renderer(nullptr)
	, resources(nullptr)

{
	// Used for random
	std::srand(time(0));

	resolution[WIDTH] = DEFAULT_SCREEN_WIDTH;
	resolution[HEIGHT] = DEFAULT_SCREEN_HEIGHT;

	//Our test callback function
	Uint32 Callback(Uint32 interval, void* param);
}

Engine::~Engine()
{
	Stop();

	delete input;
	delete resources;
	delete timer;

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
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER) > 0)
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
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			}
			else
			{
				//Initialize SDL_mixer
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
				}

				if (TTF_Init() < 0)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
				}

				SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00); 

				input = new Input();
				resources = new Resources(renderer);
				timer = new Timer();
			}
		}
	}
}

void Engine::Start()
{
	isRunning = true;
	isPaused = false;

	timer->Start();
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
			input->Poll(event);

			switch (event.type)
			{
			case SDL_QUIT:
				Kill();
				return 0;
			default:
				break;
			}

			if (input->IsKeyReleased(SDL_SCANCODE_ESCAPE))
			{
				Kill();
				return 0;
			}
			
			timer->Tick();
		}

		//For when you stop scrolling
		input->ResetMouseScroll();

		if (!isPaused)
		{
			DeltaTime();
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

	gTimer->Stop();
	gTimer->Reset();
}

void Engine::Update()
{
	std::vector<Component*>::iterator iter = Component::components.begin();		
	while (iter != Component::components.end())	
	{		
		if ((*iter)->GetIsActive())
		{
			(*iter)->Update();
		}
		iter++;									
	}
}

void Engine::Draw()
{
	//Clear screen
	SDL_RenderClear(renderer);

	FOREACH_COMPONENT(Draw());

	//Update screen
	SDL_RenderPresent(renderer);
}
