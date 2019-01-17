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
	int c,v0,v1,a,l;
	cin >> c >> v0 >> v1 >> a >> l;
	int curr = 0;
	long long int ans = 1;
	while(1)
	{
		if(v0>v1)
		{
			v0 = v1;
		}
		curr += v0;
		if(curr >= c)
		{
			break;
		}
		curr -= l;
		v0 += a;
		ans++;
	}
	cout << ans << endl;
}