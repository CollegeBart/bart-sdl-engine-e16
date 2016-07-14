#pragma once

#include "Engine.h"
#include "Component.h"
#include "Vector.h"

class Sprite
	: public Component
{
public:
	Sprite();
	Sprite(const char* path);
	Sprite(const char* path, float x, float y);
	Sprite(const char* path, float x, float y, int w, int h);
	Sprite(const char* path, float x, float y, int srcX,
		int srcY, int srcW, int srcH, float scale = 1.0f);

	virtual ~Sprite();

	float GetX() const { return x; }
	float GetY() const { return y; }
	int GetW() const { return dstRect->w; }
	int GetH() const { return dstRect->h; }

	const SDL_Rect* const GetDstRect() const
	{
		return srcRect;
	}

	float GetSrcX() const { return srcX; }
	float GetSrcY() const { return srcY; }
	
	bool GetIsVisible() { return isVisible; }

	void SetPosition(float x, float y) 
	{ 
		this->x = x; 
		this->y = y; 
	}

	void SetSrcPosition(float x, float y)
	{
		srcX = x;
		srcY = y;
	}

	void SetSrcRect(float x, float y, int h, int w)
	{
		if (srcRect == nullptr)
		{
			srcRect = new SDL_Rect();
		}

		srcX = x;
		srcY = y;
		srcRect->x = (int)x;
		srcRect->y = (int)y;
		srcRect->h = h;
		srcRect->w = w;
	}

	void SetDstRect(const SDL_Rect* const dst, float scale = 1.0f)
	{
		SetDstRect(dst->x, dst->y, dst->h, dst->w, scale);
	}

	void SetDstRect(float x, float y, int h, int w, float scale=1.0f)
	{
		if (dstRect == nullptr)
		{
			dstRect = new SDL_Rect();
		}

		this->x = x;
		this->y = y;
		dstRect->x = (int)x;
		dstRect->y = (int)y;
		dstRect->h = (int)(h * scale);
		dstRect->w = (int)(w * scale);
	}

	void SetSize(int w, int h)
	{
		if (dstRect == nullptr)
		{
			dstRect = new SDL_Rect();
		}

		dstRect->w = w;
		dstRect->h = h;
	}

	void SetTexture(const char* path)
	{
		image = gResources->GetTexture(path);
	}

	void SetTexture(const char* path, SDL_Texture* tex)
	{
		std::string s(path);
		std::string s2(".ttf");
		if (gResources->GetTexture(tex))
		{
			image = tex;
		}
		else
		if (s.find(s2) != std::string::npos) 
		{
			gResources->SetTexture(path, tex);
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

	void SetVisible(bool tf) { isVisible = tf; }

	void Move(const Vector* const move)
	{
		x += move->GetX();
		y += move->GetY();
	}

	bool HitTest(Sprite* other);
	

	virtual void Update();
	void Draw();

protected:
	bool isVisible;
	float x, y, srcX, srcY;
	
	SDL_Texture* image;
	SDL_Rect* dstRect;
	SDL_Rect* srcRect;

private:
	bool ContainsRect(SDL_Rect* rect);
	bool ContainsPoint(int x, int y);
};