#include "Component.h"

std::vector<Component*> Component::components;

Component::Component()
	: orderLayer(0), isActive(true)
{
	components.push_back(this);
}

Component::~Component()
{

}

void Component::ReorderLastCompFirst()
{
	std::vector<Component*> componentsCpy;
	componentsCpy.push_back(components.at(components.size() - 1));
	for (int i = 0; i < components.size() - 1; i++)
	{
		componentsCpy.push_back(components.at(i));
	}
	components.clear();
	for (int i = 0; i < componentsCpy.size(); i++)
	{
		components.push_back(componentsCpy.at(i));
	}
}

void Component::SortComponentsOrderLayer()
{
	std::sort(components.begin(), components.end());
}

void Component::Update()
{
	
}

void Component::Draw()
{

}
