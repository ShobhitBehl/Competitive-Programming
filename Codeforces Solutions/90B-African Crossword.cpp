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
	int n,m;
	cin >> n >> m;
	vector < vector <int> > row(n,vector<int>(26,0));
	vector < vector <int> > col(m,vector<int>(26,0));
	char arr[n][m];
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			cin >> arr[i][j];
			row[i][arr[i][j] - 'a']++;
			col[j][arr[i][j] - 'a']++;
		}
	}
	for(int i  = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if(row[i][arr[i][j] - 'a'] >1 || col[j][arr[i][j] - 'a'] >1)
			{
				arr[i][j] = '_';
			}
		}
	}
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if(arr[i][j] != '_')
			{
				cout << arr[i][j];
			}
		}
	}
	cout << endl;
}
