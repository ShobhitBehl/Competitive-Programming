#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <fstream>
#include <cmath>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

int min(int arr[], int i, int j)
{
	return arr[i]>arr[j] ? j:i;
}

int max(int arr[], int i , int j)
{
	return arr[i]<arr[j] ? j:i;
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
	int temp;
	int i = 0;
	int ans = arr[0];
	while(i<n-3)
	{
		if(i+1)
		i = max(arr,i+1,i+2);
		if(arr[i] < ans)
		{
			ans = arr[i];
		}
	}
	if(arr[n-1] < ans)
	{
		ans = arr[n-1];
	}
	cout << ans << endl;
}