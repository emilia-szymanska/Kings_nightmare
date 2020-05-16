#ifndef ASTAR_HH
#define ASTAR_HH
#include "GraphList.hh"
#include <queue>
#include <cmath>

int heuristic(unsigned int vector1, unsigned int vector2, unsigned int sizeOfBoard);

vector<pair<int, int> > AStar(GraphList & graph, unsigned int vertexStart, unsigned int vertexEnd);			//returns a cost and its vertex

#endif
