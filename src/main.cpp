#include "../inc/Board.hh"
#include "../inc/DFS.hh"
#include "../inc/MakePath.hh"


int main()
{

	vector<pair<unsigned int, char> > pairs;
	vector<pair<unsigned int, unsigned int> > check;
	unsigned int RookID = 1;
	unsigned int KingID = 2;
	unsigned int KnightID = 3;

	pairs.resize(3);
	pairs[0] = {RookID, 'A'};	//rook
	pairs[1] = {KingID, 'H'};	//king
	pairs[2] = {KnightID, 'W'};	//knight


	Board board = Board(pairs);
	Board copyBoard = Board(pairs);
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
	vector<char> porzadek = makeOrder(order);

	for(unsigned int i = 0; i < porzadek.size(); i++)
		cout << porzadek[i] << " ";
	cout << endl;

/*	vector<char> path = makePath(order, 7);

	for(unsigned int i = 0; i < path.size(); i++)
		cout << path[i] << " ";
	cout << endl;
*/	
	return 0;
}
