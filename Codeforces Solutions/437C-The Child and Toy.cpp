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

int minimum(int a, int b)
{
	return a>b ? b:a;
}

int main()
{
	int n,r;
	cin >>n >> r;
	int arr[n+1];
	for(int i = 1; i<=n; i++)
	{
		cin >> arr[i];
	}
	int ans = 0;
	for(int i = 0; i<r; i++)
	{
		int a,b;
		cin >> a >> b;
		ans += minimum(arr[a],arr[b]);
	}
	cout << ans << endl;
}