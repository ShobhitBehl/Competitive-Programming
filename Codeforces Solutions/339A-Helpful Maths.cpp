#include <iostream>
#include <string>
using namespace std;

int main()
{
	string instr;
	cin >> instr;
	int len = instr.length();
	string outstr;
	int c1 = 0,c2 = 0,c3 = 0;
	for (int i = 0; i < len; i+=2)
	{
		if(instr[i] == '1')
		{
			c1++;
		}
		else if(instr[i] == '2')
		{
			c2++;
		}
		else
		{
			c3++;
		}
	}
	for(int i = 0; i<c1; i++)
	{
		outstr += '1';
		outstr += '+';
	}
	for(int i = 0; i<c2; i++)
	{
		outstr += '2';
		outstr += '+';
	}
	for(int i = 0; i<c3; i++)
	{
		outstr += '3';
		outstr += '+';
	}
	outstr.erase(len);
	cout << outstr;
}