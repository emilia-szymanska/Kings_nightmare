#ifndef BOARD_HH
#define BOARD_HH
#include "Matrix.hh"
#include <iostream>
using namespace std;


class Board
{
	unsigned int dimension = 5;
	Matrix<unsigned int> matrixOfFields = Matrix<unsigned int>(dimension,dimension);
	Matrix<char> matrixOfLetters = Matrix<char>(dimension,dimension);
	pair<unsigned int, pair<unsigned int, unsigned int> > Rook;
	pair<unsigned int, pair<unsigned int, unsigned int> > King;
	pair<unsigned int, pair<unsigned int, unsigned int> > Knight;

	public:
		Board(const vector<pair<unsigned int, char > > & vectorOfFigures);

		Matrix<unsigned int> & returnMatrixOfFields()
		{
			return this->matrixOfFields;
		}	
		
		Matrix<char> & returnMatrixOfLetters()
		{
			return this->matrixOfLetters;
		}	
		
		unsigned int returnSize()
		{
			return this->dimension; 
		}
		
		unsigned int KingsPosition()
		{
			return ((this->King).second.first * this->dimension + (this->King).second.second);
		}
		
		unsigned int KnightsPosition()
		{
			return ((this->Knight).second.first * this->dimension + (this->Knight).second.second);
		}
		
		pair<unsigned int, unsigned int> KnightsPositionXY()
		{
			return (this->Knight).second;
		}

		unsigned int KnightsID()
		{
			return this->Knight.first;
		}

		void resetBoard();
		void displayBoard();
		void displayBoardOfLetters();
		void addMove(unsigned int i, unsigned int j, unsigned int Figure);
		void setKnightsPosition(unsigned int i, unsigned int j);		//not checking if the field is empty
		void removeMove(unsigned int i, unsigned int j);
		bool isMovePossible(unsigned int i, unsigned int j, unsigned Figure);
		vector<pair<unsigned int, unsigned int> > knightsPossibleMoves();
		vector<pair<unsigned int, unsigned int> > knightsCheck();
		vector<pair<unsigned int, unsigned int> > boardToVectors();

};

#endif
