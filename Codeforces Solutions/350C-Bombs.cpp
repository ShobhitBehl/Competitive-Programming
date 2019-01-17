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

int main()
{
	int n;
	scanf("%d",&n);
	vector < pair<int,int> > arr(n);
	int count = 0;
	for(int i = 0; i<n; i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(x == 0 || y == 0)
		{
			count += 4;
		}
		else
		{
			count += 6;
		}
		arr[i] = make_pair(x,y);
	}
	sort(arr.begin(),arr.end(),compare);
	cout << count << endl;
	for(int i = 0; i<n; i++)
	{
		if(arr[i].first > 0)
		{
			printf("1 %d R\n",arr[i].first);
		}
		else if(arr[i].first < 0)
		{
			printf("1 %d L\n",-arr[i].first);		
		}
		if(arr[i].second > 0)
		{
			printf("1 %d U\n",arr[i].second);
		}
		else if(arr[i].second < 0)
		{
			printf("1 %d D\n",-arr[i].second);
		}
		printf("2\n");
		if(arr[i].first > 0)
		{
			printf("1 %d L\n",arr[i].first);
		}
		else if(arr[i].first < 0)
		{
			printf("1 %d R\n",-arr[i].first);
		}
		if(arr[i].second > 0)
		{
			printf("1 %d D\n",arr[i].second);
		}
		else if(arr[i].second < 0)
		{
			printf("1 %d U\n",-arr[i].second);
		}
		printf("3\n");
	}
}
