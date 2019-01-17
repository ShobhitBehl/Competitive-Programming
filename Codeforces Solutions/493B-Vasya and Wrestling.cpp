
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
	long long int n;
	cin >> n;
	vector <long long int> first(n),second(n);
	long long int fs = 0,ss = 0,x;
	for(int i = 0; i<n; i++)
	{
		cin >> x;
		if(x > 0)
		{
			first.push_back(x);
			fs += x;
		}
		else
		{
			second.push_back(-x);
			ss -= x;
		}
	}
	if(fs > ss)
	{
		cout << "first\n";
		return 0;
	}
	else if(ss > fs)
	{
		cout << "second\n";
		return 0;
	}
	else
	{
		fs = first.size();
		ss = second.size();
		for(int i = 0; i<fs && i<ss; i++)
		{
			if(first[i] > second[i])
			{
				cout << "first\n";
				return 0;
			}
			else if(second[i] > first[i])
			{
				cout << "second\n";
				return 0;
			}
		}
		if(fs > ss)
		{
			cout << "first\n";
			return 0;
		}
		else if(ss > fs)
		{
			cout << "second\n";
			return 0;
		}
		else
		{
			if(x > 0)
			{
				cout << "first\n";
				return 0;
			}
			else
			{
				cout << "second\n";
				return 0;
			}
		}
	}
}