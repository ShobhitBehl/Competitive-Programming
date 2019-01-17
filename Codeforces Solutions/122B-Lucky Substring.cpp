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
    string instr;
    int four = 0,seven = 0;
    cin >> instr;
    int len = instr.size();
    for(int i = 0; i<len ;i++)
    {
    	if(instr[i] == '4')
    	{
    		four++;
    	}
    	else if(instr[i]== '7')
    	{
    		seven++;
    	}
    }
    if(four == 0 && seven == 0)
    {
    	cout << -1 << endl;
    }
    else if(four >= seven)
    {
    	cout << 4 << endl;
    }
    else
    {
    	cout << 7 << endl;
    }

}

