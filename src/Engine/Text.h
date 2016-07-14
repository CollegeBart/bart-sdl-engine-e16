#pragma once
#include "Sprite.h"
#include <sstream>
class Text :
	public Sprite
{
public:
	Text();
	Text(int x, int y, std::string fontName, std::string text, int taille);
	~Text();

private:

	SDL_Color bgColor;
	SDL_Color fgColor;

	TTF_Font* font;
	std::string text;
};

