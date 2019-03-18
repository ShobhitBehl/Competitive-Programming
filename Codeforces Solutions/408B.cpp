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
	vector <int> arr(26,0);
	vector <int> gar(26,0);
	string a;
	cin >> a;
	int len = a.size();
	for(int i = 0; i<len; i++)
	{
		arr[a[i]-'a']++;
	}
	cin >> a;
	len = a.size();
	for(int i = 0; i<len; i++)
	{
		gar[a[i]-'a']++;
	}
	len = 0;
	for(int i = 0; i<26;i++)
	{
		if(gar[i] > 0 && arr[i] == 0)
		{
			len = 0;
			break;
		}
		if(arr[i] >= gar[i])
		{
			len += gar[i];
		}
		else
		{
			len += arr[i];
		}
	}
	if(len == 0)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << len << endl;
}

