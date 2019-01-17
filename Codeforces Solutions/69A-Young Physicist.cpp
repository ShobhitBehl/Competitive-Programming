
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
using namespace std;

struct dragon
{
	int energy,powerup;
	bool operator<(dragon const &a) const
	{
		return energy > a.energy;
	}
};

int main()
{
	int n;
	cin >> n;
	int xs(0),ys(0),zs(0);
	int in;
	for(int i = 0; i<n; i++)
	{
		cin >> in;
		xs += in;
		cin >> in;
		ys += in;
		cin >> in;
		zs += in;
	}
	if(xs != 0 || ys != 0 || zs != 0)
	{
		cout << "NO\n";
	}
	else
	{
		cout << "YES\n";
	}
}