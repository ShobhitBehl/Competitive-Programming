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
    lli n,m,k;
    cin >> n >> m >> k;
    lli c[n+1],p[n+1][m+1];
    for(int i = 1; i<=n; i++)
    {
        cin >> c[i];
    }
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            cin >> p[i][j];
        }
    }
    lli dp[n+1][k+1][m+1];
    for(int num = 0; num<=n; num++)
    {
        for(int beauty = 0; beauty<=k; beauty++)
        {
            for(int col = 0; col<=m; col++)
            {
                dp[num][beauty][col] = MAX;
            }
        }
    }
    if(c[1] == 0)
    {
        for(int col = 1; col <=m; col++)
        {
            dp[1][1][col] = p[1][col];
        }
    }
    else
    {
        dp[1][1][c[1]] = 0;
    }
    for(int num = 2; num<=n; num++)
    {
        for(int beauty = 1; beauty<=k; beauty++)
        {
            if(c[num] == 0)
            {
                for(int col1 = 1; col1<=m; col1++)
                {
                    for(int col2 = 1; col2<=m; col2++)
                    {
                        if(col1 == col2)
                        {
                            dp[num][beauty][col1] = min(dp[num][beauty][col1], dp[num-1][beauty][col1] + p[num][col1]);
                        }
                        else
                        {
                            dp[num][beauty][col1] = min(dp[num][beauty][col1], dp[num-1][beauty-1][col2] + p[num][col1]);
                        }
                    }
                }
            }
            else
            {
                for(int col = 1; col<=m; col++)
                {
                    if(col == c[num])
                    {
                        dp[num][beauty][col] = min(dp[num][beauty][col],dp[num-1][beauty][col]);
                    }
                    else
                    {
                        dp[num][beauty][c[num]] = min(dp[num][beauty][c[num]],dp[num-1][beauty-1][col]);
                    }
                }
            }
        }
    }
    lli ans = MAX;
    for(int i = 1; i<=m; i++)
    {
        ans = min(ans,dp[n][k][i]);
    }
    ans = ans >= MAX ? -1 : ans;
    cout << ans << endl;
}
