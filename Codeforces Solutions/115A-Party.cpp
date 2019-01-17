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
	vector < vector<int> > graph(n+1);
	vector <int> groups(n+1,0);
	vector <int> start;
	int ans = 1;
	for(int i = 1; i<=n; i++)
	{
		int temp;
		cin >> temp;
		if(temp == -1)
		{
			groups[i] = 1;
			start.push_back(i);
		}
		else
		{
			graph[temp].push_back(i);
		}
	}
	int x = start.size();
	for(int i = 0; i<x; i++)
	{
		stack <int> s;
		s.push(start[i]);
		while(!s.empty())
		{
			int temp = s.top();
			s.pop();
			if(groups[temp] > ans)
			{
				ans = groups[temp];
			}
			int count = graph[temp].size();
			for(int j = 0; j<count; j++)
			{
				groups[graph[temp][j]] = groups[temp]+1;
				s.push(graph[temp][j]);
			}
		}
	}
	cout << ans << endl;
}