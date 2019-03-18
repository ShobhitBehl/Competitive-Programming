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
	int n,x0,maxl = INT_MIN,minr = INT_MAX;
	scanf("%d %d",&n,&x0);
	for(int i = 0; i<n; i++)
	{
		int r,l;
		scanf("%d %d",&l,&r);
		if(r<l)
		{
			int temp = r;
			r = l;
			l = temp;
		}
		if(l>maxl)
		{
			maxl = l;
		}
		if(r < minr)
		{
			minr = r;
		}
	}
	if(minr < maxl)
	{
		printf("-1\n");
	}
	else
	{
		if(x0 > maxl && x0 < minr)
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n",min(abs(minr-x0),abs(maxl-x0)));
		}
	}
}