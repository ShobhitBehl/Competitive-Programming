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

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	while(b>0)
	{
		if(b%2 == 1)
		{
			ans *= a;
		}
		a *= a;
		b /= 2;
	}
	return ans;
}

int main()
{
	long long int n,k;
	cin >> n >> k;
	vector <long long int> ans;
	if(k<=32)
	{
		vector <long long int> arr;
		arr.push_back(1);
		arr.push_back(1);
		for(int i = 1;i<=k-1;i++)
		{
			arr.push_back(2*(arr.back()));
		}
		while(1)
		{
			long long int next = 2*(arr.back()) - arr[arr.size()-k-1];
			if(next < n)
			{
				arr.push_back(next);
			}
			else
			{
				break;
			}
		}
		long long int start = arr.size()-1;
		while(n > 0)
		{
			if(arr[start] <= n)
			{
				ans.push_back(arr[start]);
				n-=arr[start];
			}
			start--;
		}
	}
	else
	{
		long long int start = power(2,32);
		while(n>0)
		{
			if(start <= n)
			{
				ans.push_back(start);
				n -= start;
			}
			start/=2;
		}
	}
	long long int len = ans.size();
	if(len == 1)
	{
		len ++;
		ans.push_back(0); 
	}
	cout << len << endl;
	for(int i = len-1; i>=0; i--)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
}