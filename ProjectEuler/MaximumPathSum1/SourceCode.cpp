#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

long MaximumPathSum(vector<vector<int>> &vcTree, unsigned int row, unsigned int col)
{
long MaxSum = 0;

if(row < vcTree.size()-1)
	{
	long Sum1 = MaximumPathSum(vcTree, row+1, col);
	long Sum2 = MaximumPathSum(vcTree, row+1, col+1);
	MaxSum = max(Sum1, Sum2);
	}

return MaxSum + vcTree[row][col];
}

void CollectNumbers(string str, vector<int> &vcNum)
{
string strNum;
for(size_t i = 0; i < str.size() && str[i] != '\0'; i++)
	{
	if(str[i] != ' ')
		strNum.push_back(str[i]);
	else
		{
		vcNum.push_back(atoi(strNum.c_str()));
		strNum.resize(0);
		}
	}

vcNum.push_back(atoi(strNum.c_str()));
}

int main(int argc, char *argv[])
{
fstream FileIO;
FileIO.open("Input.txt", fstream::in);

vector<vector<int>> vcTree;
while(!FileIO.eof())
	{
	string str;
	getline(FileIO, str);

	vector<int> vcNum;
	CollectNumbers(str, vcNum);
	vcTree.push_back(vcNum);
	}

long MaxPathSum = MaximumPathSum(vcTree, 0, 0);

return 0;
}