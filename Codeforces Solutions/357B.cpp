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

struct compare
{
	bool operator()(int a, int b)
	{
		return a<b;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	vector <int> col(n+1,0);
	for(int i = 0; i<m; i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		if(col[a] == 0 && col[b] == 0 && col[c] == 0)
		{
			col[a] = 1;
			col[b] = 2;
			col[c] = 3;
		}
		else if(col[a] != 0)
		{
			col[b] = (col[a]+1)%3;
			if(col[b] == 0)
			{
				col[b] = 3;	
			}
			col[c] = (col[a]+2)%3;
			if(col[c] == 0)
			{
				col[c] = 3;	
			}
		}
		else if(col[b] != 0)
		{
			col[a] = (col[b]+1)%3;
			if(col[a] == 0)
			{
				col[a] = 3;	
			}
			col[c] = (col[b]+2)%3;	
			if(col[c] == 0)
			{
				col[c] = 3;	
			}
		}
		else if(col[c] != 0)
		{
			col[a] = (col[c]+1)%3;
			if(col[a] == 0)
			{
				col[a] = 3;	
			}	
			col[b] = (col[c]+2)%3;	
			if(col[b] == 0)
			{
				col[b] = 3;	
			}
		}
	}
	for(int i = 1; i<=n; i++)
	{
		cout << col[i] << " ";
	}
	cout << endl;
}

