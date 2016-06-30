#include "Engine.h"
#include "Component.h"

int main(int argc, char* args[])
{
	gEngine->Init();

	// Cr�er tous mes objets
	Component* monCompo = new Component();

	int assert = gEngine->Run();

	// D�truire tous mes objets
	delete monCompo;

	return assert;
}
