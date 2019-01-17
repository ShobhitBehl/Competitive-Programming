#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <fstream>
#include <cmath>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

int pow(int a, int b)
{
	int ans = 1;
	while(b>0)
	{
		if(b%2 == 1)
		{
			ans *= a;
		}
		a *= a;
		b/=2;
	}
	return ans;
}

int maximum(int a, int b)
{
	return a>b ? a:b;
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	int curr = 0;
	int ans = 0;
	for(int i = 0; i<n; i++)
	{
		ans += arr[i] - curr + 1;
		curr = arr[i];
		if(i == n-1)
		{
			break;
		}
		if(arr[i+1] >= curr)
		{
			ans++;
		}
		else
		{
			ans += curr - arr[i+1] + 1;
			curr = arr[i+1];
		}
	}
	cout << ans << endl; 
}