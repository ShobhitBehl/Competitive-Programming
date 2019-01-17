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
	long long int b = 0,s = 0,c = 0;
	string ham;
	cin >> ham;
	int len = ham.size();
	for(int i = 0; i<len; i++)
	{
		if(ham[i] == 'B')
		{
			b++;
		}
		else if(ham[i] == 'C')
		{
			c++;
		}
		else
		{
			s++;
		}
	}
	long long int nb,nc,ns,pb,ps,pc,r;
	cin >> nb >> ns >> nc >> pb >> ps >> pc >> r;
	long long int left = 0,right = 10000000000000;
	while(left+1<right)
	{
		long long mid = (left+right)/2;
		long long int cost = pb*max(0,(mid*b)-nb) + ps*max(0,(mid*s)-ns) + pc*max(0,(mid*c)-nc);
		if(cost<=r)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	cout << left << endl;
}
