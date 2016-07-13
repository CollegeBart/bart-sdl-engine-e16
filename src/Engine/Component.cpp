#include "Component.h"

std::vector<Component*> Component::components;

Component::Component()
	: orderLayer(0)
{
	components.push_back(this);
}

Component::~Component()
{

}

void Component::ReorderLastCompFirst()
{
	Component* last = components[components.size() - 1];
	Component* first = components[0];
	components[components.size() - 1] = first;
	components[0] = last;
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
