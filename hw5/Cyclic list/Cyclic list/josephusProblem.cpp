#include "List.h"
#include "Node.h"

int josephusProblem(int const numberOfWarriors, int const murderFrequency)
{
	List l;
	for (int i = numberOfWarriors; i >= 1; --i)
	{
		l.addNode(i);
	}
	auto* temp = l.getHead();
	auto* nextAfterElementToDelete = temp;
	while (!l.isOneNode())
	{
		temp = nextAfterElementToDelete;
		for (int i = 0; i < murderFrequency - 1; ++i)
		{
			temp = temp->next;
		}
		int numberOfCurrentWarrior = temp->data;
		nextAfterElementToDelete = temp->next;
		l.deleteNode(numberOfCurrentWarrior);
	}
	return l.getHead()->data;
}