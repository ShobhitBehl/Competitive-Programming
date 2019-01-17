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
	int n,k;
	cin >> n >> k;
	int arr[n];
	int ans = 0;
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
		if(arr[i] <= 5-k)
		{
			ans++;
		}
	}
	cout << ans/3 << endl;
}