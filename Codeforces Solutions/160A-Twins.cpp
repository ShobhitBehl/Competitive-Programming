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
	int temp;
	int sum = 0,newsum = 0,ans = 0;
	priority_queue <int,vector<int>,compare> heap;
	for(int i = 0; i<n; i++)
	{
		cin >> temp;
		heap.push(temp);
		sum += temp;
	}
	while(newsum<=sum)
	{
		newsum += heap.top();
		sum -= heap.top();
		heap.pop();
		ans++;
	}
	cout << ans << endl;
}

