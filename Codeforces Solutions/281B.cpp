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

int gcd(int a,int b)
{
	if(b>a)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	if(b == 0)
	{
		return a;
	}
	else
	{
		return gcd(a%b,b);
	}
}

int main()
{
	int x,y,n;
	scanf("%d %d %d",&x,&y,&n);
	double og = x/y;
	int a,b;
	double mind = INT_MAX;
	for(int i = 1;i<=n; i++)
	{
		double app = 1.0*x*i/y;
		long num = app;
		if(app-num > 0.5)
		{
			num++;
		}
		pair <int,int> frac = make_pair(num,i);
		for(int j = 1;j<=sqrt(i);j++)
		{
			while(frac.first%j == 0 && frac.second == 0)
			{
				frac.first /= j;
				frac.second /= j;
			}
		}
		double diff = 1.0*frac.first/frac.second - 1.0*x/y;
		if(diff < 0)
		{
			diff = -diff;
		}
		if(diff < mind)
		{
			a = frac.first,b = frac.second;
			mind = diff;
		}
	}
	printf("%d/%d\n",a,b);
}
