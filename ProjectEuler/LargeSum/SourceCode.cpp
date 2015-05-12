#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void CollectInput(const char* filepath, vector<string> &ArrNumbers)
{
filebuf file;
file.open(filepath, ios::in);

istream input(&file);

char number[51] = "";
int counter = 0;
while(input && counter < 100)
	{
	input.getline(number, 51, '\n');
	if(*number != '\0')
		{
		ArrNumbers[counter].resize(51);
		ArrNumbers[counter] = number;
		counter++;
		}
	}

file.close();
}

string AddLargeNumbers(vector<string> &ArrNumbers)
{
int carry = 0;
string sum = "";
for(int i = 49; i >= 0; i--)
	{
	int sum_temp = 0;
	for(int j = 0; j < 100; j++)
		sum_temp += (ArrNumbers[j][i] - '0');
	sum_temp += carry;
	sum.push_back(sum_temp % 10 + '0');
	carry = sum_temp / 10;
	}

while(carry > 0)
	{
	sum.push_back(carry % 10 + '0');
	carry = carry / 10;
	}

for(int i = 0, j = sum.length() - 1; i < j; i++, j--)
	{
	char ch = sum[i];
	sum[i] = sum[j];
	sum[j] = ch;
	}

return sum;
}

int main(int argc, char *argv[])
{
vector<string> ArrNumbers(100);
CollectInput("Numbers.txt", ArrNumbers);
string value = AddLargeNumbers(ArrNumbers);
return 0;
}