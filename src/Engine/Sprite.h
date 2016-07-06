#pragma once

#include "Engine.h"
#include "Component.h"

class Sprite
	: Component
{
public:
	Sprite();
	Sprite(const char* path);
	Sprite(const char* path, float x, float y);
	Sprite(const char* path, float x, float y, int w, int h);

	Sprite(const char* path, float x, float y, int srcX,
		int srcY, int srcW, int srcH, float scale = 1.0f);

	Sprite(const char* path, float x, float y,	int srcX,
		int srcY, int srcW, int srcH, float scaleX, float scaleY);

	virtual ~Sprite();

	float GetX() { return x; }
	float GetY() { return y; }

	void SetTexture(const char* path)
	{
		image = gResources->GetTexture(path);
	}

	void SetTexture(SDL_Texture* tex)
	{
		SetTexture("", tex);
	}

	void SetTexture(const char* path, SDL_Texture* tex)
	{
		if (gResources->GetTexture(tex))
		{
			image = tex;
		}
		else
		if (strcmp(path, ""))
		{
			image = gResources->GetTexture(path);
		}
		else
		{
			printf("Path is invalid: %s! SDL Error: %s\n", path, SDL_GetError());
		}
	}

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

	void SetDstRect(float x, float y, int h, int w, float scaleY, float scaleX)
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
	

protected:
	float x, y;

	SDL_Texture* image;
	SDL_Rect* dstRect;
	SDL_Rect* srcRect;
};

