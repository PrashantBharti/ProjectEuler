#include <vector>
using namespace std;

void Reverse(vector<int> &num)
{
unsigned int j = num.size()-1;
unsigned int i = 0;
while(i < j)
	{
	int iTemp = num[i];
	num[i] = num[j];
	num[j] = iTemp;
	i++;
	j--;
	}
}

vector<int> MultiplyBy2(vector<int> &num)
{
vector<int> val;
int iCarry = 0;

vector<int>::const_reverse_iterator itrRev = num.crbegin();
while(itrRev != num.crend())
	{
	int iVal = (*itrRev)*2 + iCarry;
	val.push_back(iVal % 10);
	iCarry = iVal / 10;
	itrRev++;
	}
if(iCarry != 0)
	val.push_back(iCarry);

Reverse(val);
return val;
}

vector<int> Square(vector<int> num)
{
return vector<int>();
}

vector<int> Get2ToPow(int iPow)
{
if(iPow == 1)
	{
	vector<int> val;
	val.push_back(2);
	return val;
	}
else
	{
	vector<int> val;
	val.push_back(2);

	for(int i = 2; i <= iPow; i++)
		val = MultiplyBy2(val);

	return val;
	}


vector<int> val;
if(iPow % 2 == 0)
	{
	vector<int> valofhalf = Get2ToPow(iPow/2);
	val = Square(valofhalf);
	}
else
	{
	vector<int> valofoneless = Get2ToPow(iPow-1);
	val = MultiplyBy2(valofoneless);
	}

return val;
}

int main(int argc, char *argv[])
{
vector<int> val = Get2ToPow(1000);

int iSum = 0;
for(int i : val)
	iSum += i;

return 0;
}