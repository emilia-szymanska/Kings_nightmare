#include "../inc/DFS.hh"

void DFS(GraphList & graph, unsigned int vertex, vector<int> & visited, vector<unsigned int> & order)
{
	visited[vertex] = 1;
	order.push_back(vertex);
	vector<pair<int, int> > incident = graph.incidentEdges(vertex);
	for(unsigned int i = 0; i < incident.size(); i++)
	{
		int next = incident[i].first;
		if(visited[next] == 0) DFS(graph, next, visited, order);
	}	
	order.push_back(vertex);
}

