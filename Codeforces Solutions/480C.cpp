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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n,k,a,b;
    cin >> n >> a >> b >> k;
    lli dp[k+1][n+1];
    for(int i = 0; i<=k; i++)
    {
        dp[i][0] = 0;
        for(int j = 1; j<=n; j++)
        {
            if(i == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                lli one = 1;
                lli cons = abs(b-j)-1;
                lli ul = min(j+cons,n);
                lli ll = max(j-cons,one);
                if(i == 1)
                {
                    dp[i][j] = (ul-ll)%mod;
                }
                else
                {
                    lli a = ((dp[i-1][ul] - dp[i-1][ll-1])%mod + mod)%mod;
                    lli b = ((dp[i-1][j] - dp[i-1][j-1])%mod + mod)%mod;
                    dp[i][j] = ((a - b)%mod + mod)%mod;
                }
                if(j == b)
                {
                    dp[i][j] = 0;
                }
                dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
            }
        }
    }
    cout << ((dp[k][a] - dp[k][a-1])%mod+mod)%mod << endl;
}
