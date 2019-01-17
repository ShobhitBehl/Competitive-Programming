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

lli power(lli a,lli b)
{
    lli ans = 1;
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

struct enemy
{
    lli sh,mh,r;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,l;
    cin >> n >> l;
    lli powers[n];
    powers[0] = 1;
    for(int i = 1; i<n; i++)
    {
        powers[i] = 2*powers[i-1];
    }
    lli c[n];
    pair <double,lli> eff[n];
    for(int i = 0; i<n; i++)
    {
        cin >> c[i];
        eff[i].first = (double)c[i]/powers[i];
        eff[i].second = i;
    }
    sort(eff,eff+n);
    lli ans =  1e18;
    lli temp = 0;
    for(int i = 0; i<n; i++)
    {
        if(powers[eff[i].second] <= l)
        {
            lli num = l/powers[eff[i].second];
            temp += num*c[eff[i].second];
            l-=powers[eff[i].second]*num;
            //cout << "taking " << powers[eff[i].second] << " " << num << endl;
            if(l == 0)
            {
                ans = min(ans,temp);
            }
            else
            {
                ans = min(ans,temp + c[eff[i].second]);
            }
        }
        else if(l < powers[eff[i].second])
        {
            ans = min(ans,temp + c[eff[i].second]);
            //cout << "taking " << powers[eff[i].second] << " " << 1 << endl;
        }
        else if(l<=0)
        {
            ans = min(ans,temp);
        }
    }
    cout << ans << endl;
}
