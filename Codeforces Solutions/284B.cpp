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
 

struct comparator
{
	bool operator ()( pair <long long int,long long int> a,pair <long long int,long long int> b)
	{
		if(a.first == b.first)
		{
			return a.second < b.second;
		}
		return a.first < b.first;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n; 
	char arr[n];
	int ni = 0,na = 0;
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
		if(arr[i] == 'A')
		{
			na++;
		}
		else if(arr[i] == 'I')
		{
			ni++;
		}
	}
	if(ni >=2)
	{
		cout << 0 << endl;
	}
	else if(ni == 1)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << na << endl;
	}
}
