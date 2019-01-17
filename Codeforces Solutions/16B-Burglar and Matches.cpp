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
	long long int n,m;
	cin >> n >> m;
	priority_queue < pair<long long int,long long int> , vector < pair<long long int,long long int> >,comparator > arr;
	for(int i = 0; i<m; i++)
	{
		long long int a,b;
		cin >> a >> b;
		arr.push(make_pair(b,a));
	}
	long long int ans = 0;
	while(n>0 && !arr.empty())
	{
		pair <long long int, long long int> temp;
		temp = arr.top();
		if(temp.second <= n)
		{
			n -= temp.second;
			ans += (temp.first*temp.second);
		}
		else
		{
			ans += (temp.first*n);
			n = 0;
		}
		arr.pop();
	}
	cout << ans << endl;
}
