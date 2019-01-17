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
	int n,temp;
	scanf("%d",&n);
	long long int ind[n+1];
	for(int i = 0; i<n; i++)
	{
		scanf("%d",&temp);
		ind[temp] = i+1;
	}
	int m;
	long long ans1 = 0,ans2 = 0;;
	scanf("%d",&m);
	for(int i = 0; i<m; i++)
	{
		scanf("%d",&temp);
		ans1 += ind[temp];
		ans2 += n - ind[temp] + 1;
	}
	cout << ans1 << " " << ans2 << endl;
}
