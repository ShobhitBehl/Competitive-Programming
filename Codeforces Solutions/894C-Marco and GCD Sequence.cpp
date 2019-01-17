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
    vector <int> a(n);
    cin >> a[0];
    int g = a[0];
    for(int i = 1; i<n; i++)
    {
        cin >> a[i];
        g = gcd(g,a[i]);
    }
    if(find(a.begin(),a.end(),g) == a.end())
    {
        cout << -1 << endl;
    }
    else
    {
        cout << 2*n << endl;
        for(int i = 0; i<n; i++)
        {
            cout << a[i] << " " << g << " ";
        }
        cout << endl;
    }
}
