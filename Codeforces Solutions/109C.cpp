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

vector<lli> getbinary(lli x)
{
    vector <lli> bin(8,0);
    lli iter = 0;
    while(x > 0)
    {
        if(x%2 == 0)
        {
            bin[iter] = 0;
        }
        else
        {
            bin[iter] = 1;
        }
        x/=2;
        iter++;
    }
    return bin;
}

lli dist(pll a, pll b)
{
    return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y - a.y);
}

unordered_map <lli,vector<lli> > g;
map <pll,lli> lucky;
lli subtree[100001],notsub[100001],insub[100001];
lli n;

bool check(lli x)
{
    while(x>0)
    {
        if(x%10 != 4 && x%10 != 7)
        {
            return false;
        }
        x/=10;
    }
    return true;
}

void dfs1(lli u, lli parent)
{
    subtree[u] = 1;
    for(auto v : g[u])
    {
        if(v!=parent)
        {
            dfs1(v,u);
            subtree[u] += subtree[v];
            if(lucky[mp(u,v)] == 1 || lucky[mp(v,u)] == 1)
            {
                insub[u] += subtree[v];
            }
            else
            {
                insub[u] += insub[v];
            }
        }
    }
}

void dfs2(lli u, lli parent)
{
    if(parent != 0)
    {
        if(lucky[mp(u,parent)] == 1 || lucky[mp(parent,u)] == 1)
        {
            notsub[u] = n - subtree[u];
        }
        else
        {
            notsub[u] = notsub[parent] + insub[parent] - insub[u];
        }
    }
    for(auto v : g[u])
    {
        if(v != parent)
        {
            dfs2(v,u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    for(int i = 0; i<100001; i++)
    {
        notsub[i] = 0;
        insub[i] = 0;
        subtree[i] = 0;
    }
    cin >> n;
    for(int i = 0; i<n-1; i++)
    {
        lli u,v,w;
        cin >> u >> v >> w;
        g[u].pb(v);
        g[v].pb(u);
        if(check(w))
        {
            lucky[mp(u,v)] = 1;
            lucky[mp(v,u)] = 1;
        }
    }
    dfs1(1,0);
    dfs2(1,0);
    lli ans = 0;
    for(int i = 1; i<=n; i++)
    {
        lli temp = insub[i] + notsub[i];
        ans += temp*(temp-1);
    }
    cout << ans << endl;
}
