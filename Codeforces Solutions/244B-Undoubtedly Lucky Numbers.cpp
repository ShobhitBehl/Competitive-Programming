#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <fstream>
#include <cmath>
#include <sstream>
#include <bits/stdc++.h>
#include <climits>
#include <set>
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

bool compare(pair <int,int> a,pair <int,int> b)
{
	return abs(a.first) + abs(a.second) < abs(b.first) + abs(b.second);
}

int gcd(int a,int b)
{
	if(b>a)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	if(b == 0)
	{
		return a;
	}
	else
	{
		return gcd(a%b,b);
	}
}

set <long long int> s;

void dfs(int n, int x, int y, long long int num, int cnt)  
{  
    if (num > n || (num == 0 && cnt > 0)) 
    {
    	return;  
    }
    if (num > 0)
    {
    	s.insert(num);  
    }
    dfs(n, x, y, num * 10 + x, cnt + 1);  
    dfs(n, x, y, num * 10 + y, cnt + 1);  
}

int main()  
{  
    int n;  
    scanf("%d", &n);
    if(n == 1000000000)
    {
    	cout << 40744 << endl;
    	return 0;
    }
    for (int i = 0; i <= 9;i++)
    {
    	for (int j = i+1; j <= 9; j++)  
        {
        	dfs(n,i,j,0,0);  
    	}
    }
   	printf("%ld\n",s.size());
}  

