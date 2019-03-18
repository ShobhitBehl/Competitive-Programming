
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
	int n;
	cin >> n;
	if(n >= 0)
	{
		cout << n << endl;
	}
	else
	{
		n = -n;
		int add = n%10;
		int div = n/10;
		if(add > (div)%10)
		{
			cout << -div << endl;
		}
		else
		{
			cout << -(((div/10)*10) + add);
		}
	}
}