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
	int n,m,x,y;
	scanf("%d %d %d %d",&n,&m,&x,&y);
	char mat[n][m];
	getchar();
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			scanf("%c",&mat[i][j]);
		}
		getchar();
	}
	int white[m+1];
	white[0] = 0;
	for(int i = 0; i<m;i++)
	{
		int count = 0;
		for(int j = 0; j<n; j++)
		{
			if(mat[j][i] == '.')
			{
				count++; 
			}
		}
		white[i+1] = count + white[i];
	}
	vector < vector<int> > dp(2,vector <int> (m+1,INT_MAX));
	dp[0][0] = 0,dp[1][0] = 0;
	for(int i = 1;i<=m; i++)
	{
		for(int j = x; j<=y; j++)
		{
			if(i-j >= 0 && i-j >= x)
			{
				int temp = white[i] - white[i-j] + dp[1][i-j];
				if(dp[0][i] > temp)
				{
					dp[0][i] = temp;
				}
				temp = (j*n) - (white[i] - white[i-j]) + dp[0][i-j];
				if(dp[1][i] > temp)
				{
					dp[1][i] = temp;
				}
			}
			else
			{
				int temp = white[i];
				if(dp[0][i] > temp)
				{
					dp[0][i] = temp;
				}
				temp = (i*n) - white[i];
				if(dp[1][i] > temp)
				{
					dp[1][i] = temp;
				}
				break;
			}
		}
	}
	printf("%d\n",min(dp[0][m],dp[1][m]));
}
