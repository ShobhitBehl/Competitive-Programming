
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
	int n;
	cin >> n;
	vector <int> inhome(n),inaway(n),outhome(n),outaway(n);
	vector <int> colour(100001);
	for(int i =0 ;i<n; i++)
	{
		cin >> inhome[i] >> inaway[i];
		outhome[i] = n-1;
		colour[inhome[i]]++;
	}
	for(int i = 0; i<n; i++)
	{
		outhome[i] += colour[inaway[i]];
		outaway[i] += n-1-colour[inaway[i]];
	}
	for(int i = 0; i<n; i++)
	{
		cout << outhome[i] << " " << outaway[i] << endl;
	}
}
