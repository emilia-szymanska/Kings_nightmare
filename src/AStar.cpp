template <class T>
AStar_results AStar(T & graph, int vertex)
{
	unsigned int v, cost, neighbour_index, neighbour_edge;
	unsigned int number_of_elements = graph.Size();
	AStar_results result = AStar_results(number_of_elements);			//putting results into special struct
	for(unsigned int i = 0; i < number_of_elements; i++)		// making ,,infinity'' values
	{	
		result.cost[i] = -1;
		result.previous[i] = -1;
	}

	result.cost[vertex] = 0;
	Heap<Pair<int> > Q = Heap<Pair<int> >();	
	Q.addToHeap(Pair<int>(0, vertex));
	while(!Q.isEmpty())						//like Dijkstra
	{
		cost = -Q.seeRoot().first;
		v = Q.seeRoot().second;
		Q.takeFromHeap();
		if(cost > result.cost[v]) continue;
		vector<Pair<unsigned int> > neighbours = graph.incidentEdges(v);
		for (auto It = neighbours.begin(); It != neighbours.end(); It++)
		{
			
			neighbour_index = (*It).first;
			neighbour_edge = (*It).second;
			if(result.cost[neighbour_index] == -1 || result.cost[neighbour_index] > dist + neighbour_edge)
			{       	
				result.previous[neighbour_index] = v;
				result.cost[neighbour_index] = dist + neighbour_edge;
				Q.addToHeap(Pair<int>(-result.cost[neighbour_index], neighbour_index));
			}		
		}	
	}

	return result;
}
