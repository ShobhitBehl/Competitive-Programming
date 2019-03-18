#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
#define x first
#define y second
#define mp make_pair
#define pb push_back

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

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    mll m1;
    map< int,vector<int> > g;
    for(int i = 0; i<k; i++)
    {
        int x;
        cin >> x;
        m1[x] = 1;
    }
    for(int i = 0; i<m; i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector <int> col(n+1,0);
    vector< pair <int,int> > cc;
    stack <int> s;
    for(int i = 1; i<=n; i++)
    {
        if(col[i] == 0)
        {
            int num = 0,temp = 0;
            s.push(i);
            col[i] = 1;
            while(!s.empty())
            {
                int top = s.top();
                s.pop();
                if(m1[top] == 1)
                {
                    temp = 1;
                }
                num++;
                for(auto v: g[top])
                {
                    if(col[v] == 0)
                    {
                        col[v] = 1;
                        s.push(v);
                    }
                }
            }
            cc.pb(mp(num,temp));
        }
    }
    sort(cc.rbegin(),cc.rend());
    int x = cc.size();
    int max = 0;
    for(int i = 0; i<x; i++)
    {
        //cout << cc[i].x << " " << cc[i].y << endl;
        max += cc[i].x*(cc[i].x-1)/2;
    }
    int a = cc[0].x,at = cc[0].y;
    for(int i = 1; i<x; i++)
    {
        if(cc[i].y == 0)
        {
            max += a*cc[i].x;
            a += cc[i].x;
        }
        else if(cc[i].y == 1 && at == 0)
        {
            max += a*cc[i].x;
            at = 1;
            a += cc[i].x;
        }
    }
    cout << max - m << endl;
}
