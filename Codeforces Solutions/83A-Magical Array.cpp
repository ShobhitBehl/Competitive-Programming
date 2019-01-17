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
	long long int n;
	cin >> n;
	long long int prev;
	cin >> prev;
	long long int ans = 0,temp,len = 1;
	for(int i = 1;i<n;i++)
	{
		cin >> temp;
		if(temp == prev)
		{	
			len++;
		}
		else
		{
			ans += (len*(len+1))/2;
			len = 1;
			prev = temp;
		}
	}
	ans += (len*(len+1))/2;
	cout << ans << endl;
}