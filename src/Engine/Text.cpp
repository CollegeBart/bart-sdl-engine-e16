#include "Text.h"

Text::Text()
{
	font = TTF_OpenFont("emulogic.ttf", 10);
	//color = { 0,0,0 };
}

Text::Text(int x, int y, std::string fontName, std::string text, int taille)
	: text(text)
{
	SDL_Surface* surfaceText;
	SDL_Texture* tex;

	bgColor = { 0x00,0x00,0x00 };

	font = TTF_OpenFont(fontName.c_str(), taille);
	surfaceText = TTF_RenderText_Solid(font, text.c_str(), fgColor);
	tex = SDL_CreateTextureFromSurface(gEngine->GetRenderer(), surfaceText);

	std::stringstream ss;
	ss << fontName << "_" << taille;

	SetTexture(ss.str().c_str(), tex);
	SetPosition(x, y);
	SetSize(surfaceText->w, surfaceText->h);

	SDL_FreeSurface(surfaceText);
}

Text::~Text()
{
	TTF_CloseFont(font);
}
