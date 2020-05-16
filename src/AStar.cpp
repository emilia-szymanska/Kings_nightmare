#include "../inc/AStar.hh"

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


vector<pair<int, int> > AStar(GraphList & graph, int vertex)
{
	unsigned int v, cost, neighbour_index, neighbour_edge;
	unsigned int number_of_elements = graph.Size();
	vector<pair<int, int> > result;
	for(unsigned int i = 0; i < number_of_elements; i++)		// making ,,infinity'' values
	{	
		result[i].first = -1;					//cost
		result[i].second = -1;					//previous
	}

	result[vertex].first = 0;
	priority_queue<pair<int, int> > q;				//cost, vertex	
	q.push({0, vertex});
	while(!q.empty())						//like Dijkstra
	{
		cost = -q.top().first;
		v = q.top().second;
		q.pop();
		if(cost > result[v].first) continue;
		vector<pair<int, int> > neighbours = graph.incidentEdges(v);
		for (auto It = neighbours.begin(); It != neighbours.end(); It++)
		{
			neighbour_index = (*It).first;
			neighbour_edge = (*It).second;
			if(result[neighbour_index].first == -1 || result[neighbour_index].first > cost + neighbour_edge)
			{       	
				result[neighbour_index].second = v;
				result[neighbour_index].first = cost + neighbour_edge;
				q.push({-result[neighbour_index].first, neighbour_index});
			}		
		}	
	}

	return result;
}
