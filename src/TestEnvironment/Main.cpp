#include "Engine.h"
#include "Wqt.h"
#include "WqtAnimation.h"
#include <iostream>
#include "List.h"

int main(int argc, char* args[])
{
	gEngine->Init();

	SpriteInfo wqtInfos[] =
	{
		{ 3.0f, 0.0f, 0.0f, 19.0f, 25.0f, 0, 0, 19, 25 },
		{ 3.0f, 0.0f, 0.0f, 19.0f, 25.0f, 19, 0, 19, 25 },
		LAST_FRAME
	};

	// Créer tous mes objets
	//Wqt* monCompo = new Wqt();
	WqtAnimation* wqtAnimation = new WqtAnimation(wqtInfos);
	
	int assert = gEngine->Run();

	// Détruire tous mes objets
	delete wqtAnimation;
	//delete monCompo;

	return assert;
}
