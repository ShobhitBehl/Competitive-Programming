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
	int n,m,k;
	cin >> n >> m >> k;
	char arr[n][m];
	int num[n][m];
	int dots = 0;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			cin >> arr[i][j];
			if(arr[i][j] == '.')
			{
				dots++;
			}
			num[i][j] = 0;
		}
		getchar();
	}
	queue< pair<int,int> > q;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if(arr[i][j] == '.')
			{
				q.push(pair<int,int>(i,j));
				num[i][j] = 1;
				break;
			}
		}
		if(!q.empty())
		{
			break;
		}
	}
	for(int i = 0; i < dots-k; i++)
	{
		int x,y;
		x = q.front().first;
		y = q.front().second;
		q.pop();
		num[x][y] = 2;
		if(x>0 && arr[x-1][y] == '.' && num[x-1][y] == 0)
		{
			q.push(pair<int,int>(x-1,y));
			num[x-1][y] = 1;
		}
		if(x+1<n && arr[x+1][y] == '.' && num[x+1][y] == 0)
		{
			q.push(pair<int,int>(x+1,y));
			num[x+1][y] = 1;	
		}
		if(y>0 && arr[x][y-1] == '.' && num[x][y-1] == 0)
		{
			q.push(pair<int,int>(x,y-1));
			num[x][y-1] = 1;
		}
		if(y+1<m && arr[x][y+1] == '.' && num[x][y+1] == 0)
		{
			q.push(pair<int,int>(x,y+1));
			num[x][y+1] = 1;
		}
	}
	while(!q.empty())
	{
		int x,y;
		x = q.front().first;
		y = q.front().second;
		q.pop();
		arr[x][y] = 'X';
		num[x][y] = 2;
		if(x>0 && arr[x-1][y] == '.' && num[x-1][y] == 0)
		{
			q.push(pair<int,int>(x-1,y));
			num[x-1][y] = 1;
		}
		if(x+1<n && arr[x+1][y] == '.' && num[x+1][y] == 0)
		{
			q.push(pair<int,int>(x+1,y));
			num[x+1][y] = 1;	
		}
		if(y>0 && arr[x][y-1] == '.' && num[x][y-1] == 0)
		{
			q.push(pair<int,int>(x,y-1));
			num[x][y-1] = 1;
		}
		if(y+1<m && arr[x][y+1] == '.' && num[x][y+1] == 0)
		{
			q.push(pair<int,int>(x,y+1));
			num[x][y+1] = 1;
		}	
	}
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
}