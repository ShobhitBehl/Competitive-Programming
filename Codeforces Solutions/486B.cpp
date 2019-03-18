
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
	int m,n;
	cin >> m >> n;
	int A[m][n],B[m][n],C[m][n];
	for(int i = 0; i<m; i++)
	{
		for(int j = 0; j<n; j++)
		{
			cin >> A[i][j];
			B[i][j] = 1;
			C[i][j] = 0;
		}
	}
	for(int i = 0; i<m; i++)
	{
		for(int j  = 0; j<n; j++)
		{
			if(A[i][j] == 0)
			{
				for(int x = 0; x<n; x++)
				{
					B[i][x] = 0;
				}
				for(int x = 0; x<m; x++)
				{
					B[x][j] = 0;
				}
			}
		}
	}
	for(int i = 0; i<m; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(B[i][j] == 1)
			{
				for(int x = 0; x<n; x++)
				{
					C[i][x] = 1;
				}
				for(int x = 0; x<m; x++)
				{
					C[x][j]= 1;
				}
			}
		}
	}
	for(int i = 0; i<m; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(C[i][j] != A[i][j])
			{
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	for(int i = 0; i<m; i++)
	{
		for(int j = 0; j<n; j++)
		{
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
}