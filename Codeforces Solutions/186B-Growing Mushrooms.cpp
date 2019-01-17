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

double min(double v1,double v2)
{
	return v1>v2?v2:v1;
}
double max(double v1, double v2)
{
	return v1<v2?v2:v1;
}

int main()
{
	double n;
	double t1,t2;
	double k;
	cin >> n >> t1 >> t2 >> k;
	vector < pair<double,int> > arr(n);
	for(int i = 0; i<n; i++)
	{
		double v1,v2;
		cin >> v1 >> v2;
		double len = 0;
		if(t1<t2)
		{
			len += t1*min(v1,v2);
			len -= (k/100)*len;
			len += t2*max(v1,v2);
			arr[i] = make_pair(-len,i+1);
		}
		else
		{
			len += t1*max(v1,v2);
			len -= (k/100)*len;
			len += t2*min(v1,v2);
			double temp = 0;
			temp += t1*min(v1,v2);
			temp -= (k/100)*temp;
			temp += t2*max(v1,v2);
			if(temp>len)
			{
				len = temp;
			}
			arr[i] = make_pair(-len,i+1);
		}
	}
	sort(arr.begin(),arr.end());
	for(int i = 0;i<n; i++)
	{
		printf("%d %.2lf\n",arr[i].second,-arr[i].first);
	}
}