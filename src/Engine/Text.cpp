#include "Text.h"

Text::Text()
{
	font = TTF_OpenFont("emulogic.ttf", 10);
	//color = { 0,0,0 };
}

Text::Text(int x, int y, std::string fontName, std::string text, int taille)
	: text(text),
	taille(taille),
	fontName(fontName),
	surfaceText(nullptr),
	textTexture(nullptr)
{
	fgColor = { 0xFF, 0xFF, 0xFF };
	surfaceText = new SDL_Surface();

	font = TTF_OpenFont(fontName.c_str(), taille);

	surfaceText = TTF_RenderText_Blended_Wrapped(font, text.c_str(), fgColor, 950);
	textTexture = SDL_CreateTextureFromSurface(gEngine->GetRenderer(), surfaceText);

	std::stringstream ss;
	ss << fontName << "_" << taille;

	this->fontName = ss.str();
	SetTexture(this->fontName.c_str(), textTexture);
	SetPosition(x, y);
	SetSrcRect(0, 0, surfaceText->h, surfaceText->w);
	SetSize(surfaceText->w, surfaceText->h);

	SDL_FreeSurface(surfaceText);
}

void Text::SetBgColor(SDL_Color newColor)
{
	bgColor = newColor;
	surfaceText = TTF_RenderText_Blended_Wrapped(font, text.c_str(), fgColor, 950);	textTexture = SDL_CreateTextureFromSurface(gEngine->GetRenderer(), surfaceText);
	
	std::stringstream ss;
	ss << fontName << "_" << taille;
	
	fontName = ss.str();
	SetTexture(fontName.c_str(), textTexture);
	
	
	SDL_FreeSurface(surfaceText);
}

void Text::SetFgColor(SDL_Color newColor)
{
	fgColor = newColor;
	surfaceText = TTF_RenderText_Blended_Wrapped(font, text.c_str(), fgColor, 950);	textTexture = SDL_CreateTextureFromSurface(gEngine->GetRenderer(), surfaceText);
	
	std::stringstream ss;
	ss << fontName << "_" << taille;
	
	fontName = ss.str();
	SetTexture(fontName.c_str(), textTexture);
	
	SDL_FreeSurface(surfaceText);
}

void Text::SetText(std::string newText)
{
	text = newText;

	surfaceText = TTF_RenderText_Blended_Wrapped(font, text.c_str(), fgColor, 950);	textTexture = SDL_CreateTextureFromSurface(gEngine->GetRenderer(), surfaceText);
	//SetSurfaceAlpha(textTexture, 128);

	std::stringstream ss;
	ss << fontName << "_" << taille;

	fontName = ss.str();
	SetTexture(fontName.c_str(), textTexture);
	SetSrcRect(0, 0, surfaceText->h, surfaceText->w);
	SetSize(surfaceText->w, surfaceText->h);

	SDL_FreeSurface(surfaceText);
}

Text::~Text()
{
	TTF_CloseFont(font);

	if (surfaceText != nullptr)
	{
		SDL_FreeSurface(surfaceText);
	}
}
