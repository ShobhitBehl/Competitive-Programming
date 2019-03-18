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
    queue <int> a,b;
    int temp;
    cin >> temp;
    lli ans = 0;
    for(int j = 0; j<temp; j++)
    {
        int x;
        cin >> x;
        a.push(x);
    }
    cin >> temp;
    for(int j = 0; j<temp; j++)
    {
        int x;
        cin >> x;
        b.push(x);
    }
    while(!a.empty() && !b.empty() && ans <= 39916800)
    {
        int x,y;
        ans++;
        x = a.front();
        y = b.front();
        a.pop();
        b.pop();
        if(x>y)
        {
            a.push(y);
            a.push(x);
        }
        else
        {
            b.push(x);
            b.push(y);
        }
    }
    if(a.empty())
    {
        cout << ans << " 2\n";
    }
    else if(b.empty())
    {
        cout << ans << " 1\n";
    }
    else
    {
        cout << -1 << endl;
    }
}
