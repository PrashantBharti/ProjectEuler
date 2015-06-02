// This code is a solution to
// https://projecteuler.net/problem=14

#include <iostream>
#include <map>
using namespace std;

unsigned long SeqLen(unsigned long iNum, map<unsigned long, unsigned long> &HashSeqLen)
{
if(iNum < 1)
	return 0;

if(iNum == 1)
	return 1;

if(HashSeqLen[iNum] != 0)
	return HashSeqLen[iNum];

if(iNum % 2 == 0)
	HashSeqLen[iNum] = 1 + SeqLen(iNum / 2, HashSeqLen);
else
	HashSeqLen[iNum] = 1 + SeqLen(3*iNum + 1, HashSeqLen);

return HashSeqLen[iNum];
}

int main(int argc, char *argv[])
{
map<unsigned long, unsigned long> HashSeqLen;

unsigned long iMaxLenNum = 0;
unsigned long iMaxLen = 0;

for(unsigned int i = 1; i < 1000000; i++)
	{
	unsigned long iSeqLen = SeqLen(i, HashSeqLen);
	if(iSeqLen > iMaxLen)
		{
		iMaxLen = iSeqLen;
		iMaxLenNum = i;
		}
	}

cout << "Max Length Num: " << iMaxLenNum << "having Length: " << iMaxLen << endl;
return 0;
}