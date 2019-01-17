
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const double pi = 3.14159265359;

int main()
{
	int n,x0,y0;
	cin >> n >> x0 >> y0;
	long double arr[n];
	int it = 0,flag = 0;
	long double k;
	double x,y;
	int ans = 0;
	for(int i = 0; i<n; i++)
	{
		cin >> x >> y;
		if(flag == 0 && x - x0 == 0)
		{
			ans++;
			flag = 1;
		}
		else if(x - x0 != 0)
		{
			k = (y - y0)/(x - x0);
			arr[it++] = k;
		}
	}
	sort(arr, arr+it);
	for(int i = 0; i<it; i++)
	{
		while(arr[i] == arr[i+1] && i+1<it)
		{
			i++;
		}
		ans++;
	}
	cout << ans << endl;
}