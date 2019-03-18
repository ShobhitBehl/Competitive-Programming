#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <fstream>
#include <cmath>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

long long int max(long long int i , long long int j)
{
	return i<j ? j:i;
}

int main()
{
	long long int n;
	cin >> n;
	long long int x;
	long long int buff[100001];
	long long int f[100001];
	for(int i = 0; i<n ;i++)
	{
		cin >> x;
		buff[x]++;
	}
	f[0] = 0;
	f[1] = buff[1];
	for(int i = 2; i<100001; i++)
	{
		f[i] = f[i-2] + (buff[i] * (long long)i);
		if(f[i-1] > f[i])
		{
			f[i] = f[i-1];
		}
	} 
	cout << f[100000] << endl;
}