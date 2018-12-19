#include "graph.h"

using namespace std;

//≈сть множество городов и дороги, св€зывающие эти города.ƒл€ каждой дороги задана еЄ длина.
//«адача Ц распределить города между государствами по такому алгоритму : задаютс€ k столиц каждого государства, 
//далее по очереди каждому государству добавл€етс€ ближайший незан€тый город, непосредственно св€занный дорогой 
//с каким - либо городом, уже принадлежащим государству(столицей или каким - либо городом, добавленным на одном 
//	из предыдущих шагов).ѕроцесс продолжаетс€ до тех пор, пока все города не будут распределены.
//	√раф дорог св€зный.¬о входном файле : n Ц число городов и m Ц число дорог.ƒалее следуют сами 
//	дороги в формате : i j len, i и j Ц номера городов, len Ц длина дороги.ƒалее задано число k Ц число столиц, 
//	далее Ц k чисел Ц номера столиц.Ќадо вывести на консоль номера государств и списки городов, принадлежащих 
//	государствам.

Graph::Graph(int const numberOfVertexes)
{
	this->numberOfVertexes = numberOfVertexes;
	adjacencyMatrix = new int*[numberOfVertexes];
	for (int i = 0; i < numberOfVertexes; ++i)
	{
		adjacencyMatrix[i] = new int[numberOfVertexes] {};
	}
}

Graph::~Graph()
{
	for (int i = 0; i < numberOfVertexes; ++i)
	{
		delete[] adjacencyMatrix[i];
	}
	delete[] adjacencyMatrix;
}

int & Graph::operator()(int const i, int const j)
{
	return adjacencyMatrix[i][j];
}

int const & Graph::operator()(int const i, int const j) const
{
	return adjacencyMatrix[i][j];
}

ostream & operator<<(ostream & os, Graph const & graph)
{
	for (int i = 0; i < graph.numberOfVertexes; ++i)
	{
		for (int j = 0; j < graph.numberOfVertexes; ++j)
		{
			os << graph(i, j) << " ";
		}
		os << endl;
	}
	return os;
}

istream & operator>>(istream & is, Graph & graph)
{
	for (int i = 0; i < graph.numberOfVertexes; ++i)
	{
		for (int j = 0; j < graph.numberOfVertexes; ++j)
		{
			is >> graph(i, j);
		}
	}
	return is;
}