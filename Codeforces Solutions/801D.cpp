#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
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
    cin >> n;
    pdd a[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    double ans = 1e18;
    for(int i = 0; i<n; i++)
    {
        int i1,i2,i3;
        i1 = i;
        i2 = (i+1)%n;
        i3 = (i+2)%n;
        double a1 = a[i3].y - a[i1].y;
        double b1 = a[i1].x - a[i3].x;
        double c1 = - (a[i1].y*b1) - (a[i1].x*a1);
        ans = min(ans,abs(a1*a[i2].x + b1*a[i2].y + c1)/(sqrt(a1*a1 + b1*b1)));
    }
    cout << setprecision(20) << ans/2.0 << endl;
}
