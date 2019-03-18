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
    vector < vector<int> > g(n+1);
    for(int i = 0; i<n-1;i++)
    {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector <int> col(n+1,0);
    stack <int> stk;
    stk.push(1);
    col[1] = 1;
    cout << endl;
    while(!stk.empty())
    {
        int top = stk.top();
        stk.pop();
        int t = g[top].size();
        for(int i = 0; i<t; i++)
        {
            if(col[g[top][i]] == 0)
            {
                stk.push(g[top][i]);
                if(col[top] == 1)
                {
                    col[g[top][i]] = 2;
                }
                else
                {
                    col[g[top][i]] = 1;
                }
            }
        }
    }
    lli s1 = 0,s2 = 0;
    for(int i = 1; i<=n; i++)
    {
        if(col[i] == 1)
        {
            s1++;
        }
        else
        {
            s2++;
        }
    }
    cout << s1*s2 - (n-1) << endl;
}
