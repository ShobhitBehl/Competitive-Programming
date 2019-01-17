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
    long long int m,n,d;
    cin >> n >> m >> d;
    vector <int> arr(n*m);
    int size = n*m;
    int mod = INT_MAX;
    for(int i = 0; i<size; i++)
    {
    	cin >> arr[i];
    	if(i == 0)
    	{
    		mod = arr[i]%d;
    	}
    	else
    	{
    		if(arr[i]%d != mod)
    		{
    			cout << -1;
    			return 0;
    		}
    	}
    }
    int ans = 0;
    sort(arr.begin(),arr.end());
    mod = arr[size/2];
    for(int i = 0; i<size; i++)
    {
    	ans += abs(mod - arr[i])/d;
    }
    cout << ans << endl;
}

