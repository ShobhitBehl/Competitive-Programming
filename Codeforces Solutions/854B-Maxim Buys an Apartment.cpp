#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

long long int dot(long long int a[5],long long int b[5])
{
    long long int ans = 0;
    for(int i = 0; i<5; i++)
    {
        ans += a[i]*b[i];
    }
    return ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,k;
    cin >> n >> k;
    int min,max;
    if(n == k || k == 0)
    {
        min = 0;
        max = 0;
    }
    else
    {
        min = 1;
        if(k<=n/3)
        {
            max = 2*k;
        }
        else
        {
            max = n-k;
        }
    }
    cout << min << " " << max << endl;
}
