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
        }
        a*=a;
        p/=2;
    }
    return ans;
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
    lli n;
    cin >> n;
    lli a[n+1];
    lli sum[n+1];
    sum[0] = 0;
    for(int i = 1; i<=n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    lli s = sum[n];
    if(s%3 != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    s /= 3;
    lli b[n+1];
    lli c[n+1];
    for(int i = 1; i<=n; i++)
    {
        if(sum[i] == s)
        {
            b[i] = 1;
        }
        else
        {
            b[i] = 0;
        }
    }
    for(int i = n; i>=1; i--)
    {
        if(sum[n] - sum[i-1] == s)
        {
            c[i] = 1;
        }
        else
        {
            c[i] = 0;
        }
    }
    b[0] = 0;
    c[0] = 0;
    for(int i = 1; i<=n; i++)
    {
        b[i] += b[i-1];
        c[i] += c[i-1];
    }
    lli ans = 0;
    for(int i = 1; i<=n-2; i++)
    {
        if(b[i] - b[i-1] == 1)
        {
            //cout << c[n] << " " << c[i+1] << endl;
            ans += c[n] - c[i+1];
        }
    }
    cout << ans << endl;
}
