#include "../inc/Board.hh"
#include "../inc/DFS.hh"
#include "../inc/MakePath.hh"


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
	

	vector<int> visited;									//DFS
	visited.resize(NoE);
     	vector<unsigned int> order;
	vector<vector<char> > path;
	path.resize(checkFields.size());

	DFS(graph, KnightPosition, visited, order);
	
	vector<char> visitingOrder = makeOrder(order, NoE);					//visiing order
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
		
	return 0;
}
