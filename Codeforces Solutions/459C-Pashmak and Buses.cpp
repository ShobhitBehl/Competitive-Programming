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
	long long int n,k,d;
	cin >> n >> k >> d;
	int x = 1;
	for(int i = 0;i<d; i++)
	{
		x*=k;
		if(x >= n)
		{
			x = -1;
			break;
		}
	}
	if(x != -1)
	{
		cout << "-1\n";
		return 0;
	}
	x = 1;
	for(int i = 0; i<d; i++)
	{
		for(int j = 0; j<n; j++)
		{
			cout << 1 + (j/x)%k << " ";
		}
		cout << endl;
		if(x < n)
		{
			x *= k;
		}
	}
}