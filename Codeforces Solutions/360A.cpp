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
    lli n,m;
    cin >> n >> m;
    lli t[m],l[m],r[m],val[m];
    vector <lli> a(n+1,0),s(n+1,1000000000);
    for(int i = 0; i<m; i++)
    {
        cin >> t[i] >> l[i] >> r[i] >> val[i];
        if(t[i] == 1)
        {
            for(int j = l[i]; j<=r[i]; j++)
            {
                a[j] += val[i];
            }
        }
        else
        {
            for(int j = l[i]; j<=r[i]; j++)
            {
                s[j] = min(s[j],val[i]-a[j]);
            }
        }
    }
    for(int i = 1; i<=n; i++)
    {
        a[i] = s[i];
    }
    for(int i = 0; i<m; i++)
    {
        if(t[i] == 1)
        {
            for(int j = l[i]; j<=r[i]; j++)
            {
                a[j] += val[i];
            }
        }
        else
        {
            lli maxval = -1000000000;
            for(int j = l[i]; j<=r[i]; j++)
            {
                maxval = max(maxval,a[j]);
            }
            if(maxval!= val[i])
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for(int i = 1; i<=n; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
}
