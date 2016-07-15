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

	void SetBgColor(SDL_Color newColor);

	void SetFgColor(SDL_Color newColor);

	void SetText(std::string newText);
	
private:
	SDL_Color bgColor;
	SDL_Color fgColor;

	TTF_Font* font;
	std::string text;
	std::string fontName;
	int taille;
};


