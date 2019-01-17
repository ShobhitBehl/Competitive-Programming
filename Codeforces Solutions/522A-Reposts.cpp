#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <fstream>
#include <cmath>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

int maximum(int a, int b)
{
	return a>b ? a:b;
}



int main()
{
	int n;
	cin >> n;
	map <string,int> len;
	len["polycarp"] = 1;
	int ans = 1;
	for(int i = 0; i<n; i++)
	{
		string to,from,useless;
		cin >> to >> useless >> from;
		transform(to.begin(),to.end(),to.begin(),::tolower);
		transform(from.begin(),from.end(),from.begin(),::tolower);
		len[to] = len[from] + 1;
		if(len[to] > ans)
		{
			ans = len[to];
		}
	}
	cout << ans << endl;
}