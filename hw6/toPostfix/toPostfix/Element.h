#pragma once

struct Element
{
	Element(char data = '\0');

	~Element();

	char data;
	Element* next;
};