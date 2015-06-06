// Solution for
// https://projecteuler.net/problem=15

#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;

#define PAIR(x, y) pair<int, int>(x, y)

unsigned long long Paths(vector<vector<int>> &matrix, int iNRows, int iNCols, map<pair<int, int>, unsigned long long> &hashmap, int iR, int iC)
{
if(iR == iNRows - 1 && iC == iNCols - 1)
	return 1;

if(hashmap[PAIR(iR, iC)] != 0)
	return hashmap[PAIR(iR, iC)];

unsigned long long iPathsFromRight = 0;
unsigned long long iPathsFromBottom = 0;

if(iC < iNCols - 1)
	iPathsFromRight = Paths(matrix, iNRows, iNCols, hashmap, iR, iC + 1);
if(iR < iNRows - 1)
	iPathsFromBottom = Paths(matrix, iNRows, iNCols, hashmap, iR + 1, iC);

hashmap[PAIR(iR, iC)] = iPathsFromRight + iPathsFromBottom;
return hashmap[PAIR(iR, iC)];
}

int main(int argc, char* argv[])
{
int iNRows = 21;
int iNCols = 21;
vector<vector<int>> matrix(iNRows);
for(int i = 0; i < iNRows; i++)
	matrix[i].resize(iNCols);

map<pair<int, int>, unsigned long long> hashmap;

unsigned long long iTotalPaths = Paths(matrix, iNRows, iNCols, hashmap, 0, 0);

return 0;
}