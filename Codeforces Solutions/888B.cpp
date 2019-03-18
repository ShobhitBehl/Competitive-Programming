#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <climits>
#include <queue>
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

struct comparator {
 bool operator()(lli i, lli j) {
 return i > j;
 }
};

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
    lli n;
    cin >> n;
    string s;
    cin >> s;
    lli ans = 0;
    lli r = 0,d = 0,u = 0,l = 0;
    for(int i = 0; i<n; i++)
    {
        if(s[i] == 'R')
        {
            r++;
        }
        else if(s[i] == 'L')
        {
            l++;
        }
        else if(s[i] == 'U')
        {
            u++;
        }
        else
        {
            d++;
        }
    }
    ans += 2*min(l,r);
    ans += 2*min(u,d);
    cout << ans <<endl;
}
