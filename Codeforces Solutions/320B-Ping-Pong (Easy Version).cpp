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

bool DFS(int i,int n,vector <int> a,vector <int> b,int y)
{
	vector <bool> f(111,false);
	stack <int> s;
	s.push(i);
	while(!s.empty())
	{
		int temp = s.top();
		s.pop();
		f[temp] = true;
		for(int k = 1; k <= n;k++)
		{
			if(f[k])
			{
				continue;
			}
			if(a[temp]>a[k] && a[temp]<b[k])
			{
				s.push(k);
			}
			else if(b[temp]>a[k] && b[temp]<b[k])
			{
				s.push(k);
			}
		}
	}
	return f[y];
}


int k;

int main()
{
	cin >> k;
	vector <int> a(111,0),b(111,0);
	int n = 0;
	for(int i = 1; i <= k; i++)
	{
		int x,y,m;
		cin >> m;
		if(m == 1)
		{
			n++;
			cin >> a[n];
			cin >> b[n];
		}
		if(m == 2)
		{
			cin >> x;
			cin >> y;
			if(DFS(x,n,a,b,y))
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}