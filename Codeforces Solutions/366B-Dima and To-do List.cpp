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

int bs(vector <long long int> arr,long long int s)
{
	long long int l = 1,r = arr.size()-1;
	long long int ans = -1;
	while(l<=r)
	{
		int mid = (l+r)/2;
		if(arr[mid] - arr[mid-1] > s)
		{
			r = mid-1;
		}
		else if(arr[mid] - arr[mid-1] < s)
		{
			l = mid+1;
			ans = mid;
		}
		else
		{
			ans = mid;
			l = mid+1;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,m;
    cin >> n >> m;
    vector <int> arr(m,0);
    int min = INT_MAX;
    int minind;
    for(int i = 0;i<n; i++)
    {
    	int temp;
    	cin >> temp;
    	arr[i%m] += temp;
    	if(i >= n-m)
    	{
    		if(arr[i%m] < min)
    		{
    			min = arr[i%m];
    			minind = (i%m) + 1;
    		}
    	}
    }
    cout << minind << endl;
}

