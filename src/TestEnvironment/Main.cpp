#include "Engine.h"
#include "Wqt.h"

int main(int argc, char* args[])
{
	gEngine->Init();

	// Créer tous mes objets
	Wqt* monCompo = new Wqt();

	int assert = gEngine->Run();

	// Détruire tous mes objets
	delete monCompo;

	return assert;
}
