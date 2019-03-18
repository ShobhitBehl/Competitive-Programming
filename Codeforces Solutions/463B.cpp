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
    cin >> n;
    int arr[n],ans = 0,curr = 0,e = 0;
    for(int i = 0; i<n; i++)
    {
    	cin >> arr[i];
    }
    for(int i = 0; i<n; i++)
    {
    	if(arr[i] > curr)
    	{
    		e += (curr - arr[i]);
    		if(e<0)
    		{
    			ans -= e;
    			e = 0;
    		}
    	}
    	else
    	{
    		e += curr - arr[i];
    	}
    	curr = arr[i];
    }
    cout << ans << endl;
}
