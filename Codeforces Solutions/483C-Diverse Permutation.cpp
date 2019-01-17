#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <climits>
using namespace std;

int power(int a,int b)
{
    int ans;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            ans *= a;
        }
        b /=2;
        a*=a;
    }
    return ans;
}

long long int min(long long int a, long long int b)
{
    return a>b?b:a;
}

long long int max(long long int a, long long int b)
{
    return a>b?a:b;
}

struct t
{
    long long int si,fi,se;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    int l = 1,r = k+1;
    while(l <= r)
    {
        if(l == r)
        {
            cout << l << " ";
            l++;
            r--;
        }
        else
        {
            cout << l << " " << r << " ";
            l++;
            r--;
        }
    }
    for(int i = k+2; i<=n; i++)
    {
        cout << i << " ";
    }
}
