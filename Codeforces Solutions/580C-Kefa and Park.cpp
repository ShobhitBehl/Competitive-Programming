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
	int n,k;
	cin >> n >> k;
	vector < pair<int,int> > cats(n+1);
	for(int i = 1; i<=n; i++)
	{
		int temp;
		cin >> temp;
		cats[i].first = temp;
		cats[i].second = 0;
	}
	vector < vector<int> > graph(n+1);
	for(int i = 1; i<n; i++)
	{
		int n1,n2;
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}
	stack <int> s;
	s.push(1);
	cats[1].second = 1;
	int ans = 0;
	while(!s.empty())
	{
		int t = s.top();
		s.pop();
		cats[t].second = 2;
		int count = graph[t].size();
		if(count == 1 && t != 1)
		{
			ans++;
		}
		for(int i = 0; i<count; i++)
		{
			if(cats[graph[t][i]].second != 2)
			{
				if(cats[graph[t][i]].first + cats[t].first > k)
				{
					continue;
				}
				else
				{
					if(cats[graph[t][i]].first != 0)
					{
						cats[graph[t][i]].first += cats[t].first;
					}
					s.push(graph[t][i]);
					cats[graph[t][i]].second = 1;
				}
			}
		}
	}
	cout << ans << endl;
}