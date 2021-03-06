#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <fstream>
#include <cmath>
#include <sstream>
#include <bits/stdc++.h>
#include <climits>
#include <set>
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

int factorial(int x)
{
	int ans = 1;
	for(int i = 2;i<=x; i++)
	{
		ans*=i;
	}
	return ans;
}

int compstr(string a,string b)
{
	if(a.size()>b.size())
	{
		return 1;
	}
	else if(a.size() == b.size())
	{
		int temp = a.size();
		for(int i = 0; i<temp; i++)
		{
			if(a[i] - '0' > b[i] - '0')
			{
				return 1;
			}
			else if(a[i] - '0' < b[i] - '0')
			{
				return 0;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	scanf("%d",&n);
	pair <int,int> tv1,tv2;
	vector < pair <int,int> > a(n);
	for(int i = 0; i<n; i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		a[i] = make_pair(x,y);
	}
	sort(a.begin(),a.end());
	tv1 = a[0];
	tv2 = a[1];
	for(int i = 2; i<n; i++)
	{
		if(a[i].first > tv1.second)
		{
			tv1 = a[i];
		}
		else if(a[i].first > tv2.second)
		{
			tv2 = a[i];
		}
		else
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}
