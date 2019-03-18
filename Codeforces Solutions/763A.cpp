#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
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

lli power(lli a, lli p)
{
    lli ans = 1;
    while(p > 0)
    {
        if(p%2)
        {
            ans *= a;
            ans %= mod;
        }
        a*=a;
        a%=mod;
        p/=2;
    }
    return ans%mod;
}

vector <lli> getbinary(lli x)
{
    vector <lli> bin(101,0);
    int iter = 0;
    while(x > 0)
    {
        bin[iter] = x%2;
        iter++;
        x/=2;
    }
    return bin;
}

map <lli, vector <lli> > g;
lli c[100001];
bool check;

void dfs(lli v,lli color,lli parent)
{
    if(c[v] != color)
    {
        check = false;
    }
    for(auto e : g[v])
    {
        if(e != parent)
        {
            dfs(e,color,v);
        }
    }
}

bool solve(lli u)
{
    bool ret = true;
    for(auto v : g[u])
    {
        check = true;
        dfs(v,c[v],u);
        ret = ret && check;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n,u,v;
    cin >> n;
    for(int i = 0; i<n-1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i = 1; i<=n; i++)
    {
        cin >> c[i];
    }
    lli root1 = -1,root2 = -1;
    for(int i = 1; i<=n; i++)
    {
        for(auto e : g[i])
        {
            if(c[i] != c[e])
            {
                root1 = i;
                root2 = e;
            }
        }
    }
    if(root1 == -1)
    {
        cout << "YES\n";
        cout << 1 << endl;
        return 0;
    }
    if(solve(root1))
    {
        cout << "YES\n";
        cout << root1 << endl;
        return 0;
    }
    if(solve(root2))
    {
        cout << "YES\n";
        cout << root2 << endl;
        return 0;
    }
    cout << "NO\n";
}
