#include "Element.h"

Element::Element(int data = 0)
{
	this->data = data;
	this->previous = nullptr;
	this->next = nullptr;
}

Element::~Element()
{
	this->previous = nullptr;
	this->next = nullptr;
	data = 0;
}