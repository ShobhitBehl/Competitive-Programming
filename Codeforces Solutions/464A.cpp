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
#include <list>
#include <deque>
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,p;
    cin >> n >> p;
    string s;
    cin >> s;
    if(p == 1)
    {
        cout << "NO\n";
        return 0;
    }
    if(n == 1)
    {
        if((s[0] - 'a')%p == p-1)
        {
            cout << "NO\n";
            return 0;
        }
        else
        {
            s[0]++;
            cout << s[0] << endl;
        }
    }
    else if(n == 2 && p == 2)
    {
        if(s[0] == 'a' && s[1] == 'b')
        {
            cout << "ba\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    else
    {
        for(int i = n-1; i>=0; i--)
        {
            int flag = 0;
            string t = s;
            while(t[i]-'a' < p-1)
            {
                t[i]++;
                if((i>=1 && t[i] == t[i-1]) || (i >= 2 && t[i] == t[i-2]))
                {
                    //cout << "rejected " << t[i] << endl;
                    continue;
                }
                //cout << "ac " << t[i] << endl;
                flag = 1;
                for(int j = i+1; j<n; j++)
                {
                    t[j] = 'a';
                    while((j>=1 && t[j] == t[j-1]) || (j >= 2 && t[j] == t[j-2]))
                    {
                        t[j]++;
                        //cout << t[j] << endl;
                    }
                    if(t[j]-'a' == p)
                    {
                        //cout << "this?\n";
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1)
                {
                    break;
                }
            }
            //cout << flag << endl;
            if(flag == 1)
            {
                cout << t << endl;
                return 0;
            }
        }
        cout << "NO\n";
    }
}
