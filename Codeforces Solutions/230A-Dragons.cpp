
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
	int S,n;
	cin >> S >> n;
	priority_queue <dragon> heap;
	for(int i = 0; i<n; i++)
	{
		dragon d;
		cin >> d.energy >> d.powerup;
		heap.push(d);
	}
	while(!heap.empty())
	{
		if(S > heap.top().energy)
		{
			S += heap.top().powerup;
			heap.pop();
		}
		else
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}