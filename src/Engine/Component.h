#pragma once

#include <iostream>
#include <vector>

class Component
{
	friend class Engine;

public:
	Component();
	~Component();

	void Update();
	void Draw();

private:
	static std::vector<Component*> components;
};

