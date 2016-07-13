#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Component
{
	friend class Engine;

public:
	Component();
	virtual ~Component();

	void ReorderLastCompFirst();
	void SortComponentsOrderLayer();
	void SetOrderLayer(const int _orderLayer) { orderLayer = _orderLayer; }

	virtual void Update();
	virtual void Draw();

	bool operator < (const Component* str) const {	return (orderLayer < str->orderLayer);	}

private:
	static std::vector<Component*> components;
	int orderLayer;
};

