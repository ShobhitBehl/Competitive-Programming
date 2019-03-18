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
    lli n;
    cin >> n;
    pair<lli,lli> a[n];
    lli sum = 0;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i].second;
        sum += a[i].second;
    }
    for(int i = 0; i<n; i++)
    {
        cin >> a[i].first;
    }
    sort(a,a+n);
    lli temp = a[n-1].first + a[n-2].first;
    if(sum > temp)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
}
