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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int d,sumtime;
	vector <int> arr;
	vector < pair<int,int> > hours;
	cin >> d >> sumtime;
	for(int i = 0; i<d; i++)
	{
		int mintime,maxtime;
		cin >> mintime >> maxtime;
		hours.push_back(make_pair(mintime,maxtime));
		arr.push_back(mintime);
		sumtime -= mintime;
	}
	if(sumtime < 0)
	{
		cout << "NO\n";
	}
	else
	{
		for(int i = 0; i<d; i++)
		{
			if(sumtime >= hours[i].second - hours[i].first)
			{
				arr[i] = hours[i].second;
				sumtime = sumtime - (hours[i].second - hours[i].first);
			}
			else
			{
				arr[i] += sumtime;
				sumtime = 0;
			}
		}
		if(sumtime > 0)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
			for(int i = 0; i<d; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	}
}

