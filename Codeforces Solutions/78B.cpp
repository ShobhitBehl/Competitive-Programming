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
 

struct comparator
{
	bool operator ()( pair <long long int,long long int> a,pair <long long int,long long int> b)
	{
		if(a.first == b.first)
		{
			return a.second < b.second;
		}
		return a.first < b.first;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	string out;
	while(n>0)
	{
		if(n>=7)
		{
			out += "VIBGYOR";
			n-=7;
		}
		else
		{
			if(n == 6)
			{
				out += "VIBGYO";
			}
			else if(n == 5)
			{
				out += "VIBGY";
			}
			else if(n == 4)
			{
				out += "VIBG";
			}
			else if(n == 3)
			{
				out += "BGY";
			}
			else if(n == 2)
			{
				out += "BG";
			}
			else if(n == 1)
			{
				out += "G";
			}
			n = 0;
		}
	}
	cout << out << endl;
}
