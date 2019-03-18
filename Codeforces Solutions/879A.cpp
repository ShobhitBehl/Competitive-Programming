#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <climits>
using namespace std;

/*lli power(lli a,lli b)
{
    lli ans;
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
}*/

typedef long long int lli;

lli gcd(lli a, lli b)
{
    if(a == 0)
    {
        return b;
    }
    return gcd(b%a,a);
}

long long int min(long long int a, long long int b)
{
    return a>b?b:a;
}

long long int max(long long int a, long long int b)
{
    return a>b?a:b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,ans = 0,si,di,curr = 0;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> si >> di;
        if(si > curr)
        {
            curr = si;
            ans = si;
        }
        else
        {
            while(si <= curr)
            {
                si += di;
            }
            curr = si;
            ans = si;
        }
    }
    cout << ans << endl;
}
