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
	vector<int> num;
	int n;
	cin >> n;
	vector < pair<int,int> > arr(100001,make_pair(-1,0));
	for(int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		if(arr[temp].first == -1)
		{
			arr[temp].first = i;
			arr[temp].second = 0;
			ans++;
			num.push_back(temp);
		}
		else if(arr[temp].first == -2)
		{
			continue;
		}
		else
		{
			if(arr[temp].second == 0)
			{
				arr[temp].second = i - arr[temp].first;
				arr[temp].first = i;
			}
			else
			{
				if(i - arr[temp].first != arr[temp].second)
				{
					arr[temp].first = -2;
					ans--;
				}
				else
				{
					arr[temp].first = i;
				}
			}
		}
	}
	cout << ans << endl;
	ans = num.size();
	sort(num.begin(),num.end());
	for(int i = 0; i<ans; i++)
	{

		if(arr[num[i]].first != -1 && arr[num[i]].first != -2)
		{
			cout << num[i] << " " << arr[num[i]].second << endl;
		}
	}
}

