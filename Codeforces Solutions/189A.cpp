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
	int n;
	vector <int> arr(3);
	cin >> n >> arr[0] >> arr[1] >> arr[2];
	sort(arr.begin(),arr.end());
	vector <int> max(4001,-10000000);
	max[0] = 0;
	max[arr[0]] = 1;
	max[arr[1]] = 1;
	max[arr[2]] = 1;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 0; j<3; j++)
		{
			if(arr[j] > i)
			{
				break;
			}
			max[i] = maximum(max[i-arr[j]]+1,max[i]);
		}
	}
	cout << max[n] << endl;
}