#pragma once

struct Element
{
	Element(char data);
	~Element();
	char data;
	Element* next;
};