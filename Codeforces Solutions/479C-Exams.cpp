#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <fstream>
#include <cmath>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> &a, pair<int,int> &b)
{
    if((a.first < b.first) || (a.first == b.first && a.second < b.second))
    {
    	return true;
    }
    return false;
}


int main(){

    int n; 
    cin >> n;
    vector <pair<int,int> > arr(n);
    for(int i = 0; i<n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[i] = pair<int,int>(x, y);
    }
    sort(arr.begin(), arr.end(), comp);
    int ans(0);
    for(int i = 0; i<n; i++)
    {
        if(ans <= arr[i].second)
        {
        	ans = arr[i].second;
        }
        else
        {
        	ans = arr[i].first;
        }
    }
    cout << ans << endl;
}