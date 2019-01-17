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

string standard(string s)
{
	string outstr;
	int len = s.size();
	for(int i = 0; i<len; i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
		{
			outstr += s[i]; 
		}
		else if(s[i] >= 'A' && s[i] <= 'Z')
		{
			outstr += s[i] - 'A' + 'a';
		}
	}
	return outstr;
}

int main()
{
	string s1,s2,s3;
	cin >> s1 >> s2 >> s3;
	s1 = standard(s1);
	s2 = standard(s2);
	s3 = standard(s3);
	int n;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		string check;
		cin >> check;
		check = standard(check);
		if(check == s1+s2+s3 || check == s1+s3+s2 || check == s2+s1+s3 || check == s2+s3+s1 || check == s3+s1+s2 || check == s3+s2+s1)
		{
			cout << "ACC\n";
		}
		else
		{
			cout << "WA\n";
		}
	}
}