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
	double n,a;
	cin >> n >> a;
	int s = 1,mid = 2,e;
	double min = INT_MAX;
	double start = ((n-2.0)*180.0)/n;
	double diff = 180.0/n;
	for(int i = 1; i<=n-2; i++)
	{
		if(abs(start - a) < min)
		{
			min = abs(start - a);
			e = 2 + i;
		}
		start -= diff;
	}
	cout << s << " " << mid << " " << e << endl;
}