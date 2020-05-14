#include "../inc/DFS.hh"

void DFS(GraphList & graph, unsigned int vertex, vector<int> & result)
{
	result[vertex] = 1;
	vector<pair<int, int> > incident = graph.incidentEdges(vertex);
	for(unsigned int i = 0; i < incident.size(); i++)
	{
		int next = incident[i].first;
		if(result[next] == 0) DFS(graph, next, result);
	}	
}

