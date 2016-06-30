#include "Component.h"

std::vector<Component*> Component::components = std::vector<Component*>(1000);

Component::Component()
{
	components.push_back(this);
}

Component::~Component()
{

}

void Component::Update()
{
	std::cout << "Component::Update" << std::endl;
}

void Component::Draw()
{

}
