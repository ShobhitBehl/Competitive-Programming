
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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
	int n,m,a,b;
	int cost = 0;
	cin >> n >> m >> a >> b;
	if(a*m > b)
	{
		cost += (n/m)*b;
		if(a*(n%m) < b)
		{
			cost += a*(n%m);
		}
		else
		{
			cost += b;
		}
	}
	else
	{
		cost += n*a;
	}
	cout << cost;
}