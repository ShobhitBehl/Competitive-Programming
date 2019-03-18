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

string binary(int n)
{
	string outstr;
	while(n>0)
	{
		if(n%2 == 1)
		{
			outstr += "1";
		}
		else
		{
			outstr += "0";
		}
		n/=2;
	}
	return outstr;
}

int decimal(string s)
{
	int len = s.size();
	int ans = 0;
	for(int i = len-1; i>=0; i--)
	{
		if(s[i] == '1')
		{
			ans = 10*ans + 1;
		}
		else
		{
			ans = 10*ans;
		}
	}
	return ans;
}

int main()
{
	int n;
	scanf("%d",&n);
	int ans = 0;
	while(decimal(binary(ans+1)) <= n)
	{
		ans++;
	}
	printf("%d\n",ans);
}