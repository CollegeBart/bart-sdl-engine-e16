#include "Text.h"

Text::Text()
{
	font = TTF_OpenFont("emulogic.ttf", 10);
	//color = { 0,0,0 };
}

Text::Text(std::string fontName, std::string text, int taille)
	: text(text)
{
	SDL_Surface* surfaceText;
	SDL_Texture* tex;

	bgColor = { 0xFF,0xFF,0xFF };
	fgColor = { 0x00,0x00,0x00 };

	font = TTF_OpenFont(fontName.c_str(), taille);
	
	surfaceText = TTF_RenderText(font, text.c_str(), fgColor, bgColor);
	tex = SDL_CreateTextureFromSurface(gEngine->GetRenderer(), surfaceText);

	std::stringstream ss;
	ss << fontName << "_" << taille;

	SetTexture(ss.str().c_str(), tex);

	SDL_FreeSurface(surfaceText);
}

Text::~Text()
{
	TTF_CloseFont(font);
}
