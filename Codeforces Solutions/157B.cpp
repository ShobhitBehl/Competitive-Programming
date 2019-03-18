
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const double pi = 3.14159265359;

int main() 
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	sort(arr,arr+n);
	long double sum = 0;
	for(int i = n-1; i>=0; i-=2)
	{
		sum += arr[i] * arr[i];
		if(i-1>=0)
		{
			sum -= arr[i-1] * arr[i-1];
		}
	}
	cout << pi*sum;
}