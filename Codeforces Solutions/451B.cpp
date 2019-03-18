
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
	int n;
	cin >> n;
	int arr[n],sorted[n];
	
	for(int i=0; i<n; i++) 
	{
		 cin >> arr[i];
		 sorted[i] = arr[i];
	}
	
	sort(sorted,sorted + n);
	int s = 0,e = 0;
	for(int i=0; i<n; i++)
	{
		if( arr[i] != sorted[i] ) 
		{
			s = i;
			break;    
		}
	}

	for(int i=n-1; i>=0; i--)
	{	
		if( arr[i] != sorted[i]) 
		{
			e = i;
			break;    
		}
	}

	for( int i=s, j=e; i<=e; i++,j--)
	{
		if(sorted[i] != arr[j])
		{
			cout << "no\n";
			return 0;
		}
	}

	cout << "yes" << endl << s + 1 << " " << e + 1 << endl;              
}
