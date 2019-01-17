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
	int b,g;
	cin >> b;
	vector <int> arr(b);
	for(int i = 0; i<b; i++)
	{
		cin >> arr[i];
	}
	cin >> g;
	vector <int> brr(g);
	for(int i = 0; i<g; i++)
	{
		cin >> brr[i];
	}
	sort(arr.begin(),arr.end());
	sort(brr.begin(),brr.end());
	int i = 0,j = 0;
	int ans = 0;
	while(i<b && j<g)
	{
		if(abs(arr[i] - brr[j]) <= 1)
		{
			i++;
			j++;
			ans++;
		}
		else if(arr[i] > brr[j])
		{
			j++;
		}
		else
		{
			i++;
		}
	}
	cout << ans << endl;
}