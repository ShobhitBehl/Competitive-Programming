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
 

struct comparator
{
	bool operator ()( pair <long long int,long long int> a,pair <long long int,long long int> b)
	{
		if(a.first == b.first)
		{
			return a.second < b.second;
		}
		return a.first < b.first;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    int len = str.size();
    long long int sum = 0,ans = 0;
    while(len != 1)
    {
    	sum = 0;
    	for(int i = 0; i<len; i++)
    	{
    		sum += (str[i] - '0');
    	}
    	stringstream ss;
    	ss << sum;
    	str = ss.str();
    	len = str.size();
    	ans++;
    }
    cout << ans << endl;
}
