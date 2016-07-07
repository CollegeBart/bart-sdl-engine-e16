#include "Engine.h"
#include "Wqt.h"
#include <iostream>

int main(int argc, char* args[])
{
	gEngine->Init();

	// Cr�er tous mes objets
	Wqt* monCompo = new Wqt();
	
	int assert = gEngine->Run();

	// D�truire tous mes objets
	delete monCompo;

	return assert;
}
