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
    int a[n];
    int g;
    lli no = 0;
    cin >> a[0] >> a[1];
    if(a[0] == 1)
    {
        no++;
    }
    if(a[1] == 1)
    {
        no++;
    }
    g = gcd(a[0],a[1]);
    for(int i = 2; i<n; i++)
    {
        cin >> a[i];
        if(a[i] == 1)
        {
            no++;
        }
        g = gcd(g,a[i]);
    }
    lli steps,min = INT_MAX;
    if(g == 1 && no == 0)
    {
        for(int i = 0; i<n; i++)
        {
            steps=n;
            if(a[i] == 1)
            {
                break;
            }
            g = a[i];
            for(int j = i+1;j<n; j++)
            {
                g = gcd(g,a[j]);
                if(g == 1)
                {
                    steps=j-i;
                    break;
                }
            }
            if(steps < min)
            {
                min = steps;
            }
        }
        cout << min + n - 1 << endl;
    }
    else if(no > 0)
    {
        cout << n-no << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}
