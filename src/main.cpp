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
	parki.resize(3);
	parki[0] = {1, 'H'};
	parki[1] = {2, 'A'};
	parki[2] = {3, 'S'};


	Board plansza = Board(parki);


	return 0;
}
