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
	int n;
	cin >> n;
	int sum = 0;
	int cups[n];
	vector < pair<int,int> > arr; 
	for(int i = 0; i<n; i++)
	{
		int temp;
		cin >> temp;
		sum += temp;
		cups[i] = temp;
	}
	if(sum != (sum/n) * n)
	{
		cout << "Unrecoverable configuration.\n";
		return 0;
	}
	sum = sum/n;
	for(int i = 0; i<n; i++)
	{
		if(cups[i] != sum)
		{
			arr.push_back(make_pair(cups[i],i+1));
		}
	}
	if(arr.size() > 2)
	{
		cout << "Unrecoverable configuration.\n";		
	}
	else if(arr.size() == 0)
	{
		cout << "Exemplary pages.\n";
	}
	else
	{
		if(arr[0].first < arr[1].first)
		{
			cout << abs(sum-arr[0].first) << " ml. from cup #" << arr[0].second << " to cup #" << arr[1].second << ".\n"; 
		}
		else
		{
			cout << abs(sum-arr[0].first) << " ml. from cup #" << arr[1].second << " to cup #" << arr[0].second << ".\n"; 				
		}
	}
}