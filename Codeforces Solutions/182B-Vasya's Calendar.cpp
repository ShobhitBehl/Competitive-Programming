
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
using namespace std;

int main()
{
	int d,n;
	cin >> d >> n;
	int ai,ans = 0;
	for(int i = 0; i<n-1; i++)
	{
		cin >> ai;
		ans += d-ai;
	}
	cout << ans;
}