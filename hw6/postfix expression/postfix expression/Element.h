#pragma once

struct Element
{
	Element(int data);
	~Element();
	int data;
	Element* next;
};