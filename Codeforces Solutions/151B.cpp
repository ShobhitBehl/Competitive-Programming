
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
using namespace std;

int checknum(string instr)
{
	if(instr[0] == instr[1] && instr[1] == instr[3] && instr[3] == instr[4] && instr[4] == instr[6] && instr[6] == instr[7])
	{
		return 0;
	}
	else if( instr[0] > instr[1] && instr[1] > instr[3] && instr[3] > instr[4] && instr[4] && instr[4] > instr[6] && instr[6] > instr[7])
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

int main()
{
	int n,num;
	cin >> n;
	string name[n];
	string ans[3];
	int pizza = 0,taxi = 0, girl = 0;
	for(int i = 0; i<n;i++)
	{
		int t = 0, p = 0, g = 0;
		cin >> num;
		cin >> name[i];
		for(int j = 0; j<num; j++)
		{
			string number;
			cin >> number;
			int x = checknum(number);
			if(x == 0)
			{
				t++;
			}
			else if(x == 1)
			{
				p++;
			}
			else
			{
				g++;
			}
		}
		if(t > taxi || ans[0] == "")
		{
			taxi = t;
			ans[0] = name[i];
		}
		else if(t == taxi)
		{
			ans[0] += ", ";
			ans[0] += name[i];
		}
		if(p > pizza || ans[1] == "")
		{
			pizza = p;
			ans[1] = name[i];
		}
		else if(p == pizza)
		{
			ans[1] += ", ";
			ans[1] += name[i];
		}
		if(g > girl || ans[2] == "")
		{
			girl = g;
			ans[2] = name[i];
		}
		else if(g == girl)
		{
			ans[2] += ", ";
			ans[2] += name[i];
		}
	}
	cout << "If you want to call a taxi, you should call: " << ans[0] << "." << endl;
	cout << "If you want to order a pizza, you should call: " << ans[1] << "." << endl;
	cout << "If you want to go to a cafe with a wonderful girl, you should call: " << ans[2] << "." << endl;
}