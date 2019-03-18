#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

//#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
typedef set<lli> sl;
typedef map<int,int> mii;
typedef set<int> si;
typedef pair<double,double> pdd;
typedef map<double,lli> mdl;
typedef set<double> sd;
#define x first
#define y second
#define mp make_pair
#define pb push_back
const lli mod = 1e9 + 7;


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

lli lcm(lli a, lli b)
{
    return (a*b/gcd(a,b));
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
            ans = ans%mod;
        }
        b/=2;
        a*=a;
        a = a%mod;
    }
    return ans%mod;
}

pll a[100001];
lli siz[100001],parent[100001],visited[100001];
unordered_map <lli, vector<lli> > g;
lli ans = 0;

lli find(lli a)
{
    if(parent[a] == a)
    {
        return a;
    }
    else
    {
        return find(parent[a]);
    }
}

void merge(lli a,lli b,lli num)
{
    a = find(a);
    b = find(b);
    if(a == b)
    {
        return;
    }
    ans += siz[a]*siz[b]*num;
    if(siz[a] < siz[b])
    {
        swap(a,b);
    }
    parent[b] = a;
    siz[a] += siz[b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    lli n,m;
    cin >> n >> m;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i].x;
        a[i].y = i;
    }
    sort(a,a+n);
    reverse(a,a+n);
    for(int i = 0; i<m; i++)
    {
        lli u,v;
        cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i = 0; i<n; i++)
    {
        lli curr = a[i].y;
        visited[curr] = 1;
        parent[curr] = curr;
        siz[curr] = 1;
        for(auto v : g[curr])
        {
            if(visited[v] == 1)
            {
                merge(v,curr,a[i].x);
            }
        }
    }
    ans *= 2;
    cout << (ans*1.0)/(n*(n-1))*1.0 << endl;
}
