
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
using namespace std;

int lowbit(int n)
{
	return n&-n;
}

int main()
{
	int sum,limit;
	cin >>sum >>limit;
	vector <int> ans;
	for(int i = limit; i>0; i--)
	{
		int current;
		current = lowbit(i);
		if(sum >= current)
		{
			ans.push_back(i);
			sum -= current;
		}
	}
	if(sum == 0)
	{
		int len = ans.size();
		cout << len << endl;
		for(int i = 0; i<len; i++)
		{
			cout << ans[i] << " ";
		}
	}
	else
	{
		cout << -1;
	}
}