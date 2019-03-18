#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <climits>
#include <iomanip>
#include <queue>
#include <set>
using namespace std;



typedef long long int lli;

#include <bits/stdc++.h>


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

lli lcm(lli a, lli b)
{
    return (a*b/gcd(a,b));
}

bool check(lli x)
{
    while(x%2 == 0)
    {
        x/=2;
    }
    while(x%3 == 0)
    {
        x/=3;
    }
    if(x != 1)
    {
        return false;
    }
    return true;
}

lli ans(int num, int n)
{
    if(n == 1)
    {
        return num;
    }
    else if(n == 2)
    {
        return num+1;
    }
    else if(n == 3)
    {
        return num+2;
    }
    else if(n%3 == 0)
    {
        return ans(num+2,(n-1)/2);
    }
    else if(n%2 == 0)
    {
        return ans(num+1,n/2);
    }
}

vector<lli> getprimes()
{
    vector <lli> pl(101,1);
    for(int i = 2; i<=100; i++)
    {
        if(pl[i] == 1)
        {
            for(int j = 2*i; j<=100; j+=i)
            {
                pl[j] = 0;
            }
        }
    }
    return pl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    lli n;
    cin >> n;
    int a[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    if(n == 1)
    {
        cout << a[0];
        return 0;
    }
    int g1,g2;
    if(a[0] > a[1])
    {
        g1 = a[0];
        g2 = a[1];
    }
    else
    {
        g2 = a[0];
        g1 = a[1];
    }
    if(n == 2)
    {
        cout << g2 << endl;
        return 0;
    }
    vector <int> b(n+1,0);
    vector <int> c(n+1,0);
    if(a[1] > a[0])
    {
        c[a[1]] = 1;
    }
    for(int i = 2; i<n; i++)
    {
        if(a[i] > g1)
        {
            c[a[i]] = 1;
            g2 = g1;
            g1 = a[i];
        }
        else if(a[i] < g1 && a[i] > g2)
        {
            b[g1]++;
            g2 = a[i];
        }
    }
    int max = 1;
    int nef = b[1] - c[1];
    for(int i = 1; i<=n; i++)
    {
        if(b[i] - c[i] > nef)
        {
            max = i;
            nef = b[i] - c[i];
        }
    }
    int index;
    for(int i = 0; i<n; i++)
    {
        if(a[i] == max)
        {
            index = i;
            break;
        }
    }
    if(index == 0 && b[max] == 0)
    {
        if(c[a[1]] == 1)
        {
            int temp = 0;
            for(int i = 1; i<n; i++)
            {
                if(c[a[i]] == 0 && temp == 0)
                {
                    max = a[i];
                    temp = 1;
                }
                if(temp == 1 && c[a[i]] == 0 && a[i] < max)
                {
                    max = a[i];
                }
            }
        }
    }
    else if(b[max] == 1 && c[max] == 1)
    {
        for(int i = 0; i<n; i++)
        {
            if(a[i] == max)
            {
                for(int j = i+1; j<n; j++)
                {
                    if(a[j] < max)
                    {
                        max = a[j];
                    }
                }

            }
        }
    }
    cout << max << endl;
}
