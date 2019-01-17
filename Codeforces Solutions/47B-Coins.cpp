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
    string one,two,three;
    cin >> one >> two >> three;
    vector <int> arr(3,0);
    if(one[1] == '<')
    {
    	arr[one[2] - 'A']++;
    }
    else
    {
    	arr[one[0] - 'A']++;
    }
    if(two[1] == '<')
    {
    	arr[two[2] - 'A']++;
    }
    else
    {
    	arr[two[0] - 'A']++;
    }
    if(three[1] == '<')
    {
    	arr[three[2] - 'A']++;
    }
    else
    {
    	arr[three[0] - 'A']++;
    }
    int z = 0,o = 0,t = 0;
    for(int i = 0; i<3; i++)
    {
    	if(arr[i] == 0 && z == 0)
    	{
    		one = (char)('A' + i);
    		z++;
    	}
    	else if(arr[i] == 1 && o == 0)
    	{
    		two = (char)('A' + i);
    		o++;
    	}
    	else if(arr[i] == 2 && t == 0)
    	{
    		three = (char)('A' + i);
    		t++;
    	}
    	else
    	{
    		z = -1;
    		break;
    	}
    }
    if(z == -1)
    {
    	cout << "Impossible\n";
    }
    else
    {
    	cout << one << two << three << endl;
    }
}
