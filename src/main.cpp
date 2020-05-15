#include "../inc/Board.hh"
#include "../inc/DFS.hh"
#include "../inc/MakePath.hh"

/*
vector<pair<pair<unsigned int, unsigned int>, unsigned int > > boardToList (Board & board)	//{v1,v2}, cost
{
	vector<pair<unsigned int, unsigned int> > knightsMoves = board.knightsPossibleMoves();
	vector<pair<pair<unsigned int, unsigned int>, unsigned int > > result;
	vector<pair<pair<unsigned int, unsigned int>, unsigned int > > nextRecursion;
	unsigned int V1, V2, cost, x, y;

	
	for(unsigned int i = 0; i < knightsMoves.size(); i++)
	{
		x = knightsMoves[i].first;
	       	y = knightsMoves[i].second;
		V1 = board.KnightsPosition();
		V2 = x * board.Size() + y;
		cost = 1;
		result.push_back({V1, V2}, cost);
		board.addMove(x, y, board.KnightsID());
		if(!board.knightsPossibleMoves().empty())
			nextRecursion = boardToList(board);	
		board.removeMove(x, j);
	}	

	return 

}*/

void boardToList (Board & board, vector<pair<pair<unsigned int, unsigned int>, unsigned int > > & result)	//{v1,v2}, cost
{
	vector<pair<unsigned int, unsigned int> > knightsMoves = board.knightsPossibleMoves();
	vector<pair<pair<unsigned int, unsigned int>, unsigned int > > nextRecursion;
	unsigned int V1, V2, cost, x, y;

	for(unsigned int i = 0; i < knightsMoves.size(); i++)
	{
		x = knightsMoves[i].first;
	       	y = knightsMoves[i].second;
		V1 = board.KnightsPosition();
		V2 = x * board.returnSize() + y;
		cost = 1;
		result.push_back({{V1, V2}, cost});
		board.addMove(x, y, board.KnightsID());
		if(!board.knightsPossibleMoves().empty())
			boardToList(board, result);	
		board.removeMove(x, y);
	}	
	return; 
}

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
	cout << board.KnightsPosition() << endl;
	
	/*board.displayBoardOfLetters();
	board.displayBoard();
		

	//	void addMove(unsigned int i, unsigned int j, unsigned int Figure);
	//	void removeMove(unsigned int i, unsigned int j);
	//	bool isMovePossible(unsigned int i, unsigned int j, unsigned Figure);
	
	check = board.knightsCheck();
	int howManyChecks = check.size();
	

	vector<unsigned int> Order;
	Order.push_back(0);
	Order.push_back(2);
	Order.push_back(1);
	Order.push_back(1);
	Order.push_back(3);
	Order.push_back(3);
	Order.push_back(4);
	Order.push_back(4);
	Order.push_back(2);
	Order.push_back(0);

	vector<char> result;

//	result = makePath(Order, 4);	
	
	result = makeOrder(Order);

	for(int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	cout << endl;
	

	unsigned int NoE;
	
	GraphList grafik = GraphList(NoE);

		unsigned int KnightsPosition()
	

	for(int i = 0; i < edge; i++)
	{
		cin>>v1>>v2>>value;
		grafik.insertEdge(v1, v2, value);
	}
	

	for(int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	cout << endl;
	
	for(int i = 0; i < howManyChecks; i++)
		cout << check[i].first << " " << check[i].second << endl;
*/
	return 0;
}
