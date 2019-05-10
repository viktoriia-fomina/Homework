#pragma once

struct Element
{
	explicit Element(int data);
	
	int data;
	Element* previous;
	Element* next;
private:
	Element();
};