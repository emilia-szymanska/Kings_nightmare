#include "../inc/MakePath.hh"

vector<char> makePath(vector<unsigned int> DFSorder, unsigned int endVertex)
{
	vector<char> result;
	vector<unsigned int> ifSeen;
	ifSeen.resize(DFSorder.size()/2, 0);
	unsigned int vertex;

	for(unsigned int i = 0; i < DFSorder.size(); i++)
	{
		vertex = DFSorder[i];
		if(vertex == endVertex) 
		{
			result.push_back('A'+vertex);
			return result;
		}

		if(ifSeen[vertex] == 0)
		{
			ifSeen[vertex] = 1;
			result.push_back('A'+vertex);
		}
		else
		{
			unsigned int j = result.size() - 1;
			while('A'+vertex != result[j])
			{
				result.pop_back();
				j--;
			}
			result.pop_back();
		}
	}
	return result;
}

vector<char> makeOrder (vector<unsigned int> DFSorder)
{
	vector<char> result;
	vector<unsigned int> ifSeen;
	ifSeen.resize(DFSorder.size()/2, 0);
	unsigned int vertex;

	for(unsigned int i = 0; i < DFSorder.size(); i++)
	{
		vertex = DFSorder[i];
		if(ifSeen[vertex] == 0)
		{
			ifSeen[vertex] = 1;
			result.push_back('A'+vertex);
		}
	}

	return result;	
}
