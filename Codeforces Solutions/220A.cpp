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


int main()
{
	int n;
	scanf("%d",&n);
	vector <int> arr(n),sorted(n);
	for(int i = 0; i<n; i++)
	{
		scanf("%d",&arr[i]);
		sorted[i] = arr[i];
	}
	sort(sorted.begin(),sorted.end());
	int diff = 0;
	for(int i = 0; i<n; i++)
	{
		if(arr[i] != sorted[i])
		{
			diff++;
		}
	}
	if(diff > 2)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
}