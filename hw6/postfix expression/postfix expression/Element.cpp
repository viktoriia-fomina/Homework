#include "Element.h"

Element::Element(int data = 0)
{
	this->data = data;
	this->next = nullptr;
}

Element::~Element()
{
	this->data = 0;
	this->next = nullptr;
}