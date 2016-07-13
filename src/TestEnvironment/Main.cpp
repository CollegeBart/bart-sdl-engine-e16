#include "Engine.h"
#include "Wqt.h"
#include "WqtAnimation.h"
#include <iostream>
#include "List.h"
#include "Text.h"

int main(int argc, char* args[])
{
	gEngine->Init();

	Text* monText = new Text("emulogic.ttf", "Hello World!", 16);

	SpriteInfo wqtInfos[] =
	{
		{ 3.0f, 0.0f, 0.0f, 19.0f, 25.0f, 0, 0, 19, 25 },
		{ 3.0f, 0.0f, 0.0f, 19.0f, 25.0f, 19, 0, 19, 25 },
		LAST_FRAME
	};

	// Cr�er tous mes objets
	//Wqt* monCompo = new Wqt();
	WqtAnimation* wqtAnimation = new WqtAnimation(wqtInfos);
	
	int assert = gEngine->Run();

	// D�truire tous mes objets
	delete wqtAnimation;
	//delete monCompo;
	delete monText;

	return assert;
}
