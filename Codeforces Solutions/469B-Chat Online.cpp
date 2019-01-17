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

int intrsct(int a, int b, int c, int d)
{
	if(a>d || c>b)
	{
		return 0;
	}
	return 1;
}

int main()
{
	int p,q,l,r;
	cin >> p >> q >> l >> r;
	vector < pair<int,int> > a,b;
	int x,y;
	for(int i = 0; i<p; i++)
	{
		cin >> x >> y;
		a.push_back(make_pair(x,y));
	}
	for(int i = 0; i<q; i++)
	{
		cin >> x >> y;
		b.push_back(make_pair(x,y));
	}
	int ans = 0,flag = 0;
	for(int i = l; i<=r; i++)
	{
		flag = 0;
		for(int j = 0; j<q && flag == 0; j++)
		{
			for(int k = 0; k<p && flag == 0; k++)
			{
				flag = intrsct((b[j].first) + i,(b[j].second) + i,a[k].first,a[k].second);
				if(flag == 1)
				{
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}