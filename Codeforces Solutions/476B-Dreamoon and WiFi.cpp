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

long double factorial(int n)
{
	long double ans = 1;
	for(int i = 1; i<=n; i++)
	{
		ans *= i;
	}
	return ans;
}

long double power(int a, int b)
{
	long double ans = 1;
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

int main()
{
	string control,dor;
	cin >> control >> dor;
	int len = control.size();
	int pos = 0,neg = 0;
	for(int i = 0; i<len; i++)
	{
		if(control[i] == '+')
		{
			pos++;
		}
		else
		{
			neg++;
		}
	}
	int dpos = 0,dneg = 0,ques = 0;
	for(int i = 0; i<len; i++)
	{
		if(dor[i] == '+')
		{
			dpos++;
		}
		else if(dor[i] == '-')
		{
			dneg++;
		}
		else
		{
			ques++;
		}
	}
	if(dpos > pos || dneg >neg)
	{
		cout << 0 << endl;
	}
	else if((pos - dpos) + (neg - dneg) == ques)
	{
		if(ques == 0)
		{
			cout << 1 << endl;
		}
		else
		{
			double ans = (factorial(ques)/(factorial(pos-dpos)*factorial(ques-pos+dpos)))/power(2,ques);
			printf("%.9lf",ans);
		}
	}
	else
	{
		cout << 0 << endl;
	}
}