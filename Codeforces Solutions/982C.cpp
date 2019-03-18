#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
typedef set<lli> sl;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;
#define x first
#define y second
#define mp make_pair
#define pb push_back

map <int,vector<int> > g;
int col[100001];

void dfs(int start)
{
    col[start] = 1;
    for(auto v : g[start])
    {
        if(col[v] == 0)
        {
            dfs(v);
            col[start] += col[v];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,u,v;
    cin >> n;
    for(int i = 0; i<n-1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        col[i+1] = 0;
    }
    col[n] = 0;
    if(n%2 == 1)
    {
        cout << -1 << endl;
        return 0;
    }
    dfs(1);
    int ans = 0;
    for(int i = 2; i<=n; i++)
    {
        if(col[i]%2 == 0)
        {
            ans++;
        }
    }
    cout << ans << endl;
}
