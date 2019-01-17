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

struct bun
{
    lli a,b,c,d;
};

bool comparator(bun &a,bun &b)
{
    return b.c*a.d > a.c*b.d;
}

const int MAX=1005, MAXM=13;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n,m,c0,d0;
    cin >> n >> m;
    lli a[m],b[m],c[m],d[m];
    cin >> c0 >> d0;
    for(int i=0; i<m; i++)
    {
    	cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    vector < vector<lli> > dp(11111,vector<lli>(m+1,0));
    dp[0][0] = 0;
    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            lli num = a[j]/b[j];
            for(int k = 0; k<=num; k++)
            {
                dp[i+c[j]*k][j+1] = max(dp[i+c[j]*k][j+1],dp[i][j] + d[j]*k);
            }
        }
    }
    lli ans = -1;
    for(int i = 0 ;i<=n; i++)
    {
        ans = max(ans,dp[i][m] + ((n-i)/c0)*d0);
    }
    cout << ans << endl;
}
