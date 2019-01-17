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
	int n,a;
	cin >> n >> a;
	int arr[n+1];
	for(int i = 1; i<=n; i++)
	{
		cin >> arr[i];
	}
	int d = 0,ans = 0;
	while(a+d<=n || a-d > 0)
	{
		if(d == 0)
		{
			if(arr[a] == 1)
			{
				ans ++;
			}
		}
		else if(a+d <= n && a-d >0)
		{
			if(arr[a+d] == 1 && arr[a-d] == 1)
			{
				ans += 2;
			}
		}
		else if(a+d <= n && arr[a+d] == 1)
		{
			ans++;
		}
		else if(a-d > 0 && arr[a-d] == 1)
		{
			ans++;
		}
		d++;
	}
	cout << ans << endl;
}
