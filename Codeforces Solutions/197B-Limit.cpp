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

int gcd(int a, int b)
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
	return gcd(a%b,b);
}

int main()
{
	int n,m;
	cin >> n >> m;
	int a1,a2;
	cin >> a1;
	int waste;
	for(int i = 0; i< n; i++)
	{
		cin >> waste;
	}
	cin >> a2;
	for(int i = 0; i<m; i++)
	{
		cin >> waste;
	}
	if(n>m)
	{
		if((a1>0 && a2>0) || (a1<0 && a2<0))
		{
			cout << "Infinity\n";
		}
		else
		{
			cout << "-Infinity\n";
		}
	}
	else if(m>n)
	{
		cout << "0/1\n";
	}
	else
	{
		if(a1>0 && a2>0)
		{
			cout << a1/gcd(a1,a2) <<  "/" << a2/gcd(a1,a2) << endl;
		}
		else if(a1<0 && a2<0)
		{
			cout << -a1/gcd(-a1,-a2) << "/" << -a2/gcd(-a1,-a2) << endl;
		}
		else
		{
			if(a1<0)
			{
				cout << a1/gcd(-a1,a2) << "/" << a2/gcd(-a1,a2) << endl;
			}
			else
			{
				cout << -a1/gcd(a1,-a2) << "/" << -a2/gcd(a1,-a2) << endl;	
			}
		}	
	}
}