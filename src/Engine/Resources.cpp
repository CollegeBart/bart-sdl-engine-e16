#include "Resources.h"

Resources::Resources()
	:renderer(nullptr)
{
}

Resources::Resources(SDL_Renderer * renderer)
	:renderer(renderer)
{
}

Resources::~Resources()
{
}

SDL_Texture* Resources::LoadImage(const char* path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path);
	if (!loadedSurface)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
	}
	else
	{
		if (!renderer)
		{
			printf("Renderer null exception \n", SDL_GetError());
		}
		else
		{
			//Create texture from surface pixels
			newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
			if (!newTexture)
			{
				printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
			}
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}

