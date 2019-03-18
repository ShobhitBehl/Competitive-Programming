
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
	char c;
	set <char> dist;
	while(1)
	{
		cin >> c;
		if(c == '}')
		{
			break;
		}
		else if(c != '{' && c != ',' && c != ' ')
		{
			dist.insert(c);
		}
	}
	cout << dist.size();
}