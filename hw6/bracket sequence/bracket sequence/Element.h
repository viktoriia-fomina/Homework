#pragma once

struct Element
{
	explicit Element(char data);

	char data;
	Element* next;
};