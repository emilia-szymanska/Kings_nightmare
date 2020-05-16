#include "../inc/Board.hh"
#include "../inc/DFS.hh"
#include "../inc/MakePath.hh"


int main()
{

	vector<pair<unsigned int, char> > pairs;
	vector<pair<unsigned int, unsigned int> > check;
	unsigned int boardSize;
	unsigned int RookID = 1;
	unsigned int KingID = 2;
	unsigned int KnightID = 3;

	pairs.resize(3);
	pairs[0] = {RookID, 'A'};	//rook
	pairs[1] = {KingID, 'H'};	//king
	pairs[2] = {KnightID, 'W'};	//knight


	Board board = Board(pairs);
	boardSize = board.returnSize();
	vector<pair<unsigned int, unsigned int> > trial;
	trial = board.boardToVectors();
	
	unsigned int NoE = 25;
	
	GraphList grafik = GraphList(NoE);
	
	for(unsigned int i = 0; i < trial.size(); i++)
	{
		grafik.insertEdge(trial[i].first, trial[i].second, 1);
	}
	

	vector<int> visited;
	visited.resize(25);
       	vector<unsigned int> order;
       	DFS(grafik, 22, visited, order);
	check = board.knightsCheck();
	vector<unsigned int> checkFields;

	for(unsigned int i = 0; i < check.size(); i++)
	{
		checkFields.push_back( check[i].first * boardSize + check[i].second);
	}

	for(unsigned int i = 0; i < checkFields.size(); i++)
	{
		cout << checkFields[i] << " ";
	}
	cout << endl;
	

/*	vector<char> ordered = makeOrder(order, 25);

	for(unsigned int i = 0; i < ordered.size(); i++)
		cout << ordered[i] << " ";
	cout << endl;

	vector<char> path = makePath(order, 6, 25);

	for(unsigned int i = 0; i < path.size(); i++)
		cout << path[i] << " ";
	cout << endl;
*/	
	return 0;
}
