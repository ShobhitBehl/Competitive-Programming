#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
typedef set<lli> sl;
typedef map<int,int> mii;
typedef set<int> si;
#define x first
#define y second
#define mp make_pair
#define pb push_back

lli power(lli a, lli p)
{
    lli ans = 1;
    while(p > 0)
    {
        if(p%2)
        {
            ans *= a;
            ans %= 1000000007;
        }
        a*=a;
        a%=1000000007;
        p/=2;
    }
    return ans%1000000007;
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
lli INF = 1e18 + 1;
lli a[300300];
unordered_map <lli,vector<lli> > g;
lli dp[300300];
vector <lli> col(300300,0);
lli ans = -INF;

void dfs(lli curr)
{
    col[curr] = 1;
    dp[curr] = a[curr];
    a[curr] = -INF;
    lli max1 = -INF,max2 = -INF;
    for(auto v : g[curr])
    {
        if(col[v] != 1)
        {
            dfs(v);
            dp[curr] += dp[v];
            a[curr] = max(a[curr],a[v]);
            if(a[v] > max1)
            {
                swap(max1,a[v]);
            }
            if(a[v] > max2)
            {
                swap(max2,a[v]);
            }
        }
    }
    if(max2 > -INF)
    {
        ans = max(ans,max1+max2);
    }
    a[curr] = max(a[curr],dp[curr]);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n;
    cin >> n;
    for(int i  = 1; i<=n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i<n-1; i++)
    {
        lli u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    if(ans > -INF)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "Impossible\n";
    }
}
