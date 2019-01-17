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
	int n,dest;
	cin >> n >> dest;
	int arr[n];
	for(int i = 1; i<n; i++)
	{
		cin >> arr[i];
	}
	int curr = 1;
	while(1)
	{
		if(curr == dest)
		{
			cout << "YES\n";
			break;
		}
		if(curr > dest)
		{
			cout << "NO\n";
			break;
		}
		curr += arr[curr];
	}
}