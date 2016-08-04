#include "Sprite.h"

Sprite::Sprite()
	: image(nullptr)
	, dstRect()
	, srcRect()
	, isVisible(true)
	, x(0), y(0), srcX(0), srcY(0)
{ 
	srcRect = new SDL_Rect();
	dstRect = new SDL_Rect();
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
	, x((float)x), y((float)y), srcX(srcX), srcY(srcY)
	, isVisible(true)
	, xScale(scale)
	, yScale(scale)
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

void Sprite::StartFlashing(float flashDelay, float timeInvisible)
{
	this->flashDelay = flashDelay;
	this->timeInvisible = timeInvisible;
	isFlashing = true;
}

bool Sprite::isTimeToFlash()
{
	if (flashTimer > flashDelay)
		return true;
	return false;
}

void Sprite::ToggleVisibility()
{
	if (GetIsVisible())
		SetVisible(false);
	else
		SetVisible(true);
}

bool Sprite::HitTest(Sprite * other)
{
	return ContainsRect(other->dstRect) || other->ContainsRect(dstRect);
}

bool Sprite::HitTestBelow(Sprite* other) 
{
	return other->ContainsPoint(this->x, this->y + this->GetH()) ||
		other->ContainsPoint(this->x + this->GetW(), this->y + this->GetH()) ||
		other->ContainsPoint(this->x + this->GetW() / 2, this->y + this->GetH());
}

void Sprite::SetImage(const char * path, const int srcW, const int srcH)
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
	dstRect->h = (int)(srcH * xScale);
	dstRect->w = (int)(srcW * yScale);
}

bool Sprite::ContainsRect(SDL_Rect* rect)
{
	return	ContainsPoint(rect->x, rect->y) ||
			ContainsPoint(rect->x + rect->w, rect->y) ||
			ContainsPoint(rect->x + rect->w, rect->y + rect->h) ||
			ContainsPoint(rect->x, rect->y + rect->h);
}

bool Sprite::ContainsPoint(int x, int y)
{
	return	x >= this->x &&
			x <= (this->x + dstRect->w) &&
			y >= this->y &&
			y <= (this->y + dstRect->h);
}

void Sprite::Update()
{
	if (isFlashing)
	{
		flashTimer += gTimer->GetDeltaTime();
		if (isTimeToFlash())
		{
			ToggleVisibility();
			flashTimer = 0;
		}
	}
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

void Sprite::ScaleX(float scale)
{
	this->dstRect->w = (int)(this->dstRect->w * scale);
}

void Sprite::ScaleY(float scale)
{
	this->dstRect->h = (int)(this->dstRect->h * scale);
}
