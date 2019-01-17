#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;

struct data
{
	int level,hour;
	bool operator<(const data &a) const
	{
		return level < a.level;
	}
};

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	priority_queue<data> q;
	int n,k;
	vector <int> out;
	fin >> n >> k;
	for(int i = 0; i<n; i++)
	{
		data x;
		fin >> x.level;
		x.hour = i+1;
		q.push(x);
	}
	for(int i = 0; i<k; i++)
	{
		data temp;
		temp = q.top();
		if(i == k-1)
		{
			fout << temp.level << endl;
		}
		out.push_back(temp.hour);
		q.pop();
	}
	for(int i = 0; i<k; i++)
	{
		if(i == k-1)
		{
			fout << out[i];
		}
		else
		{
			fout << out[i] << " ";
		}
	}
	fout << endl;
	out.clear();
}