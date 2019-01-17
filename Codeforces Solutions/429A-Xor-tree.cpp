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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n;
    cin >> n;
    vector< vector<int> > g(n+1);
    for(int i = 0; i<n-1; i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int parents[n+1];
    parents[1] = -1;
    stack <int> s;
    vector <int> col(n+1,0);
    s.push(1);
    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        col[top] = 1;
        int temp = g[top].size();
        for(int i = 0; i<temp; i++)
        {
            if(col[g[top][i]] == 0)
            {
                col[g[top][i]] = 1;
                s.push(g[top][i]);
                parents[g[top][i]] = top;
            }
        }
    }
    /*for(int i = 1; i<=n; i++)
    {
        cout << parents[i] << endl;
    }*/
    int curr[n+1],need[n+1];
    for(int i = 1; i<=n; i++)
    {
        cin >> curr[i];
    }
    for(int i = 1; i<=n; i++)
    {
        cin >> need[i];
    }
    vector <int> nodes;
    vector <int> flip(n+1,0);
    lli ans = 0;
    if(need[1] != curr[1])
    {
        flip[1]++;
        ans++;
        nodes.push_back(1);
    }
    s.push(1);
    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        col[top] = 0;
        if(parents[top] == 1)
        {
            if(curr[top] != need[top])
            {
                flip[top]++;
                ans++;
                nodes.push_back(top);
            }
        }
        if(top != 1 && parents[top]!=1)
        {
            if(curr[top] != need[top] && flip[parents[parents[top]]]%2 == 0)
            {
                flip[top] = flip[parents[parents[top]]]+1;
                ans++;
                nodes.push_back(top);
            }
            else if(curr[top] == need[top] && flip[parents[parents[top]]]%2 != 0)
            {
                flip[top] = flip[parents[parents[top]]]+1;
                ans++;
                nodes.push_back(top);
            }
            else
            {
                flip[top] = flip[parents[parents[top]]];
            }
        }
        int temp = g[top].size();
        for(int i = 0; i<temp; i++)
        {
            if(col[g[top][i]] == 1)
            {
                s.push(g[top][i]);
                col[g[top][i]] = 0;
            }
        }
    }
    cout << ans << endl;
    n = nodes.size();
    for(int i = 0; i<n; i++)
    {
        cout << nodes[i] << endl;
    }
}
