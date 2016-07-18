#include "Text.h"

Text::Text()
{
	font = TTF_OpenFont("emulogic.ttf", 10);
	//color = { 0,0,0 };
}

Text::Text(int x, int y, std::string fontName, std::string text, int taille)
	: text(text),
	taille(taille),
	fontName(fontName)
{
	SDL_Surface* surfaceText;
	SDL_Texture* tex;

	bgColor = { 0x00,0x00,0x00 };

	font = TTF_OpenFont(fontName.c_str(), taille);
	surfaceText = TTF_RenderText_Shaded(font, text.c_str(), fgColor, bgColor);
	tex = SDL_CreateTextureFromSurface(gEngine->GetRenderer(), surfaceText);

	std::stringstream ss;
	ss << fontName << "_" << taille;

	this->fontName = ss.str();
	SetTexture(this->fontName.c_str(), tex);
	SetPosition(x, y);
	SetSize(surfaceText->w, surfaceText->h);

	SDL_FreeSurface(surfaceText);
}

void Text::SetBgColor(SDL_Color newColor)
{
	bgColor = newColor;

	SDL_Surface * surfaceText = TTF_RenderText_Shaded(font, text.c_str(), fgColor, bgColor);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(gEngine->GetRenderer(), surfaceText);

	std::stringstream ss;
	ss << fontName << "_" << taille;

	fontName = ss.str();
	SetTexture(fontName.c_str(), tex);

	SDL_FreeSurface(surfaceText);
}

void Text::SetFgColor(SDL_Color newColor)
{
	fgColor = newColor;

	SDL_Surface * surfaceText = TTF_RenderText_Shaded(font, text.c_str(), fgColor, bgColor);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(gEngine->GetRenderer(), surfaceText);

	std::stringstream ss;
	ss << fontName << "_" << taille;

	fontName = ss.str();
	SetTexture(fontName.c_str(), tex);

	SDL_FreeSurface(surfaceText);
}

void Text::SetText(std::string newText)
{
	text = newText;

	SDL_Surface * surfaceText = TTF_RenderText_Shaded(font, text.c_str(), fgColor, bgColor);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(gEngine->GetRenderer(), surfaceText);

	std::stringstream ss;
	ss << fontName << "_" << taille;

	fontName = ss.str();
	SetTexture(fontName.c_str(), tex);

	SDL_FreeSurface(surfaceText);
}

Text::~Text()
{
	TTF_CloseFont(font);
}
