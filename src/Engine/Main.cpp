#include "Engine.h"
#include "Component.h"

int main(int argc, char* args[])
{
	gEngine->Init();

	// Créer tous mes objets
	Component* monCompo = new Component();

	int assert = gEngine->Run();

	// Détruire tous mes objets
	delete monCompo;

	return assert;
}
