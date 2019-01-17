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
#define mod 1000000007
#define pi 3.141592653589793238
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back

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
    if(b < a)
    {
        int temp = a;
        a = b;
        b = temp;
    }
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
            ans = ans%1000000009;
        }
        b/=2;
        a*=a;
        a = a%1000000009;
    }
    return ans%1000000009;
}

bool check(lli n,lli a,lli b)
{
    while(n > 0)
    {
        if(n%10 == a || n%10 == b)
        {
            n/=10;
        }
        else
        {
            return false;
        }
    }
    return true;
}

lli dist(int x1, int y1, int x2, int y2)
{
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n;
    cin >> n;
    char m[n][n];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin >> m[i][j];
        }
    }
    vector <lli> row(n,0),column(n,0);
    vector <pii> ans1,ans2;
    int flag,flag1;
    for(int i = 0; i<n; i++)
    {
        flag = 0;
        for(int j = 0; j<n; j++)
        {
            if(m[i][j] == '.')
            {
                //cout << i << " " << j << endl;
                row[i] = 1;
                ans1.push_back(mp(i,j));
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            break;
        }
    }
    //cout << endl;
    for(int i = 0; i<n; i++)
    {
        flag1 = 0;
        for(int j = 0; j<n; j++)
        {
            if(m[j][i] == '.')
            {
                //cout << i << " " << j << endl;
                column[i] = 1;
                ans2.push_back(mp(j,i));
                flag1 = 1;
                break;
            }
        }
        if(flag1 == 0)
        {
            break;
        }
    }
    //cout << endl;
    if(flag == 1 && flag1 == 0)
    {
        //cout << "1\n";
        for(int i = 0; i<ans1.size(); i++)
        {
            cout << ans1[i].first+1 << " " << ans1[i].second+1 << endl;
        }
    }
    else if(flag1 == 1 && flag == 0)
    {
        //cout << "2\n";
        for(int i = 0; i<ans2.size(); i++)
        {
            cout << ans2[i].first+1 << " " << ans2[i].second+1 << endl;
        }
    }
    else if(flag == 1 && flag1 == 1)
    {
        if(ans1.size() < ans2.size())
        {
            //cout << "3\n";
            for(int i = 0; i<ans1.size(); i++)
            {
                cout << ans1[i].first+1 << " " << ans1[i].second+1 << endl;
            }
        }
        else
        {
            //cout << "4\n";
            for(int i = 0; i<ans2.size(); i++)
            {
                cout << ans2[i].first+1 << " " << ans2[i].second+1 << endl;
            }
        }
    }
    else
    {
        cout << -1 << endl;
    }
}
