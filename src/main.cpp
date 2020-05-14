#include "../inc/Board.hh"
#include <iostream>
using namespace std;

int main()
{
/*	int tmp = 65;
	Matrix<char> macierz = Matrix<char>(5, 5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
	       		macierz(i,j) = (char)(tmp+i+j);
		}
		tmp += 4;
	}

	for(int i = 0; i < 5; i++)
	{
	       for(int j = 0; j < 5; j++)
	       {
			cout<<macierz(i,j)<<" ";
	       }
	       cout<<endl;
	}*/

	vector<pair<unsigned int, char> > parki;
	vector<pair<unsigned int, unsigned int> > rezultat;
	parki.resize(3);
	parki[0] = {1, 'H'};
	parki[1] = {2, 'A'};
	parki[2] = {3, 'N'};


	Board plansza = Board(parki);
	plansza.displayBoardOfLetters();
	plansza.displayBoard();
		

	//	void addMove(unsigned int i, unsigned int j, unsigned int Figure);
	//	void removeMove(unsigned int i, unsigned int j);
	//	bool isMovePossible(unsigned int i, unsigned int j, unsigned Figure);
	
	rezultat = plansza.knightsPossibleMoves();
	int rozmiar = rezultat.size();

	for(int i = 0; i < rozmiar; i++)
		cout << rezultat[i].first << " " << rezultat[i].second << endl;

	return 0;
}
