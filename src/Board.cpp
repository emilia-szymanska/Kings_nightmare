#include "../inc/Board.hh"

Board::Board(const vector<pair<unsigned int, char> > & vectorOfFigures)
{
	this->Rook.first = vectorOfFigures[0].first;
	this->King.first = vectorOfFigures[1].first;
	this->Knight.first = vectorOfFigures[2].first;
	int tmp = 65;								//beginning with A
	
	for(unsigned int i = 0; i < this->returnSize(); i++)
		for(unsigned int j = 0; j < this->returnSize(); j++)
			this->matrixOfFields(i,j) = 0;
	
	for(unsigned int i = 0; i < this->returnSize(); i++)
	{
		for(unsigned int j = 0; j < this->returnSize(); j++)
		{
	       		this->matrixOfLetters(i,j) = (char)(tmp+i+j);
		}
		tmp += 4;
	}

	for(unsigned int i = 0; i < this->returnSize(); i++)
	{
		for(unsigned int j = 0; j < this->returnSize(); j++)
		{
	   		if(this->matrixOfLetters(i,j) == vectorOfFigures[0].second)
			{
				this->Rook.second = {i, j};
			}
			else
			{
				if(this->matrixOfLetters(i,j) == vectorOfFigures[1].second) 
					this->King.second = {i,j};
				else if(this->matrixOfLetters(i,j) == vectorOfFigures[2].second) 
					this->Knight.second = {i,j};
			
			}
		}
	}	

	
	for(unsigned int j = 0; j < this->returnSize(); j++)
		this->matrixOfFields((this->Rook.second).first, j) = this->Rook.first;
	
	for(unsigned int i = 0; i < this->returnSize(); i++)
		this->matrixOfFields(i, (this->Rook.second).second) = this->Rook.first;

	this->matrixOfFields((this->King.second).first, (this->King.second).second) = this->King.first;
	this->matrixOfFields((this->Knight.second).first, (this->Knight.second).second) = this->Knight.first;

}

void Board::displayBoard()
{	
	cout << endl;
	
	for(unsigned int i = 0; i < this->returnSize(); i++)
	{
		for(unsigned int j = 0; j < this->returnSize(); j++)
		{
			cout << this->matrixOfFields(i,j) << " ";
		}
		cout << endl;
	}
	
	cout << endl;
}

void Board::displayBoardOfLetters()
{	
	cout << endl;
	
	for(unsigned int i = 0; i < this->returnSize(); i++)
	{
		for(unsigned int j = 0; j < this->returnSize(); j++)
		{
			cout << this->matrixOfLetters(i,j) << " ";
		}
		cout << endl;
	}

	cout << endl;
}


void Board::addMove(unsigned int i, unsigned int j, unsigned int Figure)
{
	if(this->matrixOfFields(i,j) == 0) 
	{
		this->matrixOfFields(i,j) = Figure;
		this->Knight.second = {i,j};
	}
	else cout << "This field is already occupied"<<endl;
}

void Board::removeMove(unsigned int i, unsigned int j)
{
	this->matrixOfFields(i,j) = 0;
}

bool Board::isMovePossible(unsigned int i, unsigned int j, unsigned int Figure)
{
	if(i >= 0 and i < this->returnSize() and j >= 0 and j < this->returnSize() )  
	{
		if(this->matrixOfFields(i,j) == 0) return true;
		else return false;
	}	
	else 
	{
		return false;
	}
}


void Board::resetBoard()
{
	for(unsigned int i = 0; i < this->returnSize(); i++)
		for(unsigned int j = 0; j < this->returnSize(); j++)
			this->matrixOfFields(i, j) = 0;
}


vector<pair<unsigned int, unsigned int> > Board::knightsPossibleMoves()
{
	int row, column;
	int dimension = this->dimension;
	vector<pair<unsigned int, unsigned int> > result;	
	
	row = ((this->Knight).second).first;
	column = ((this->Knight).second).second;

	if(row >= 1  and column <= dimension - 3 and this->matrixOfFields(row-1, column+2) == 0) result.push_back({row-1, column+2});			//2 right, 1 up
	if(row <= dimension - 2  and column <= dimension - 3 and this->matrixOfFields(row+1, column+2) == 0) result.push_back({row+1, column+2});	//2 right, 1 down
	
	if(row >= 1  and column >= 2 and this->matrixOfFields(row-1, column-2) == 0) result.push_back({row-1, column-2});				//2 left, 1 up
	if(row <= dimension - 2  and column >= 2 and this->matrixOfFields(row+1, column-2) == 0) result.push_back({row+1, column-2});			//2 left, 1 down
	
	if(row >= 2  and column >= 1 and this->matrixOfFields(row-2, column-1) == 0) result.push_back({row-2, column-1});				//1 left, 2 up
	if(row >= 2  and column <= dimension - 2 and this->matrixOfFields(row-2, column+1) == 0) result.push_back({row-2, column+1});			//1 right, 2 up
	
	if(row <= dimension - 3  and column >= 1 and this->matrixOfFields(row+2, column-1) == 0) result.push_back({row+2, column-1});			//1 left, 2 down
	if(row <= dimension - 3  and column <= dimension - 2 and this->matrixOfFields(row+2, column+1) == 0) result.push_back({row+2, column+1});	//1 right, 2 down

	return result;

}
		
vector<pair<unsigned int, unsigned int> > Board::knightsCheck()
{
	int row, column;
	int dimension = this->dimension;
	vector<pair<unsigned int, unsigned int> > result;	
	
	row = ((this->King).second).first;
	column = ((this->King).second).second;

	if(row >= 1  and column <= dimension - 3 and this->matrixOfFields(row-1, column+2) == 0) result.push_back({row-1, column+2});			//2 right, 1 up
	if(row <= dimension - 2  and column <= dimension - 3 and this->matrixOfFields(row+1, column+2) == 0) result.push_back({row+1, column+2});	//2 right, 1 down
	
	if(row >= 1  and column >= 2 and this->matrixOfFields(row-1, column-2) == 0) result.push_back({row-1, column-2});				//2 left, 1 up
	if(row <= dimension - 2  and column >= 2 and this->matrixOfFields(row+1, column-2) == 0) result.push_back({row+1, column-2});			//2 left, 1 down
	
	if(row >= 2  and column >= 1 and this->matrixOfFields(row-2, column-1) == 0) result.push_back({row-2, column-1});				//1 left, 2 up
	if(row >= 2  and column <= dimension - 2 and this->matrixOfFields(row-2, column+1) == 0) result.push_back({row-2, column+1});			//1 right, 2 up
	
	if(row <= dimension - 3  and column >= 1 and this->matrixOfFields(row+2, column-1) == 0) result.push_back({row+2, column-1});			//1 left, 2 down
	if(row <= dimension - 3  and column <= dimension - 2 and this->matrixOfFields(row+2, column+1) == 0) result.push_back({row+2, column+1});	//1 right, 2 down

	return result;
}	
