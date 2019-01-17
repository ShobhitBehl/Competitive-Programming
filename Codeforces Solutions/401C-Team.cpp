
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
using namespace std;

int main()
{
	int z,o;
	cin >> z >> o;
	string outstr;
	if(o < z-1 || o > 2*(z+1))
	{
		cout << -1;
		return 0;
	}
	else if(o == z-1 || o == z)
	{	
		for(int i = 0; i<o; i++)
		{
			outstr += "01";
		}
		if(o == z-1)
		{
			outstr += "0";
		}
	}
	else if(o >= z+1)
	{
		int x;
		if(o == 2*(z+1))
		{
			x = z+1;
		}
		else
		{
			x = o%(z+1);
		}
		if(o == z+1)
		{
			outstr += "1";
		}
		else
		{
			outstr += "11";
			x--;
		}
		for(int i = 0; i<z; i++)
		{
			if(x > 0)
			{
				outstr += "011";
			}
			else
			{
				outstr += "01";
			}
			x--;
		}
	}
	cout << outstr;
}