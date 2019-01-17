#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n,s,f;
	cin >> n >> s >> f;
	int arr[n+1];
	int flag[n+1];
	int count = 0;
	for(int i = 1; i<n+1; i++)
	{
		cin >> arr[i];
		flag[i] = 0;
	}
	while(1)
	{
		if(s == f)
		{
			cout << 0 << "\n";
			break;
		}
		if(arr[s] == f)
		{
			cout << count+1 << "\n";
			break;
		}

		else if(flag[arr[s]] == 1)
		{
			cout << "-1\n";
			break;
		}
		else
		{
			count++;
			flag[arr[s]] = 1;
			s = arr[s];
		}
	}
	return 0;
}