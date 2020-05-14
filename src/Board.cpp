#include "../inc/Board.hh"

Board::Board(vector<pair<unsigned int, char> > & vectorOfFigures)
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
				if(this->matrixOfLetters(i,j) == vectorOfFigures[1].second) this->King.second = {i,j};
				else this->Knight.second = {i,j};
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


	/*
	for(unsigned int i = 0; i <= this->returnSize(); i++)
	{
		for(unsigned int j = 0; j <= this->returnSize(); j++)
		{
			if(i == 0) 							//displaying a row of numbers
			{
				if(j == 0)
				{	cout << "   " << j+1;}
				else {
					if(j != this->returnSize()) 
					{
						if (j<10) cout << "  " << j+1;
						else cout << " " << j+1;
					}
				}	
			}
			else 
			{
				if(j == 0) 
				{
					if( i >= 10) cout << i << " ";
					else cout << i << "  ";				//displaying the number of the line
				}
				else 
				{
					if(this->matrixOfFields(i-1,j-1) == this->Rook.first) 
					{
						cout << playerName1.playerSign << "  ";
					}
					else 
					{
						if(this->matrixOfFields(i-1,j-1) == playerName2.playerID) cout << playerName2.playerSign << "  ";
						else cout << "_  ";
					}	
				}
			}
		}
		cout << endl;
	}*/
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
}


void Board::addMove(unsigned int i, unsigned int j, unsigned int Figure)
{
	if(this->matrixOfFields(i,j) == 0) this->matrixOfFields(i,j) = Figure;
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


