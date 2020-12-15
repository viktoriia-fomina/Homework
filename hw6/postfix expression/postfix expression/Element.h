#pragma once

struct Element
{
	explicit Element(int data);
	int data;
	Element* next;
};