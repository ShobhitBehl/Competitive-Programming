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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    map <lli,vector <lli> > g;
    vector < vector<lli> > m1(n+1,vector <lli> (n+1,0));
    for(int i = 0; i<m; i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].pb(v);
        m1[u][v] = 1;
    }
    lli ans = 0;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            if(i!=j)
            {
                lli count = 0;
                for(auto v : g[i])
                {
                    if(m1[v][j] == 1)
                    {
                        count++;
                    }
                }
                ans += count*(count-1)/2;
            }
        }
    }
    cout << ans << endl;
}
