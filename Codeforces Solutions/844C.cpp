#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int bs(int l,int r, int*arr, int key)
{
    //cout << "bc" << endl;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] > key)
        {
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    return -1;
}

int main()
{
	ios::sync_with_stdio(0);
    int n;
    scanf("%d",&n);
    int a[n];
    int b[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&a[i]);
        b[i] = a[i];
    }
    sort(a,a+n);
    int d[n];
	int t[n];
    vector <int> c(n,0);
    int temp,x = 0,z = 0;
    for(int i = 0; i<n ;i++)
    {
        int y = i;
        if(c[y] == 0)
        {
            c[y] = 1;
            d[x] = y;
			x++;
            while(1)
            {
                temp = bs(0,n-1,a,b[y]);
                //cout << temp << endl;
                if(c[temp] == 1)
                {
					t[z] = x;
					z++;
                    break;
                }
                d[x] = temp;
				x++;
                c[temp] = 1;
                y = temp;
            }
        }
    }
    printf("%d\n",z);
	int j = 0;
    for(int i = 0; i<z; i++)
    {
        if(!t[i])
            continue;
		if(i == 0)
		{
        	printf("%d ",t[i]);
		}
		else
		{
			printf("%d ",t[i]-t[i-1]);
		}
		for(;j<t[i];)
		{
			printf("%d ",d[j]+1);
			j++;
		}
        printf("\n");
    }
}
