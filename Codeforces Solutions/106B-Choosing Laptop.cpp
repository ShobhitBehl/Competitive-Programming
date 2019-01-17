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
    lli n;
    cin >> n;
    lli a[n],b[n],c[n],d[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    vector <lli> out(n,0);
    for(int i = 0; i<n;i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(a[i] < a[j] && b[i] < b[j] && c[i] < c[j])
            {
                out[i] = 1;
                break;
            }
        }
    }
    lli ans = -1;
    for(int i = 0; i<n; i++)
    {
        if(out[i] == 0)
        {
            if(ans == -1)
            {
                ans = i;
            }
            else if(d[i] < d[ans])
            {
                ans = i;
            }
        }
    }
    cout << ans+1 << endl;
}
