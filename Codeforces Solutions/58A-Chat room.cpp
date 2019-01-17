#include <iostream>
#include <string>
using namespace std;

int main()
{
	string instr;
	cin >> instr;
	int len = instr.length();
	string outstr;
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if(count == 0 && instr[i] == 'h')
		{
			count++;
		}
		else if(count == 1 && instr[i] == 'e')
		{
			count++;
		}
		else if((count == 2 || count == 3) && instr[i] == 'l')
		{
			count++;
		}
		else if(count == 4 && instr[i] == 'o')
		{
			count++;
		}
		if(count == 5)
		{
			cout << "YES\n";
			break;
		}
	}
	if(count != 5)
	{
		cout << "NO\n";
	}
	//cout << outstr;
}