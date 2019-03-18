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
            ans = ans;
        }
        b/=2;
        a*=a;
        a = a;
    }
    return ans;
}

vector <int> getbinary(int x)
{
    vector <int> bin(10,0);
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

int getnum(vector <int> bin)
{
    int t = 1;
    int n = bin.size();
    int ret = 0;
    for(int i = 0; i<n; i++)
    {
        ret += t*bin[i];
        t*=2;
    }
    return ret;
}

struct e
{
    int s,d,c;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n,a,b,a1,b1;
    cin >> n >> a >> b;
    if(n == 1)
    {
        cout << 0 << endl;
    }
    map < lli,vector<lli> > g;
    for(int i = 0; i<n-1; i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    stack <int> s;
    s.push(a);
    lli parent[n+1];
    vector <lli> col(n+1,0);
    col[a] = 1;
    while(!s.empty())
    {
        int u = s.top();
        s.pop();
        for(auto v : g[u])
        {
            if(col[v] == 0)
            {
                s.push(v);
                col[v] = 1;
                parent[v] = u;
            }
        }
    }
    b1 = parent[b];
    a1 = b;
    while(true)
    {
        if(parent[a1] == a)
        {
            break;
        }
        a1 = parent[a1];
    }
    map < lli,vector<lli> > gd;
    for(int i = 1; i<=n; i++)
    {
        for(auto v : g[i])
        {
            if(i == a && v == a1 || i == a1 && v == a || i == b1 && v == b || i == b && v == b1)
            {
                continue;
            }
            else
            {
                gd[i].pb(v);
            }
        }
    }
    //cout << "removed " << a << " " << a1 << " and " << b1 << " " << b << endl;
    for(int i = 1; i<=n; i++)
    {
        col[i] = 0;
    }
    vector <lli> scc;
    lli count = 0;
    s.push(a);
    col[a] = 1;
    while(!s.empty())
    {
        int u = s.top();
        s.pop();
        count++;
        for(auto v : gd[u])
        {
            if(col[v] == 0)
            {
                s.push(v);
                col[v] = 1;
            }
        }
    }
    scc.pb(count);
    count = 0;
    s.push(a1);
    col[a1] = 1;
    while(!s.empty())
    {
        int u = s.top();
        s.pop();
        count++;
        for(auto v : gd[u])
        {
            if(col[v] == 0)
            {
                s.push(v);
                col[v] = 1;
            }
        }
    }
    scc.pb(count);
    if(col[b] == 0)
    {
        count = 0;
        s.push(b);
        col[b] = 1;
        while(!s.empty())
        {
            int u = s.top();
            s.pop();
            count++;
            for(auto v : gd[u])
            {
                if(col[v] == 0)
                {
                    s.push(v);
                    col[v] = 1;
                }
            }
        }
        scc.pb(count);
    }
    lli ans = 0;
    /*cout << endl;
    for(int i = 0; i<scc.size(); i++)
    {
        cout << scc[i] << " ";
    }
    cout << endl;*/
    if(scc.size() == 2)
    {
        ans += (scc[0])*(scc[0]-1);
        ans += scc[1]*(scc[1]-1);
        ans += scc[1]*scc[0];
    }
    else
    {
        ans += (scc[0])*(scc[0]-1);
        ans += (scc[1])*(scc[1]-1);
        ans += (scc[2])*(scc[2]-1);
        ans += 2*scc[1]*scc[0];
        ans += 2*scc[2]*scc[1];
        ans += scc[0]*scc[2];
    }
    cout << ans << endl;
}
