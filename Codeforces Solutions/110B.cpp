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

struct compare
{
	bool operator()(int a, int b)
	{
		return a<b;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	string outstr = "";
	int len = n/4;
	for(int i = 0; i<len; i++)
	{
		outstr += "abcd";
	}
	if(n%4 == 1)
	{
		outstr += "a";
	}
	else if(n%4 == 2)
	{
		outstr += "ab";
	}
	else if(n%4 == 3)
	{
		outstr += "abc";
	}
	cout << outstr << endl;
}

