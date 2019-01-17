#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

//#define pi 3.141592653589793238
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

lli primefactorise(int n)
{
    if(n == 1)
    {
        return 1;
    }
    lli ans = n;
    while (n%2 == 0)
    {
        n = n/2;
        if(n != 1)
        {
            ans += n;
        }
    }

    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            n = n/i;
            if(n != 1)
            {
                ans += n;
            }
        }
    }
    ans += 1;
    return ans;
}

lli power(lli a,lli b)
{
    lli ans = 1;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            ans *= a;
            ans = ans%mod;
        }
        b/=2;
        a*=a;
        a = a%mod;
    }
    return ans%mod;
}

lli dp[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i<501; i++)
    {
        for(int j = 0; j<501; j++)
        {
            dp[i][j] = 0;
        }
    }
    lli n;
    cin >> n;
    lli a[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    for(int len = 1; len<=n; len++)
    {
        for(int begin = 0,end = len-1; end<n; end++,begin++)
        {
            if(len == 1)
            {
                dp[begin][end] = 1;
            }
            else
            {
                dp[begin][end] = 1 + dp[begin+1][end];
                if(a[begin] == a[begin+1])
                {
                    dp[begin][end] = min(dp[begin][end],1 + dp[begin+2][end]);
                }
                for(int pres = begin + 2; pres <= end; pres++)
                {
                    if(a[begin] == a[pres])
                    {
                        dp[begin][end] = min(dp[begin][end], dp[begin+1][pres-1] + dp[pres+1][end]);
                    }
                }
            }
        }
    }
    cout << dp[0][n-1] << endl;
}
