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

lli ans(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else if(n == 1 || n == 2)
    {
        return 0;
    }
    else if(n<0)
    {
        return 0;
    }
    else
    {
        return (ans(n-7) | ans(n-3));
    }
}

lli primefactorise(int n)
{
    if(n == 1)
    {
        return 1;
    }
    lli ans = n;
    while (n%2 == 0)
    {
        n = n/2;
        if(n != 1)
        {
            ans += n;
        }
    }

    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            n = n/i;
            if(n != 1)
            {
                ans += n;
            }
        }
    }
    ans += 1;
    return ans;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    lli n;
    cin >> n;
    lli sq = 0, nsq = 0;
    lli a[n];
    lli b[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
        lli x = sqrt(a[i]);
        if(x*x == a[i])
        {
            b[i] = 0;
            sq++;
        }
        else
        {
            b[i] = min((x+1)*(x+1) - a[i],a[i] - (x*x));
            nsq++;
        }
    }
    lli ans = 0;
    if(sq > nsq)
    {
        lli hold = 0;
        for(int i = 0; i<n; i++)
        {
            if(b[i] == 0)
            {
                if(a[i] == 0)
                {
                    hold++;
                }
                else
                {
                    ans += 1;
                    sq--;
                    nsq++;
                }
            }
            if(sq == nsq)
            {
                break;
            }
        }
        if(sq != nsq)
        {
            while(sq != nsq)
            {
                hold--;
                ans += 2;
                sq--;
                nsq++;
            }
        }
    }
    else if(nsq > sq)
    {
        sort(b,b+n);
        for(int i = 0; i<n; i++)
        {
            if(b[i] != 0)
            {
                ans += b[i];
                sq++;
                nsq--;
            }
            if(sq == nsq)
            {
                break;
            }
        }
    }
    cout << ans << endl;
}
