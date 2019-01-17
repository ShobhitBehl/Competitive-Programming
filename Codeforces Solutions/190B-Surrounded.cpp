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

double max(double r1,double r2)
{
	return r1>r2?r1:r2;
}

double min(double r1, double r2)
{
	return r1<r2?r1:r2;
}

double dist(double x1,double x2,double y1, double y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
	double x1,y1,r1,x2,y2,r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	double d = dist(x1,x2,y1,y2);
	if(d > r1+r2)
	{
		printf("%.15lf\n",(d-r1-r2)/2.0);
	}
	else if(d<r1-r2 || d<r2-r1)
	{
		printf("%.15lf\n",(max(r1,r2) - d - min(r1,r2))/2.0);
	}
	else
	{
		printf("%.15lf\n",0.0);
	}
}