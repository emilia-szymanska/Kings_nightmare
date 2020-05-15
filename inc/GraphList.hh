#ifndef GRAPHLIST_HH
#define GRAPHLIST_HH
#include <vector>
using namespace std;

class GraphList
{
	unsigned int numberOfElements;
	vector<vector<pair<int, int> > > listGraph;
	
	public:
		GraphList(unsigned int NoE = 0)
		{
			this->numberOfElements = NoE;
			this->listGraph.resize(NoE);
		}
		
		void addEdge(unsigned int vertex1, unsigned int vertex2, int value)
		{
			this->listGraph[vertex1].push_back({vertex2, value});
		}	
		
		vector<pair<int, int> > incidentEdges(unsigned int vertex)
		{
			return listGraph[vertex];
		}

		unsigned int Size()
		{
			return this->numberOfElements;
		}
};

#endif
