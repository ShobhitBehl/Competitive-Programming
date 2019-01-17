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

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
lli l=v.size();for(lli i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}


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
            ans = ans;
        }
        b/=2;
        a*=a;
        a = a;
    }
    return ans;
}

vector<lli> getbinary(lli x)
{
    vector <lli> bin(1000,0);
    lli iter = 0;
    while(x > 0)
    {
        if(x%2 == 0)
        {
            bin[iter] = 0;
        }
        else
        {
            bin[iter] = 1;
        }
        x/=2;
        iter++;
    }
    return bin;
}

lli dist(pll a, pll b)
{
    return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y - a.y);
}

struct circle
{
    lli r,cx,cy;
};

lli count(lli x, lli y)
{
    lli ans = 0;
    while(x > 0 || y > 0)
    {
        if(x%2 == 1 && y%2 == 0)
        {
            ans++;
        }
        else if(x%2 == 0 && y%2 == 1)
        {
            ans++;
        }
        x/=2;
        y/=2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(20);
    lli n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);
    pll a[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%lld %lld",&a[i].x,&a[i].y);
    }
    circle b[m];
    for(int i = 0; i<m; i++)
    {
        scanf("%lld %lld %lld",&b[i].r,&b[i].cx,&b[i].cy);
    }
    lli bit[n][m];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(dist(a[i],mp(b[j].cx,b[j].cy)) < b[j].r*b[j].r)
            {
                bit[i][j] = 1;
            }
            else
            {
                bit[i][j] = 0;
            }
        }
    }
    lli ai,bi;
    for(int temp = 0; temp<k; temp++)
    {
        scanf("%lld %lld",&ai,&bi);
        lli ans = 0;
        for(int i = 0; i<m; i++)
        {
            if( (bit[ai-1][i] == 0 && bit[bi-1][i] == 1) || (bit[ai-1][i] == 1 && bit[bi-1][i] == 0) )
            {
                ans++;
            }
        }
        printf("%lld\n",ans);
    }
}
