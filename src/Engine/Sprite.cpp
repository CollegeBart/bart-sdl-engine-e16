#include "Sprite.h"

Sprite::Sprite()
	: image(nullptr)
	, dstRect()
	, srcRect()
	, x(0), y(0)
{ 
}

Sprite::Sprite(const char * path)
	: dstRect(nullptr)
	, srcRect(nullptr)
{
	srcRect = new SDL_Rect();
	dstRect = new SDL_Rect();
	image = gResources->GetTexture(path);
}

Sprite::Sprite(const char* path, float x, float y)
	: dstRect(nullptr)
	, srcRect(nullptr)
	, x(x), y(y)
{
	image = gResources->GetTexture(path);
}

Sprite::Sprite(const char* path, float x, float y, int w, int h)
	: dstRect(nullptr)
	, srcRect(nullptr)
	, x(x), y(y)
{
	image = gResources->GetTexture(path);

	srcRect = new SDL_Rect();
	srcRect->x = 0;
	srcRect->y = 0;
	srcRect->w = w;
	srcRect->h = h;

	dstRect = new SDL_Rect();
	dstRect->x = x;
	dstRect->y = y;
	dstRect->w = w;
	dstRect->h = h;
}

Sprite::Sprite(const char * path, float x, float y, int srcX, int srcY, int srcW, int srcH, float scale)
	: dstRect()
	, srcRect()
	, x(x), y(y)
{
	image = gResources->GetTexture(path);

	srcRect = new SDL_Rect();
	srcRect->x = srcX;
	srcRect->y = srcY;
	srcRect->w = srcW;
	srcRect->h = srcH;

	dstRect = new SDL_Rect();
	dstRect->x = x;
	dstRect->y = y;
	dstRect->h = srcH * scale;
	dstRect->w = srcW * scale;
}

Sprite::Sprite(const char* path, float x, float y, int srcX, int srcY, int srcW, int srcH, float scaleX, float scaleY)
	: dstRect()
	, srcRect()
	, x(x), y(y)

{
	image = gResources->GetTexture(path);

	srcRect = new SDL_Rect();
	srcRect->x = srcX;
	srcRect->y = srcY;
	srcRect->w = srcW;
	srcRect->h = srcH;

	dstRect = new SDL_Rect();
	dstRect->x = x;
	dstRect->y = y;
	dstRect->h = srcH * scaleX;
	dstRect->w = srcW * scaleY;
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(image);
	image = NULL;
	delete srcRect;
	delete dstRect;
}

void Sprite::Update()
{
	
}

void Sprite::Draw()
{
	if (image != nullptr && gEngine->GetRenderer() != nullptr)
	{
		if (dstRect != nullptr)
		{
			dstRect->x = x;
			dstRect->y = y;
		}

		//Render texture to screen
		SDL_RenderCopy(gEngine->GetRenderer(), image, srcRect, dstRect);
	}
}
