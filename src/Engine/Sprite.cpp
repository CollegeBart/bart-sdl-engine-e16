#include "Sprite.h"

Sprite::Sprite()
	: image(nullptr)
	, dstRect()
	, srcRect()
	, x(0), y(0), srcX(0), srcY(0)
{ 
}

Sprite::Sprite(const char * path)
	: dstRect(nullptr)
	, srcRect(nullptr)
	, isVisible(true)
{
	srcRect = new SDL_Rect();
	dstRect = new SDL_Rect();
	image = gResources->GetTexture(path);
}

Sprite::Sprite(const char* path, float x, float y)
	: dstRect(nullptr)
	, srcRect(nullptr)
	, x(x), y(y), srcX(0), srcY(0)
	, isVisible(true)
{
	image = gResources->GetTexture(path);
}

Sprite::Sprite(const char* path, float x, float y, int w, int h)
	: dstRect(nullptr)
	, srcRect(nullptr)
	, x(x), y(y), srcX(0), srcY(0)
	, isVisible(true)
{
	image = gResources->GetTexture(path);

	srcRect = new SDL_Rect();
	srcRect->x = 0;
	srcRect->y = 0;
	srcRect->w = w;
	srcRect->h = h;

	dstRect = new SDL_Rect();
	dstRect->x = (int)x;
	dstRect->y = (int)y;
	dstRect->w = w;
	dstRect->h = h;
}

Sprite::Sprite(const char * path, float x, float y, int srcX, int srcY, int srcW, int srcH, float scale)
	: dstRect()
	, srcRect()
	, x(x), y(y), srcX(srcX), srcY(srcY)
	, isVisible(true)
{
	image = gResources->GetTexture(path);

	srcRect = new SDL_Rect();
	srcRect->x = srcX;
	srcRect->y = srcY;
	srcRect->w = srcW;
	srcRect->h = srcH;

	dstRect = new SDL_Rect();
	dstRect->x = (int)x;
	dstRect->y = (int)y;
	dstRect->h = (int)(srcH * scale);
	dstRect->w = (int)(srcW * scale);
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
	if (isVisible)
	{
		if (image != nullptr && gEngine->GetRenderer() != nullptr)
		{
			if (dstRect != nullptr)
			{
				dstRect->x = (int)x;
				dstRect->y = (int)y;
			}

			if (srcRect != nullptr)
			{
				srcRect->x = (int)srcX;
				srcRect->y = (int)srcY;
			}

			//Render texture to screen
			SDL_RenderCopy(gEngine->GetRenderer(), image, srcRect, dstRect);
		}
	}
}
