#ifndef MAKEPATH_HH
#define MAKEPATH_HH
#include <vector>
#include <iostream>
using namespace std;


vector<char> makePath(vector<unsigned int> DFSorder, unsigned int endVertex);

vector<char> makeOrder (vector<unsigned int> DFSorder);

#endif	
