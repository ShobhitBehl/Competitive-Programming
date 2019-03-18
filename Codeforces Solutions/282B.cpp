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
	int n;
	scanf("%d",&n);
	int sa = 0;
	for(int i = 0; i<n; i++)
	{
		int a,g;
		scanf("%d %d",&a,&g);
		sa += a;
		if(sa <= 500)
		{
			printf("A");
		}
		else
		{
			sa -= 1000;
			printf("G");
		}
	}
	printf("\n");
}

