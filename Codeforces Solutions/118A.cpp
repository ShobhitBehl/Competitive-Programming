#include <iostream>
#include <string>
using namespace std;
int isvowel(string instr, int i)
{
	if(instr[i] == 'a' ||instr[i] == 'o' ||instr[i] == 'e' ||instr[i] == 'i' ||instr[i] == 'u' ||instr[i] == 'y' ||instr[i] =='A' ||instr[i] == 'O' ||instr[i] == 'E' ||instr[i] == 'I' ||instr[i] == 'U' ||instr[i] == 'Y')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	string instr;
	cin >> instr;
	int len = instr.length();
	string outstr;
	for (int i = 0; i < len; i++)
	{
		if(!isvowel(instr,i))
		{
			outstr += ".";
			outstr += tolower(instr[i]);
		}
	}
	cout << outstr;
}