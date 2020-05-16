#ifndef MAKEPATH_HH
#define MAKEPATH_HH
#include <vector>
#include <iostream>
using namespace std;


vector<char> makePath(const vector<unsigned int> & DFSorder, unsigned int endVertex, unsigned int numberOfVertices);

vector<char> makeOrder (const vector<unsigned int> & DFSorder, unsigned int numberOfVertices);

#endif	
