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

double min(double a, double b, double c, double d)
{
    double arr[4] = {a,b,c,d};
    sort(arr,arr+4);
    return arr[0];
}

double min(double a, double b, double c)
{
    double arr[3] = {a,b,c};
    sort(arr,arr+3);
    return arr[0];
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
            ans = ans;
        }
        b/=2;
        a*=a;
        a = a;
    }
    return ans;
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

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

lli product(lli i)
{
    lli ans = 1;
    while(i > 0)
    {
        if(i%10 != 0)
        {
            ans *= (i%10);

        }
        i/=10;
    }
    return ans;
}

bool isvowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,m,k;
    cin >> n >> m >> k;
    lli a[k+1];
    a[0] = 0;
    map <lli,lli> maps;
    for(int i = 1; i<=k; i++)
    {
        cin >> a[i];
        a[i] += a[i-1];
        for(int j = a[i-1] + 1; j<=a[i]; j++)
        {
            maps[j] = i;
        }
    }
    vector < vector <lli> > g(n+1);
    vector < vector <lli> > ans(k,vector<lli>(k,INT_MAX));
    for(int i = 0; i<k; i++)
    {
        for(int j = 0; j<k ;j++)
        {
            if(i == j)
            {
                ans[i][j] = 0;
            }
        }
    }
    for(int i = 0; i<m; i++)
    {
        lli u,v,x;
        cin >> u >> v >> x;
        if(x == 0)
        {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans[maps[u]-1][maps[v]-1] = min(x,ans[maps[u]-1][maps[v]-1]);
        ans[maps[v]-1][maps[u]-1] = min(x,ans[maps[v]-1][maps[u]-1]);
    }
    vector <lli> col(n+1,0);
    vector <lli> com(n+1);
    int comp = 0;
    stack <lli> s;
    for(int i = 1; i<=n; i++)
    {
        if(col[i] == 0)
        {
            comp++;
            s.push(i);
            col[i] = 1;
            while(!s.empty())
            {
                int top = s.top();
                s.pop();
                com[top] = comp;
                int temp = g[top].size();
                for(int j = 0; j<temp; j++)
                {
                    if(col[g[top][j]] == 0)
                    {
                        s.push(g[top][j]);
                        col[g[top][j]] = 1;
                    }
                }
            }
        }
    }
    for(int i = 1; i<=k; i++)
    {
        int flag = 0;
        for(int j = a[i-1]+1; j<a[i]; j++)
        {
            if(com[j] != com[j+1])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            cout << "No\n";
            return 0;
        }
    }
    for(int i = 0; i<k; i++)
    {
        for(int j = 0; j<k; j++)
        {
            for(int l = 0; l<k; l++)
            {
                if(ans[i][j] != -1)
                {
                    ans[j][l] = min(ans[j][l],ans[j][i] + ans[i][l]);
                }
                else
                {
                    ans[j][l] = ans[j][i]+ans[i][l];
                }
            }
        }
    }
    cout << "Yes\n";
    for(int i = 0; i<k; i++)
    {
        for(int j = 0; j<k; j++)
        {
            if(i == j)
            {
                cout << 0 << " ";
            }
            else if(ans[i][j] == INT_MAX)
            {
                cout << -1 << " ";
            }
            else
            {
                cout << ans[i][j] << " ";
            }
        }
        cout << endl;
    }
}
