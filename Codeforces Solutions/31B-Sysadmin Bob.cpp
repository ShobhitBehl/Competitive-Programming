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
	string add;
	cin >> add;
	int n = add.size();
	if(add[0] == '@' || add[n-1] == '@')
	{
		printf("No solution\n");
		return 0;
	}
	int c = 0;
	for(int i = 0; i<n; i++)
	{
		if(add[i] == '@')
		{
			c++;
			i++;
			int count = 0;
			while(add[i] != '@' && i<n)
			{
				count++;
				i++;
			}
			i--;
			if(count < 2 && i != n-1)
			{
				printf("No solution\n");
				return 0;
			}
		}
	}
	if(c == 0)
	{
		printf("No solution\n");
		return 0;
	}
	int d = 0;
	for(int i = 0; i<n; i++)
	{
		cout << add[i];
		if(add[i] == '@' && d != c-1)
		{
			d++;
			cout << add[i+1] << ",";
			i++;
		}
	}
}
