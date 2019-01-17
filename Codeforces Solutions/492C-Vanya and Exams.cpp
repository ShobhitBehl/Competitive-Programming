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
    long long int n,r,avg;
    cin >> n >> r >> avg;
    pair <long long int,long long int> a[n];
    long long int x = 0;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i].second >> a[i].first;
        x += a[i].second;
    }
    long long int y = n*avg;
    long long int ans = 0;
    if(x >= y)
    {
        cout << 0 << endl;
        return 0;
    }
    x = y-x;
    sort(a,a+n);
    for(int i = 0; i<n; i++)
    {
        if(r-a[i].second < x)
        {
            x -= (r-a[i].second);
            ans += (r-a[i].second)*a[i].first;
        }
        else
        {
            ans += x*(a[i].first);
            break;
        }
    }
    cout << ans << endl;
}
