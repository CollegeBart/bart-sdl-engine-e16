#pragma once

#include <map>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

class Resources
{
public:
	Resources();
	Resources(SDL_Renderer* renderer);
	~Resources();

	void SetTexture(const char* path, SDL_Texture* tex)
	{
		resources[path] = tex;
	}

	SDL_Texture* GetTexture(const char* path)
	{
		if (!resources[path])
		{
			resources[path] = LoadImage(path);
		}
		return resources[path];
	}

	SDL_Texture* GetTexture(SDL_Texture* tex)
	{
		for (const auto &pair : resources)
		{
			if (pair.second == tex)
			{
				return pair.second;
			}
		}
		return nullptr;
	}

private:
	SDL_Texture* LoadImage(const char* path);

	SDL_Renderer* renderer;
	std::map<const char*, SDL_Texture*> resources;

};

