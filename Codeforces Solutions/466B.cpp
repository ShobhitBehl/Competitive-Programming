#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <climits>
#include <queue>
#include <set>
using namespace std;

typedef long long int lli;

lli power(lli a,lli b)
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
}


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
    lli n,h,w,origh,origw;
    cin >> n >> origh >> origw;
    h = origh;
    w = origw;
    if(h*w < 6*n)
    {
        lli min = LLONG_MAX;
        if(h<w)
        {
            for(int i = h; i<=ceil(sqrt(6*n)); i++)
            {
                lli tempw = ceil((6.0*n)/i);
                if(tempw < origw)
                {
                    continue;
                }
                if(i*tempw < min)
                {
                    h = i;
                    w = tempw;
                    min = i*tempw;
                }
            }
        }
        else
        {
            for(int i = w; i<=ceil(sqrt(6*n)); i++)
            {
                lli temph = ceil((6.0*n)/i);
                if(temph < origh)
                {
                    continue;
                }
                if(i*temph < min)
                {
                    w = i;
                    h = temph;
                    min = i*temph;
                }
            }
        }
    }
    cout << h*w << endl;
    cout << h << " " << w << endl;
}
