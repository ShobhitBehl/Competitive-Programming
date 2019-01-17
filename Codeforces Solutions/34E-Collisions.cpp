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

struct ball
{
    double x,v,m;
    lli ind;
};

bool comparator1 (const ball &a, const ball &b)
{
    return a.x < b.x;
}

bool comparator2 (const ball &a, const ball &b)
{
    return a.ind < b.ind;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n;
    double t;
    cin >> n >> t;
    ball a[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i].x >> a[i].v >> a[i].m;
        a[i].ind = i;
    }
    sort(a,a+n,comparator1);
    double ttl,timer = 0,minttl;
    lli i1,i2;
    while(true)
    {
        ttl = -1,minttl = 1e18;
        for(int i = 0; i<n-1; i++)
        {
            if(a[i].v < 0 && a[i+1].v > 0)
            {
                continue;
            }
            else if(a[i].v < 0 && a[i+1].v < 0 && abs(a[i].v) >= abs(a[i+1].v))
            {
                continue;
            }
            else if(a[i].v > 0 && a[i+1].v > 0 && abs(a[i+1].v) >= abs(a[i].v))
            {
                continue;
            }
            else
            {
                ttl = abs(a[i+1].x - a[i].x)/abs(a[i+1].v - a[i].v);
                if(ttl < minttl)
                {
                    minttl = ttl;
                    i1 = i;
                    i2 = i+1;
                }
            }
        }
        if(minttl == 1e18)
        {
            break;
        }
        else if(timer + minttl > t)
        {
            break;
        }
        for(int i = 0 ;i<n; i++)
        {
            a[i].x += a[i].v*minttl;
        }
        double temp = a[i1].v;
        a[i1].v = (((a[i1].m - a[i2].m)*a[i1].v) + (2*a[i2].m*a[i2].v))/(a[i1].m + a[i2].m);
        a[i2].v = (((a[i2].m - a[i1].m)*a[i2].v) + (2*a[i1].m*temp))/(a[i1].m + a[i2].m);
        timer += minttl;
    }
    for(int i = 0; i<n; i++)
    {
        a[i].x += a[i].v*(t-timer);
    }
    sort(a,a+n,comparator2);
    for(int i = 0; i<n; i++)
    {
        cout << setprecision(20) << a[i].x << endl;
    }
}
