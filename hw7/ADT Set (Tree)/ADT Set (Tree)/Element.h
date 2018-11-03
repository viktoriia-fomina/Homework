#pragma once

struct Element
{
	explicit Element(int data);
	~Element();
	int data;
	Element* previous;
	Element* next;
private:
	Element();
};