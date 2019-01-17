
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const double pi = 3.14159265359;

int main()
{
	int m,n;
	cin >> m >> n;
	char arr[m][n];
	for(int i = 0; i<m; i++)
	{
		for(int j = 0; j<n; j++)
		{
			cin >> arr[i][j];
		}
	}
	int count = 0;
	for(int i = 0; i<m; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(arr[i][j] == 'W')
			{
				if(arr[i-1][j] == 'P' && i-1>-1)
				{
					arr[i-1][j] = '.';
					count++;
				}
				else if(arr[i+1][j] == 'P' && i+1<m)
				{
					arr[i+1][j] = '.';
					count++;
				}
				else if(arr[i][j+1] == 'P' && j+1<n)
				{
					arr[i][j+1] = '.';
					count++;
				}
				else if(arr[i][j-1] == 'P' && j-1>-1)
				{
					arr[i][j-1] = '.';
					count++;
				}
			}
		}
	}
	cout << count;
}