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
	int n;
	cin >> n;
	vector <int> arr(n);
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	int dec = 0,inc = 0,len = 1,ans = 1,samelen = 1;
	for(int i = 1; i<n; i++)
	{
		if(arr[i] < arr[i-1])
		{
			samelen = 1;
			dec = 1;
			inc = 0;
			len++;
		}
		else if(arr[i] > arr[i-1])
		{
			if(dec == 1)
			{
				len = samelen + 1;
				inc = 1;
				dec = 0;
			}
			else if(dec != 1)
			{
				len++;
			}
			samelen = 1;
		}
		else
		{
			len++;
			samelen++;
		}
		if(len > ans)
		{
			ans = len;
		}
	}
	cout << ans << endl;
}

