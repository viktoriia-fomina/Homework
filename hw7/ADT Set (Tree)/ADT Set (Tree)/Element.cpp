#include "Element.h"

Element::Element(int data = 0)
{
	this->data = data;
	this->previous = nullptr;
	this->next = nullptr;
}