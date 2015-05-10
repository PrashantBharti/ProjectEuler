#include <iostream>
using namespace std; 

int Factors(unsigned long num)
{
if(num == 1)
	return 1;

int nbFactors = 0;
unsigned long maxFactor = num;

unsigned int counter = 1;
while(counter < maxFactor)
	{
	if(num % counter == 0)
		{
		if(num / counter == counter)
			nbFactors += 1;
		else
			nbFactors += 2;

		maxFactor = num / counter;
		}
	counter++;
	}

return nbFactors;
}

unsigned long TriangleNumber(long num)
{
return unsigned long ((num*(num + 1)) / 2);
}

int main(int argc, char *argv[])
{
int counter = 1;
unsigned long trianglenumber = 0;
do
	{
	trianglenumber = TriangleNumber(counter);
	counter++;
	}
while(Factors(trianglenumber) <= 500);

cout << trianglenumber;
return 0;
}