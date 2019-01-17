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
    long long int ans = 0;
    string instr;
    cin >> instr;
    string bits;
    int len = instr.size();
    for(int i = 0; i<len; i++)
    {
    	if(instr[i] == '>')
    	{
    		bits += "1000";
    	}
    	else if(instr[i] == '<')
    	{
    		bits += "1001";
    	}
    	else if(instr[i] == '+')
    	{
    		bits += "1010";
    	}
    	else if(instr[i] == '-')
    	{
    		bits += "1011";
    	}
    	else if(instr[i] == '.')
    	{
    		bits += "1100";
    	}
    	else if(instr[i] == ',')
    	{
    		bits += "1101";
    	}
    	else if(instr[i] == '[')
    	{
    		bits += "1110";
    	}
    	else if(instr[i] == ']')
    	{
    		bits += "1111";
    	}
    }
   	len = 4*len;
   	for(int i = 0; i<len; i++)
   	{
   		ans = (ans*2)%1000003;
   		if(bits[i] == '1')
   		{
   			ans += 1;
   		}
   	}
   	cout << ans << endl;
}

