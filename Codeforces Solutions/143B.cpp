
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
using namespace std;

int main()
{
	string instr;
	cin >> instr;
	string numstr = "";
	string outstr = "";
	string decstr = "";
	int strlen = instr.size();
	for(int i = 0; i<strlen; i++)
	{
		if(instr[i] != '-' && instr[i] != ',')
		{
			if(instr[i] == '.')
			{
				if(i +1 < strlen)
				{
					decstr += instr[i+1];
				}
				if(i+2 < strlen)
				{
					decstr += instr[i+2];
				}
				break;
			}
			numstr += instr[i];
		}
	}
	if(instr[0] == '-')
	{
		outstr += "($";
	}
	else
	{
		outstr += "$";
	}
	strlen = numstr.size();
	for(int i = 0; i<strlen%3; i++)
	{
		outstr += numstr[i];
		if(i == (strlen%3) - 1)
		{
			outstr += ",";
		}
	}
	for(int i = 0; i+(strlen%3)<strlen+1; i++)
	{
		outstr += numstr[i + (strlen%3)];
		if((i+1)%3 == 0)
		{
			outstr += ",";
		}
	}
	outstr = outstr.substr(0,outstr.size()-2);
	if(decstr.size() == 0)
	{
		outstr += ".00";
	}
	else if(decstr.size() == 1)
	{
		outstr += "." + decstr + "0";
	}
	else
	{
		outstr += "." + decstr + "";
	}
	if(outstr[0] == '(')
	{
		outstr += ")";
	}
	cout << outstr << endl;
}