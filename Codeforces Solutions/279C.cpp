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

int power(int a,int b)
{
	int ans = 1;
	while(b>0)
	{
		if(b%2 == 1)
		{
			ans *= a;
		}
		a*=a;
		b/=2;
	}
	return ans;
}

long long int max(long long int a, long long int b)
{
	return a>b?a:b;
}

long long int min(long long int a, long long int b)
{
	return a>b?b:a;
}

bool compare(pair <int,int> a,pair <int,int> b)
{
	return abs(a.first) + abs(a.second) < abs(b.first) + abs(b.second);
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int arr[n],inc[n],dec[n];
	for(int i = 0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	dec[n-1] = n-1;
	inc[n-1] = n-1;
	for(int i = n-2;i>=0;i--)
	{
		if(arr[i] > arr[i+1])
		{
			dec[i] = dec[i+1];
			inc[i]= i;
		}
		else if(arr[i] < arr[i+1])
		{
			dec[i] = i;
			inc[i] = inc[i+1];
		}
		else
		{
			dec[i] = dec[i+1];
			inc[i] = inc[i+1];
		}
	}
	for(int i = 0; i<m; i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		if(dec[inc[l-1]] >=r-1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}
