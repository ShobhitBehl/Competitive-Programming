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
    while(n != 1)
    {
    	cout << n << " ";
    	for(int i = 2; i<=n; i++)
    	{
    		if(n%i == 0)
    		{
    			n = n/i;
    			break;
    		}
    	}
    }
    cout << n << endl;
}

