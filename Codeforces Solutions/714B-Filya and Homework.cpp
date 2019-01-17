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

int main()
{
	int n,temp;
	scanf("%d",&n);
	set <int> arr;
	vector <int> list(3);
	for(int i = 0; i<n ; i++)
	{
		scanf("%d",&temp);
		arr.insert(temp);
	}
	if(arr.size() < 3)
	{
		cout << "YES\n";
	}
	else if(arr.size() > 3)
	{
		cout << "NO\n";
	}
	else
	{
		set <int> :: iterator it;
		int x = 0;
		for(it = arr.begin(); it!=arr.end(); it++)
		{
			list[x++] = *it;
		} 
		sort(list.begin(),list.end());
		if(list[1] - list[0] == list[2] - list[1])
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}