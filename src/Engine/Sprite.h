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
	Sprite(const char* path);
	Sprite(const char* path, int x, int y);
	Sprite(const char* path, int x, int y, int w, int h);

	Sprite(const char* path, int x, int y, int srcX,
		int srcY, int srcW, int srcH, float scale = 1.0f);

	Sprite(const char* path, int x, int y,	int srcX,
		int srcY, int srcW, int srcH, float scaleX, float scaleY);

	virtual ~Sprite();

	float GetX() { return x; }
	float GetY() { return y; }

	void SetPosition(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	void SetSrcRect(int x, int y, int h, int w)
	{
		srcRect->x = x;
		srcRect->y = y;
		srcRect->h = h;
		srcRect->w = w;
	}

	void SetDstRect(int x, int y, int h, int w, float scaleY, float scaleX)
	{
		this->x = x;
		this->y = y;
		dstRect->x = x;
		dstRect->y = y;
		dstRect->h = h * scaleY;
		dstRect->w = w * scaleX;
	}

	virtual void Update();
	void Draw();
	void ReloadImage(const char* path);

protected:
	float x, y;

	SDL_Texture* image;
	SDL_Rect* dstRect;
	SDL_Rect* srcRect;

private:
	
	static SDL_Texture* LoadImage(const char* path);
};

