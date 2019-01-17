
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int digsum(long long int n)
{
	int sum = 0;
	while(n != 0)
	{
		sum += n%10;
		n /= 10;
	}
	return sum;
}

long long int solve(int b, long long int c)
{
	long long int det = sqrt((b*b)+(4*c));
	long long int sol = (-b + det)/2;
	if(det * det == (b*b) + (4*c))
	{
		return sol;
	}
	return 0;
}

int main()
{
	long long int n,x;
	cin >> n;
	for(int i = 1; i<91; i++)
	{
		long long int s = solve(i,n);
		if(s == 0)
		{
			continue;
		}
		if (digsum(s) == i)
		{
			cout << s;
			return 0;
		}
	}
	cout << -1 << endl;
}