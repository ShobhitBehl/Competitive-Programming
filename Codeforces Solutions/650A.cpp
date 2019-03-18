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

bool sortpair(pair <lli,lli> &a, pair <lli,lli> &b)
{
    return (b.first-b.second) > (a.first - a.second);
}

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

long long int min(long long int a, long long int b, lli c)
{
    if(a<=b && a<=c)
    {
        return a;
    }
    else if(b<=a && b<=c)
    {
        return b;
    }
    else
    {
        return c;
    }
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
    pair <int,int> a[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a,a+n);
    lli ans = 0;
    for(int i = 0; i<n; i++)
    {
        lli temp = 1;
        while(i+1 < n && a[i].first == a[i+1].first)
        {
            i++;
            temp++;
        }
        ans += temp*(temp-1)/2;
    }
    for(int i = 0; i<n; i++)
    {
        int temp = a[i].first;
        a[i].first = a[i].second;
        a[i].second = temp;
    }
    sort(a,a+n);
    for(int i = 0; i<n; i++)
    {
        lli temp = 1;
        while(i+1 < n && a[i].first == a[i+1].first)
        {
            i++;
            temp++;
        }
        ans += temp*(temp-1)/2;
    }
    for(int i = 0; i<n; i++)
    {
        lli temp = 1;
        while(i+1 < n && a[i].first == a[i+1].first && a[i].second == a[i+1].second)
        {
            temp++;
            i++;
        }
        ans -= temp*(temp-1)/2;
    }
    cout << ans << endl;
}
