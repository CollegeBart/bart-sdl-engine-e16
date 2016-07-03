#include "Sprite.h"

Sprite::Sprite()
	: image(nullptr)
	, dstRect()
	, srcRect()
	, x(0), y(0)
{ 
}

Sprite::Sprite(const char* path, int x, int y)
	: dstRect(nullptr)
	, srcRect(nullptr)
	, x(x), y(y)
{
	srcRect = new SDL_Rect();
	dstRect = new SDL_Rect();
	image = LoadImage(path);
}

Sprite::Sprite(const char * path, int x, int y, int srcX, int srcY, int srcW, int srcH, float scale)
	: dstRect()
	, srcRect()
	, x(x), y(y)

{
	image = LoadImage(path);

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

Sprite::Sprite(const char* path, int x, int y, int srcX, int srcY, int srcW, int srcH, float scaleX, float scaleY)
	: dstRect()
	, srcRect()
	, x(x), y(y)

{
	image = LoadImage(path);

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
	std::cout << "Sprite::Update" << std::endl;
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

SDL_Texture* Sprite::LoadImage(const char* path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gEngine->GetRenderer(), loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}
