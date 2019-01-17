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

#define MOD 998244353

lli C[5001][5001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    C[0][0] = 1;
    for(int i = 1; i<5001; i++)
    {
        C[i][0] = 1;
        for(int j = 1; j<=i; j++)
        {
            C[i][j] = (C[i-1][j-1] + C[i-1][j])%MOD;
        }
    }
    lli a,b,c;
    cin >> a >> b >> c;
    lli ans1 = 0, ans2 = 0, ans3 = 0;
    lli fact = 1;
    for(int i = 0; i<=min(a,b); i++)
    {
        lli add = C[a][i];
        add %= MOD;
        add *= C[b][i];
        add %= MOD;
        add *= fact;
        add %= MOD;
        ans1 += add;
        ans1 %= MOD;
        fact *= (i+1);
        fact %= MOD;
    }
    fact = 1;
    for(int i = 0; i<=min(c,b); i++)
    {
        lli add = C[b][i];
        add %= MOD;
        add *= C[c][i];
        add %= MOD;
        add *= fact;
        add %= MOD;
        ans2 += add;
        ans2 %= MOD;
        fact*=(i+1);
        fact%=MOD;
    }
    fact = 1;
    for(int i = 0; i<=min(a,c); i++)
    {
        lli add = C[a][i];
        add %= MOD;
        add *= C[c][i];
        add %= MOD;
        add *= fact;
        add %= MOD;
        ans3 += add;
        ans3 %= MOD;
        fact*= (i+1);
        fact %= MOD;
    }
    cout << (((ans1*ans2)%MOD)*ans3)%MOD << endl;
}
