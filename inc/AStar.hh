#ifndef ASTAR_HH
#define ASTAR_HH
#include <vector>

struct AStar_results
{
	unsigned int Size;
	vector<int> cost;
	vector<int> previous;
	
	AStar_results(int Size) 
	{
		this->Size = Size;
		this->distance.resize(Size);
		this->previous.resize(Size);
	}
};

template <class T>
AStar_results AStar(T & graph, unsigned int vertex);

#include "../src/AStar.cpp"

#endif
