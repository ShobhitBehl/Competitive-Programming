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

lli M = 1000000007;

lli min(lli a, lli b, lli c, lli d)
{
    lli arr[4] = {a,b,c,d};
    sort(arr,arr+4);
    return arr[0];
}

lli max(lli a, lli b, lli c, lli d)
{
    lli arr[4] = {a,b,c,d};
    sort(arr,arr+4);
    return arr[3];
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

double distsqrd(double x1, double y1, double x2, double y2)
{
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

lli fact(lli x)
{
    lli ans = 1;
    if(x == 0)
    {
        return 1;
    }
    while(x > 0)
    {
        ans = (ans*x)%1000000007;
        x--;
    }
    return ans%1000000007;
}

lli power(lli a,lli b)
{
    lli ans = 1;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            ans *= a;
            ans = ans%M;
        }
        b/=2;
        a*=a;
        a = a%M;
    }
    return ans%M;
}

lli mod(lli a, lli b)
{
    return (((a%b)+b)%b);
}

vector <int> getbinary(int x)
{
    vector <int> bin(16,0);
    int iter = 0;
    while(x > 0)
    {
        if(x%2 == 1)
        {
            bin[iter] = 1;
        }
        else
        {
            bin[iter] = 0;
        }
        iter++;
        x/=2;
    }
    return bin;
}

struct aim
{
    double x,y,p,t;
};

bool comparator(const aim &a, const aim &b)
{
    return a.t < b.t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map <int,vector <int> > g;
    int col[n+1];
    for(int i = 0; i<n; i++)
    {
        int u,v;
        cin >> u >> v;
        col[i+1] = 0;
        g[u].pb(v);
        g[v].pb(u);
    }
    int parent[n+1];
    int ans[n+1];
    vector <int> cycle;
    stack <int> s;
    s.push(1);
    parent[1] = 0;
    col[1] = 1;
    int found = 0;
    int top;
    while(!found)
    {
        top = s.top();
        //cout << top << endl;
        for(auto v : g[top])
        {
            //cout << v << " " << col[v] << endl;
            if(col[v] == 0)
            {
                s.push(v);
                parent[v] = top;
                col[v] = 1;
                break;
            }
            else if(col[v] == 1 && v!=parent[top] && parent[v]!=top)
            {
                //cout << endl << v << " " << top << endl;
                cycle.pb(v);
                cycle.pb(top);
                found = 1;
                break;
            }
        }
        if(s.top() == top)
        {
            s.pop();
        }
    }
    while(!s.empty())
    {
        s.pop();
    }
    int iter = 1;
    while(parent[cycle[iter]] != cycle[0])
    {
        cycle.pb(parent[cycle[iter]]);
        iter++;
    }
    iter = cycle.size();
    map <int,int> cyc;
    for(int i = 0; i<iter; i++)
    {
        cyc[cycle[i]] = 1;
        ans[cycle[i]] = 0;
    }
    map <int,vector <int> > gn;
    for(auto p : g)
    {
        for(auto d: p.y)
        {
            if(cyc[p.x] == 0 && cyc[d] == 0)
            {
                gn[p.x].pb(d);
            }
            else if(cyc[p.x] == 1 && cyc[d] == 0)
            {
                gn[0].pb(d);
            }
            else if(cyc[p.x] == 0 && cyc[d] == 1)
            {
                gn[p.x].pb(0);
            }
        }
    }
    s.push(1);
    int dist[n+1];
    dist[0] = 0;
    s.push(0);
    col[0] = 1;
    for(int i = 1; i<=n; i++)
    {
        col[i] = 0;
    }
    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        for(auto v : gn[top])
        {
            if(col[v] == 0)
            {
                s.push(v);
                col[v] = 1;
                dist[v] = dist[top] + 1;
                ans[v] = dist[v];
            }
        }
    }
    for(int i = 1; i<=n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
