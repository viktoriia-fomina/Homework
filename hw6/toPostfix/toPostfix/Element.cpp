#include "Element.h"

Element::Element(char data)
{
	this->data = data;
	this->next = nullptr;
}

Element::~Element()
{
	this->next = nullptr;
}