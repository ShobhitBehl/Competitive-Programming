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
	int n,m;
	scanf("%d %d",&n,&m);
	vector <string> arr(n);
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	vector <int> check(26);
	long long int ans = 1;
	for(int i = 0; i<m; i++)
	{
		long long int count = 0;
		fill(check.begin(),check.end(),0);
		for(int j = 0; j<n; j++)
		{
			if(check[arr[j][i] - 'A'] == 0)
			{
				count++;
				check[arr[j][i]-'A'] = 1;
			}
		}
		ans = (ans*count)%1000000007;
	}
	cout << ans << endl; 
}
