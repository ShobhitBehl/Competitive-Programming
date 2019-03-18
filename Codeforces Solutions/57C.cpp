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
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n;
    cin >> n;
    lli ans = 1;
    for(int i = 1; i<=2*n - 1; i++)
    {
        ans *= i;
        ans %= 1000000007;
    }
    for(int i = 1; i<=n-1; i++)
    {
        ans *= power(i,1000000005);
        ans %= 1000000007;
        ans *= power(i,1000000005);
        ans %= 1000000007;
    }
    ans *= power(n,1000000005);
    ans %= 1000000007;
    ans *= 2;
    ans %= 1000000007;
    ans = (ans - n + 1000000007)%1000000007;
    cout << ans << endl;
}
