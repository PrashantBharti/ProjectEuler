#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

string OnesAsString(unsigned int num, vector<string> &vcOnes)
{
return vcOnes[num % 10];
}

string TensAsString(unsigned int num, vector<string> &vcTens)
{
return num >= 10 && num < 20 ? vcTens[num - 10] : "";
}

string RestOfTensAsString(unsigned int num, vector<string> &vcTens, vector<string> &vcRestOfTens, vector<string> &vcOnes)
{
int Ones = num % 10;
int RestOfTens = num / 10;

if(RestOfTens == 0)
	return OnesAsString(Ones, vcOnes);

if(RestOfTens == 1)
	return TensAsString(num, vcTens);

if(RestOfTens > 9)
	return "";

string strResult = vcRestOfTens[RestOfTens - 2];
if(Ones > 0)
	{
	strResult.append(" ");
	strResult.append(OnesAsString(Ones, vcOnes));
	}

return strResult;
}

string HundredsAsString(unsigned int num, string strHundreds, vector<string> &vcTens, vector<string> &vcRestOfTens, vector<string> &vcOnes)
{
int Tens = num % 100;
int Hundreds = num / 100;

if(Hundreds == 0)
	return RestOfTensAsString(Tens, vcTens, vcRestOfTens, vcOnes);

if(Hundreds > 9)
	return "";

string strResult = vcOnes[Hundreds - 0];
strResult.append(" ");
strResult.append(strHundreds);

if(Tens > 0)
	{
	strResult.append(" ");
	strResult.append("and");
	strResult.append(" ");
	strResult.append(RestOfTensAsString(Tens, vcTens, vcRestOfTens, vcOnes));
	}

return strResult;
}

string ThousandsAsString(unsigned int num, string strThousand, string strHundreds, vector<string> &vcTens, vector<string> &vcRestOfTens, vector<string> &vcOnes)
{
int Hundreds = num % 1000;
int Thousands = num / 1000;

if(Thousands == 0)
	return HundredsAsString(Hundreds, strHundreds, vcTens, vcRestOfTens, vcOnes);

if(Thousands > 9)
	return "";

string strResult = vcOnes[Thousands - 0];
strResult.append(" ");
strResult.append(strThousand);

if(Hundreds > 0)
	{
	strResult.append(" ");
	if(Hundreds < 100)
		{
		strResult.append("and");
		strResult.append(" ");
		}
	strResult.append(HundredsAsString(Hundreds, strHundreds, vcTens, vcRestOfTens, vcOnes));
	}

return strResult;
}

unsigned int WordLength(string str)
{
unsigned int num = 0;

for(unsigned int i = 0; i < str.length(); i++)
	{
	if(str[i] == '\0')
		continue;
	if(str[i] == ' ')
		continue;
	num++;
	}

return num;
}

int main(int argc, char * argv)
{
vector<string> vcOnes;
vcOnes.push_back("Zero");
vcOnes.push_back("One");
vcOnes.push_back("Two");
vcOnes.push_back("Three");
vcOnes.push_back("Four");
vcOnes.push_back("Five");
vcOnes.push_back("Six");
vcOnes.push_back("Seven");
vcOnes.push_back("Eight");
vcOnes.push_back("Nine");

vector<string> vcTens;
vcTens.push_back("Ten");
vcTens.push_back("Eleven");
vcTens.push_back("Twelve");
vcTens.push_back("Thirteen");
vcTens.push_back("Fourteen");
vcTens.push_back("Fifteen");
vcTens.push_back("Sixteen");
vcTens.push_back("Seventeen");
vcTens.push_back("Eighteen");
vcTens.push_back("Nineteen");

vector<string> vcRestOfTens;
vcRestOfTens.push_back("Twenty");
vcRestOfTens.push_back("Thirty");
vcRestOfTens.push_back("Fourty");
vcRestOfTens.push_back("Fifty");
vcRestOfTens.push_back("Sixty");
vcRestOfTens.push_back("Seventy");
vcRestOfTens.push_back("Eighty");
vcRestOfTens.push_back("Ninty");

string strHundreds = "Hundred";
string strThousand = "Thousand";

unsigned long len = 0;
for(unsigned int i = 1; i <= 1000; i++)
	{
	string str = ThousandsAsString(i, strThousand, strHundreds, vcTens, vcRestOfTens, vcOnes);
	len += WordLength(str);
	}

return 0;
}