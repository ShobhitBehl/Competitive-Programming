#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
typedef set<lli> sl;
//typedef pair<int,int> pii;
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
    vector <lli> bin(2000,0);
    int iter = 0;
    while(x > 0)
    {
        bin[iter] = x%2;
        iter++;
        x/=2;
    }
    return bin;
}

char mat[1024][1024];

void construct(char mat[1024][1024],int prev)
{
    for(int i = 0; i<prev; i++)
    {
        for(int j = 0; j<prev; j++)
        {
            mat[i][prev+j] = mat[i][j];
            mat[prev+i][j] = mat[i][j];
            if(mat[i][j] == '+')
            {
                mat[prev+i][prev+j] = '*';
            }
            else
            {
                mat[prev+i][prev+j] = '+';
            }
        }
    }
    prev *= 2;
    if(prev == 1024)
    {
        return;
    }
    else
    {
        construct(mat,prev);
    }
}

lli a[100000];

lli solve(lli l, lli r, lli prev)
{
    if(l>=r)
    {
        return 0;
    }
    int minind = l;
    for(int i = l; i<r; i++)
    {
        if(a[minind] > a[i])
        {
            minind = i;
        }
    }
    return min(r-l,a[minind] - prev + solve(l,minind,a[minind]) + solve(minind+1,r,a[minind]));
}

lli MAX = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n;
    cin >> n;
    map <lli,vector <lli> > g;
    map < pair<lli,lli>,lli > num;
    for(int i = 0; i<n-1; i++)
    {
        lli u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    lli parent[n+1];
    lli level[n+1];
    vector < deque <lli> > path(n+1);
    stack <lli> s;
    s.push(1);
    parent[1] = 1;
    level[1] = 0;
    lli leaf = 0;
    while(!s.empty())
    {
        lli u = s.top();
        s.pop();
        if(g[u].size() == 1 && u != 1)
        {
            leaf++;
        }
        for(auto v : g[u])
        {
            if(v != parent[u])
            {
                s.push(v);
                parent[v] = u;
                level[v] = level[u]+1;
            }
        }
    }
    lli order[leaf+2];
    order[0] = 1;
    order[leaf+1] = 1;
    for(int i = 1; i<=leaf; i++)
    {
        cin >> order[i];
    }
    for(int i = 0; i<leaf+1; i++)
    {
        lli u = order[i];
        lli v = order[i+1];
        path[v].push_front(v);
        while(u != v)
        {
            if(level[v] > level[u])
            {
                num[mp(v,parent[v])]++;
                num[mp(parent[v],v)]++;
                v = parent[v];
                path[order[i+1]].push_front(v);
            }
            else
            {
                num[mp(u,parent[u])]++;
                num[mp(parent[u],u)]++;
                u = parent[u];
                path[order[i]].push_back(u);
            }
        }
    }
    for(auto u : g)
    {
        for(auto v : u.y)
        {
            if(num[mp(u.x,v)] != 2)
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    lli prev = -1;
    for(int i = 0; i<leaf+2; i++)
    {
        for(auto p : path[order[i]])
        {
            if(p != prev)
            {
                cout << p << " ";
                prev = p;
            }
        }
    }
}
