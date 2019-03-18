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
    lli n,m,k,p;
    cin >> n >> m >> k >> p;
    priority_queue <lli,vector <lli>> col,row;
    lli c = 0,r = 0;
    lli a[n][m];
    lli sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum = 0;
        for(int j = 0; j<m; j++)
        {
            cin >> a[i][j];
            sum += a[i][j];
        }
        row.push(sum);
    }
    for(int j = 0; j<m; j++)
    {
        sum = 0;
        for(int i = 0; i<n; i++)
        {
            sum += a[i][j];
        }
        col.push(sum);
    }
    lli iter = 1;
    lli rs[k+1],cs[k+1];
    rs[0] = 0;
    cs[0] = 0;
    while(iter <= k)
    {
        lli top1 = col.top();
        lli top2 = row.top();
        col.pop();
        col.push(top1 - n*p);
        cs[iter] = cs[iter-1] + top1;
        row.pop();
        row.push(top2 - m*p);
        rs[iter] = rs[iter-1] + top2;
        iter++;
    }
    lli ans = -1e18;
    for(int i = 0; i<=k; i++)
    {
        ans = max(ans,rs[i] + cs[k-i] - i*(k-i)*p);
    }
    cout << ans << endl;
}
