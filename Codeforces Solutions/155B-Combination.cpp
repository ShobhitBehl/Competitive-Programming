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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int ans = 0;
	int count = 1;
	int n;
	cin >> n;
	vector < pair<int,int> > arr;
	for(int i = 0; i<n; i++)
	{
		int a,b;
		cin >> a >> b;
		arr.push_back(make_pair(-b,-a));
	}
	sort(arr.begin(),arr.end());
	for(int i = 0; i<n; i++)
	{
		if(count == 0)
		{
			break;
		}
		count--;
		count -= arr[i].first;
		ans -= arr[i].second;  
	}
	cout << ans << endl;
}

