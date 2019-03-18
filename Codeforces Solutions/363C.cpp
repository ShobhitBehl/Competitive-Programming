#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <fstream>
#include <cmath>
#include <sstream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

int power(int a,int b)
{
	int ans = 1;
	while(b>0)
	{
		if(b%2 == 1)
		{
			ans *= a;
		}
		a*=a;
		b/=2;
	}
	return ans;
}

long long int max(long long int a, long long int b)
{
	return a>b?a:b;
}

long long int min(long long int a, long long int b)
{
	return a>b?b:a;
}

bool compare(pair <int,int> a,pair <int,int> b)
{
	return abs(a.first) + abs(a.second) < abs(b.first) + abs(b.second);
}

int main()
{
	string instr;
	cin >> instr;
	int len = instr.size();
	int s = 2;
	vector <char> outstr;
	if(len < 2)
	{
		outstr.push_back(instr[0]);
	}
	else
	{
		outstr.push_back(instr[0]);
		outstr.push_back(instr[1]);
	}
	for(int i = 2; i<len; i++)
	{
		if(instr[i] == outstr[s-1] && instr[i] == outstr[s-2])
		{
			continue;
		}
		else if(instr[i] == outstr[s-1] && outstr[s-2] == outstr[s-3])
		{
			continue;
		}
		else
		{
			outstr.push_back(instr[i]);
			s++;
		}
	}
	len = outstr.size();
	for(int i = 0; i<len; i++)
	{
		cout << outstr[i];
	}
	cout << endl;
}
