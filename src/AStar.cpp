#include "../inc/AStar.hh"
#define SizeOfBoard 5

int heuristic(unsigned int vector1, unsigned int vector2, unsigned int sizeOfBoard)
{
	int u, v, p, q, heur;
	u = vector1 / sizeOfBoard;
	v = vector1 % sizeOfBoard;
	p = vector2 / sizeOfBoard;
	q = vector2 % sizeOfBoard;
	heur = abs(u - p) + abs(v - q);
	return heur;
}


vector<pair<int, int> > AStar(GraphList & graph, unsigned int vertexStart, unsigned int vertexEnd)
{
	unsigned int v, cost, neighbour_index, neighbour_edge, neighb_cost, neighb_prev;
	unsigned int number_of_elements = graph.Size();
	vector<pair<int, int> > result;
	result.resize(number_of_elements);
	for(unsigned int i = 0; i < number_of_elements; i++)		// making ,,infinity'' values
	{	
		result[i].first = -1;					//cost
		result[i].second = -1;					//previous
	}

	result[vertexStart].first = 0;
	priority_queue<pair<pair<int, int>, int > > q;			//cost+heuristic, cost, vertex	
	q.push({{0, 0}, vertexStart});
	while(!q.empty())
	{
		cost = -q.top().first.second;
		v = q.top().second;
		q.pop();
		if(cost > result[v].first) continue;
		vector<pair<int, int> > neighbours = graph.incidentEdges(v);
		for (auto It = neighbours.begin(); It != neighbours.end(); It++)
		{
			neighbour_index = (*It).first;
			neighbour_edge = (*It).second;
			neighb_cost = result[neighbour_index].first;
		       	neighb_prev = result[neighbour_index].second; 
			if(neighb_cost == -1 || neighb_cost > cost + neighbour_edge)
			{       	
				result[neighbour_index].second = v;
				result[neighbour_index].first = cost + neighbour_edge;
				q.push({{ -result[neighbour_index].first - heuristic(neighbour_index, vertex, SizeOfBoard), -result[neighbour_index].first}, neighbour_index});
			}		
		}	
	}

	return result;
}
