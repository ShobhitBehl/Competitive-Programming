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

const lli MaxN = 120;

long long C[MaxN][MaxN];
long long dp[MaxN][MaxN*MaxN];
long long v[MaxN];
long long a[MaxN][MaxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n,m,k;
    cin >> n >> m >> k;
    lli m0=m/n;
	lli m1=m%n;
	for (int i=1;i<=n;++i)
		v[i]=m0;
	for (int i=1;i<=m1;++i)
		v[i]++;
	for (int i=0;i<=n;++i)
		C[i][0]=1;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	for (int x=0;x<=n;++x)
		for (int i=1;i<=n;++i)
			a[x][i]=power(C[n][x],v[i]);
	dp[0][0]=1;
	for (int i=0;i<n;++i)
		for (int j=0;j<=k;++j)
		{
			if (!dp[i][j]) continue;
			for (int x=0;x<=n;++x)
				(dp[i+1][j+x]+=dp[i][j]*a[x][i+1])%=mod;
		}
	cout<<dp[n][k]<<endl;
	return 0;
}
