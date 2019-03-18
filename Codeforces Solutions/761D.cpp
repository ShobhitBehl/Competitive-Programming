#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <climits>
using namespace std;

int power(int n)
{
    int a = 1;
    while(1)
    {
        if(a>=n)
        {
            return a;
        }
        a*=2;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,l,r;
    cin >> n >> l >> r;
    long long int a[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    long long int max = INT_MIN;
    long long int min = INT_MAX;
    for(int i = 0; i<n; i++)
    {
        long long int t;
        cin >> t;
        a[i] += t;
        if(a[i] > max)
        {
            max = a[i];
        }
        if(a[i] < min)
        {
            min = a[i];
        }
    }
    if(max <= r && min >= l)
    {
        for(int i = 0; i<n; i++)
        {
            cout << a[i] << " ";
        }
    }
    else if(max > r && min - max + r >= l)
    {
        for(int i = 0; i<n; i++)
        {
            cout << a[i] - max + r << " ";
        }
    }
    else if(min < l && max + l - min <= r)
    {
        for(int i = 0; i<n; i++)
        {
            cout << a[i] + l - min << " ";
        }
    }
    else
    {
            cout << -1 << endl;
    }
}
