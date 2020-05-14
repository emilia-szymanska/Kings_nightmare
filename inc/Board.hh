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
		
		unsigned int returnSize()
		{
			return this->dimension; 
		}

		void resetBoard();
		void displayBoard();
		void displayBoardOfLetters();
		void addMove(unsigned int i, unsigned int j, unsigned int Figure);
		void removeMove(unsigned int i, unsigned int j);
		bool isMovePossible(unsigned int i, unsigned int j, unsigned Figure);
		vector<pair<unsigned int, unsigned int> > knightsPossibleMoves();
};

#endif
