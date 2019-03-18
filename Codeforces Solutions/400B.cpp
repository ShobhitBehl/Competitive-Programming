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

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	char arr[n][m];
	set <int> dp;
	getchar();
	for(int i = 0; i<n; i++)
	{
		int flag = -1;
		for(int j = 0; j<m; j++)
		{
			scanf("%c",&arr[i][j]);
			if(arr[i][j] == 'G')
			{
				flag = j;
			}
			else if(arr[i][j] == 'S')
			{
				if(flag == -1)
				{
					cout << -1 << endl;
					return 0;
				}
				else
				{
					dp.insert(j-flag);
				}
			}
		}
		getchar();
	}
	cout << dp.size() << endl;
}