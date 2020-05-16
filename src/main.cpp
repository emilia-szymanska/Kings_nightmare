#include "../inc/Board.hh"
#include "../inc/DFS.hh"
#include "../inc/MakePath.hh"
#include "../inc/AStar.hh"

int main()
{

	vector<pair<unsigned int, char> > pairs;						//putting figures on the board
	unsigned int RookID = 1;
	unsigned int KingID = 2;
	unsigned int KnightID = 3;

	pairs.resize(3);
	pairs[0] = {RookID, 'A'};	//rook
	pairs[1] = {KingID, 'H'};	//king
	pairs[2] = {KnightID, 'W'};	//knight

	Board board = Board(pairs);								//initializing board
	
	unsigned int boardSize = board.returnSize();						//useful variables
	unsigned int KingPosition = board.KingsPosition();
	unsigned int KnightPosition = board.KnightsPosition();
	unsigned int NoE = boardSize * boardSize;
	vector<pair<unsigned int, unsigned int> > check = board.knightsCheck();
	vector<unsigned int> checkFields;
	for(unsigned int i = 0; i < check.size(); i++)
	{
		checkFields.push_back( check[i].first * boardSize + check[i].second);
	}
	
	vector<pair<unsigned int, unsigned int> > listOfVertices = board.boardToVectors();	//board to graph
	GraphList graph = GraphList(NoE);
	for(unsigned int i = 0; i < listOfVertices.size(); i++)
	{
		graph.insertEdge(listOfVertices[i].first, listOfVertices[i].second, 1);
	}
	



	vector<int> visited;									//DFS - all paths
	visited.resize(NoE);
     	vector<unsigned int> order;
	vector<vector<char> > path;
	path.resize(checkFields.size());
	visited[KingPosition] = 1;
	DFS(graph, KnightPosition, visited, order);
	
	vector<char> visitingOrder = makeOrder(order, NoE);					//visiing order
	cout << endl;
	cout << "Paths to all winning positions (,,check'' positions as final positions)" << endl;
	cout << "Visiting order: ";

	for(unsigned int i = 0; i < visitingOrder.size(); i++)
	{
		cout << visitingOrder[i] << " ";
	}
	cout << endl;

	cout << "Paths:" << endl;								//paths to check
	
	for(unsigned int i = 0; i < checkFields.size(); i++)
	{
		path[i] = makePath(order, checkFields[i], NoE); 
		for(unsigned int j = 0; j < path[i].size(); j++)
			cout << path[i][j] << " ";
		cout << endl;	
	}	

	cout << endl;	
	
	
	vector<int> visited2;									//DFS - path to H
	visited2.resize(NoE);
     	vector<unsigned int> order2;
	vector<char> path2;
	path2.resize(1);
	DFS(graph, KnightPosition, visited2, order2);
	
	vector<char> visitingOrder2 = makeOrder(order2, NoE);					//visiing order
	cout << "One path (king's position as final position)" << endl;
	cout << "Visiting order: ";

	for(unsigned int i = 0; i < visitingOrder2.size(); i++)
	{
		cout << visitingOrder2[i] << " ";
	}
	cout << endl;

	cout << "Path:" << endl;								//path to H

	path2 = makePath(order2, KingPosition, NoE); 
	for(unsigned int j = 0; j < path2.size(); j++)
		cout << path2[j] << " ";
	cout << endl;	
	cout << endl;


	vector<pair<int, int> > aStarResult = AStar(graph, KnightPosition);
	cout << aStarResult[KingPosition].first << " " << aStarResult[KingPosition].second;
	cout << endl;


	return 0;
}
