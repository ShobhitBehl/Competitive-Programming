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

int power(int a,int b)
{
	int ans = 1;
	while(b>0)
	{
		if(b%2 == 1)
		{
			ans *= a;
		}
		a*=a;
		b/=2;
	}
	return ans;
}

long long int max(long long int a, long long int b)
{
	return a>b?a:b;
}

long long int min(long long int a, long long int b)
{
	return a>b?b:a;
}


int main()
{

    int n; 
    scanf("%d",&n);
    int s = -1, f = -1, m = INT_MAX;

    for(int i = n / 7; i >= 0; i--)
    {
        if((n - 7*i) % 4 != 0)
        {
        	continue;
        }
        f = (n - 7 * i) / 4;
        s = i;
        m = s + f;
        break;
    }


    if(s >= 0 && f >= 0)
    {
        for(int i = 0; i<f; i++)
        {
        	printf("4");
        }
        for(int i = 0; i<s; i++)
        {
        	printf("7");
        }
    }
    else
    {
    	printf("-1");
    }
    return 0;
}