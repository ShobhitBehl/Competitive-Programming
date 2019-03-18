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
	int n;
	scanf("%d",&n);
	int arr[n];
	int dp[n];
	for(int i = 0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	int max = arr[n-1];
	dp[n-1] = 0;
	for(int i = n-2; i>=0; i--)
	{
		dp[i] = max;
		if(max < arr[i])
		{
			max = arr[i];
		}
	}
	for(int i = 0; i<n; i++)
	{
		if(dp[i] >= arr[i])
		{
			printf("%d ",dp[i]-arr[i]+1);
		}
		else
		{
			printf("0 ");
		}
	}
	printf("\n");
}
