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

int move(int n,int x,int dx)
{
	if(dx>0)
	{
		return (n-x)/dx;
	}
	else
	{
		return -(x-1)/dx;
	}
}

int main()
{
	int n,m;
	int x,y;
	scanf("%d %d %d %d",&n,&m,&x,&y);
	int t;
	scanf("%d",&t);
	long long int ans = 0;
	for(int i = 0; i<t; i++)
	{
		int dx,dy,temp1;
		scanf("%d %d",&dx,&dy);
		if(dx == 0)
		{
			temp1 = move(m,y,dy);
		}
		else if(dy == 0)
		{
			temp1 = move(n,x,dx);
		}
		else
		{
			temp1 = min(move(m,y,dy),move(n,x,dx));
		}
		x += temp1*dx;
		y += temp1*dy;
		ans += temp1;
	}
	cout << ans << endl;
}