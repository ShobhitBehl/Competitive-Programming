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
	vector <int> add(2001,0),sub(2001,0);
	long long int ans = 0;
	for(int i = 0; i<n; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		ans += add[a+b];
		ans += sub[1000 + a-b];
		add[a+b]++;
		sub[1000 + a-b]++;
	}
	cout << ans << endl;
}