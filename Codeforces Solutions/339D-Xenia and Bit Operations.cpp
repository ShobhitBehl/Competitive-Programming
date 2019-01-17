#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <fstream>
#include <cmath>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

int pow(int a, int b)
{
	int ans = 1;
	while(b>0)
	{
		if(b%2 == 1)
		{
			ans *= a;
		}
		a *= a;
		b/=2;
	}
	return ans;
}

int maximum(int a, int b)
{
	return a>b ? a:b;
}

int main()
{
	int n,m;
	cin >> n >> m;
	n = pow(2,n);
	int seg = 2*n;
	int tree[seg];
	int arr[n+1];
	for(int i = 1; i<=n; i++)
	{
		cin >> arr[i];
	}
	for(int i = seg/2; i<seg; i++)
	{
		tree[i] = arr[i-(seg/2) + 1];		
	}
	int temp = seg/2;
	for(int x = 0; temp>1; x++)
	{
		for(int i = temp/2; i<temp; i++)
		{
			if(x%2 == 0)
			{
				tree[i] = tree[temp + 2*(i - (temp/2))] | tree[temp + 2*(i - (temp/2)) +1];
			}
			else
			{
				tree[i] = tree[temp + 2*(i - (temp/2))] ^ tree[temp + 2*(i - (temp/2)) +1];	
			}
		}
		temp /=2;
	}
	for(int i = 0; i<m; i++)
	{
		int a,b;
		cin >> a >> b;
		tree[a+n-1] = b;
		int temp = a+n-1;
		for(int i = 0; temp>1; i++)
		{
			if(temp%2 == 0)
			{
				if(i%2 == 0)
				{
					tree[temp/2] = tree[temp] | tree[temp+1];
				}
				else
				{
					tree[temp/2] = tree[temp] ^ tree[temp+1];
				}
			}
			else
			{
				if(i%2 == 0)
				{
					tree[temp/2] = tree[temp] | tree[temp-1];
				}
				else
				{
					tree[temp/2] = tree[temp] ^ tree[temp-1];
				}	
			}
			temp = temp/2;
		}
		cout << tree[1] << endl;
	}
}