#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
size_t szPrimeNumbers = 0;
cout << "Enter the number of Prime Numbers required: ";
cin >> szPrimeNumbers;

vector<unsigned int> vcPrimes;
vcPrimes.push_back(2);

unsigned int iNumber = 3;
while(szPrimeNumbers > vcPrimes.size())
	{
	bool bIsPrime = true;
	for(size_t i = 0; vcPrimes[i] <= (iNumber/2) && i < vcPrimes.size(); ++i)
		{
		if(iNumber % vcPrimes[i] == 0)
			{
			bIsPrime = false;
			break;
			}
		}

	if(bIsPrime)
		vcPrimes.push_back(iNumber);

	++iNumber;
	}

cout << "First " << szPrimeNumbers << " prime numbers are:" << endl;
for(auto i : vcPrimes)
	cout << i << endl;

return 0;
}