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
	vector < vector<int> > mat(n+1,vector <int>(m+1,0));
	int flag = 0;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			cin >> mat[i][j];
		}
	}
	if(m == 1)
	{
		for(int i = 1; i<=n; i++)
		{
			mat[i][1] += mat[i-1][1];
			cout << mat[i][1] << " ";
		}
		cout << endl;
		return 0;
	}
	for(int j = 2; j<=m; j++)
	{
		flag = 0;
		for(int i = 1; i<=n; i++)
		{
			if(i == 1)
			{
				mat[i][j] += mat[i][j-1];
				flag = mat[i][j];
			}
			else
			{
				if(j == 2)
				{
					mat[i][j-1] += mat[i-1][j-1];
				}
				if(mat[i][j-1] <flag)
				{
					mat[i][j] += flag;
					flag = mat[i][j];
				}
				else
				{
					mat[i][j] += mat[i][j-1];
					flag = mat[i][j];
				}
			}
			if(j == m)
			{
				cout << mat[i][j] << " ";
			}
		}
	}
	cout << endl;
}

