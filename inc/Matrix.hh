#ifndef MATRIX_HH
#define MATRIX_HH
#include <vector>
using namespace std;


template <typename T>
struct Matrix
{
	unsigned int rows;
	unsigned int columns;
	vector<T> V;
	
	Matrix(unsigned int rows = 1, unsigned int columns = 1)
	{
		this->rows = rows;
		this->columns = columns;
		this->V.resize(rows*columns); 
	}

	T & operator () (unsigned int i, unsigned int j)
	{
		return V[i * this->columns + j];
	}	
};

#endif
