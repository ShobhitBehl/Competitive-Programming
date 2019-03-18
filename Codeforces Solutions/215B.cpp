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
	scanf("%d",&n);
	double maxr1 = 0,maxp1 = 0,minp2 = INT_MAX;
	int temp;
	for(int i = 0; i<n; i++)
	{
		scanf("%d",&temp);
		if(temp > maxr1)
		{
			maxr1 = temp;
		}
	}
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		scanf("%d",&temp);
		if(temp > maxp1)
		{
			maxp1 = temp;
		}
	}
	cin >> n; 
	for(int i = 0; i<n; i++)
	{
		scanf("%d",&temp);
		if(temp < minp2)
		{
			minp2 = temp;
		}
	}
	double a,b;
	scanf("%lf %lf",&a,&b);
	double ans = maxr1 * sqrt((b * maxp1) / (b * maxp1 + a * minp2));
	printf("%.12f\n",ans);
}