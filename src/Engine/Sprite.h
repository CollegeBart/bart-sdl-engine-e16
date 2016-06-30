#pragma once

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"

#include "Engine.h"
#include "Component.h"

class Sprite
	: Component
{
public:
	Sprite();
	Sprite(const char* path, int x, int y);
	Sprite(
		const char* path, int x, int y,	int srcX,
		int srcY, int srcW, int srcH, float scale = 1.0f);
	virtual ~Sprite();

	float GetX() { return x; }
	float GetY() { return y; }

	void SetPosition(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	void SetSrcRect(int x, int y)
	{
		srcRect->x = x;
		srcRect->y = y;
	}

	virtual void Update();
	void Draw();

protected:
	float x, y;

	SDL_Texture* image;
	SDL_Rect* dstRect;
	SDL_Rect* srcRect;

private:
	
	static SDL_Texture* LoadImage(const char* path);
};

