
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	int size = 2*n + 1;
	int arr[size];
	for(int i = 1; i<size; i++)
	{
		arr[i] = i;
	}
	for(int i = 0; i<k+1; i++)
	{
		int temp = arr[2*i - 1];
		arr[2*i - 1] = arr[2*i];
		arr[2*i] = temp;
	}
	for(int i = 1; i<size; i++)
	{
		cout << arr[i] << " ";
	}
}