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
    int n;
    cin >> n;
    int a[n+1];
    vector<int> b(n+1,-1);
    b[1] = 1;
    vector<int> c(n+1,-1);
    c[0] = 1;
    c[1] = 1;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i+1];
    }
    lli ans = 1;
    for(int i = 2; i<=n; i++)
    {
        /*if(c[a[i]] == -1)
        {
            c[i] = ans + 1;
            ans++;
            b[ans] = i;
        }*/
        //else
        //{
            if(b[c[a[i]]] == a[i])
            {
                b[c[a[i]]] = i;
                c[i] = c[a[i]];
            }
            else
            {
                c[i] = ans + 1;
                ans++;
                b[ans] = i;
            }
        //}
    }
    cout << ans << endl;
}
