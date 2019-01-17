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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n,m;
    cin >> n >> m;
    if(n<m)
    {
        cout << "NO\n";
        return 0;
    }
    if( n == 1 && m == 0)
    {
        cout << "YES\n1\n1 1\n";
        return 0;
    }
    lli parent[n+1];
    lli size[n+1];
    map <lli,lli> deg;
    for(int i = 1; i<=n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
    int flag = 0;
    for(int i = 0; i<m; i++)
    {
        lli u,v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        while(u != parent[u])
        {
            u = parent[u];
        }
        while(v != parent[v])
        {
            v = parent[v];
        }
        if(v!=u)
        {
            if(size[v] > size[u])
            {
                parent[u] = v;
                size[v] += size[u];
            }
            else
            {
                parent[v] = u;
                size[u] += size[v];
            }
        }
        else
        {
            flag++;
        }
    }
    for(auto e : deg)
    {
        if(e.y > 2)
        {
            cout << "NO\n";
            return 0;
        }
    }
    if(flag == 1 && n!=m || flag > 1)
    {
        cout << "NO\n";
        return 0;
    }
    if(n == m)
    {
        cout << "YES\n";
        cout << 0 << endl;
        return 0;
    }
    cout << "YES\n";
    cout << n-m << endl;
    lli iter = n-m;
    for(int i = 1; i<=n && iter > 0; i++)
    {
        for(int j = i+1; j<=n && iter > 0; j++)
        {
            if(deg[i] >= 2 || deg[j] >= 2)
            {
                continue;
            }
            lli u = i,v = j;
            while(u != parent[u])
            {
                u = parent[u];
            }
            while(v != parent[v])
            {
                v = parent[v];
            }
            if(v == u)
            {
                continue;
            }
            if(v!=u)
            {
                if(size[v] > size[u])
                {
                    parent[u] = v;
                    size[v] += size[u];
                }
                else
                {
                    parent[v] = u;
                    size[u] += size[v];
                }
                iter--;
                cout << i << " " << j << endl;
                deg[i]++;
                deg[j]++;
            }
        }
    }
    for(auto e : deg)
    {
        if(e.y < 2)
        {
            cout << e.x << " ";
        }
    }
    cout << endl;
}
