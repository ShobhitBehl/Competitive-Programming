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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n,m,k;
    cin >> n >> m >> k;
    lli a[n+1];
    for(int i = 1; i<=n; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    map <lli,lli> m1;
    lli l = 1, r = k;
    lli ans = 0;
    while(r<=n)
    {
        if(m1[r] == 1)
        {
            r++;
            continue;
        }
        if(m1[l] == 1)
        {
            l++;
            continue;
        }
        if(a[r]-a[l]+1 <= m)
        {
            m1[r] = 1;
            ans++;
            r++;
        }
        else
        {
            l++;
            r++;
        }
    }
    cout << ans << endl;
}
