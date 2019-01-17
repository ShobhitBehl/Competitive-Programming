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

lli power(lli a,lli b,lli m)
{
    a %= m;
    lli ans = 1;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            ans *= a;
            ans = ans%m;
        }
        b/=2;
        a*=a;
        a = a%m;
    }
    return ans%m;
}

vector<lli> getbinary(lli x)
{
    vector <lli> bin(8,0);
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(20);
    lli n,m;
    cin >> n >> m;
    vector <pll> a,b[10000];
    lli f[10000];
    lli won = 0;
    for(int i = 0; i<n; i++)
    {
        lli u,v;
        cin >> u >> v;
        if(u == 1)
        {
            won++;
        }
        else
        {
            b[u].pb(mp(v,i+1));
            a.pb(mp(v,i+1));
        }
    }
    sort(a.begin(),a.end());
    for(int i = 1; i<=m; i++)
    {
        sort(b[i].begin(),b[i].end());
    }
    lli ans = 1e18;
    for(int th = 0; th<n; th++)
    {
        for(int i = 1; i<=n; i++)
        {
            f[i] = 0;
        }
        lli total = 0, num = 0;
        for(int i = 1; i<=m; i++)
        {
            lli s = 0;
            while(b[i].size() - s > th)
            {
                num += b[i][s].x;
                f[b[i][s].y] = 1;
                s++;
            }
            total += s;
        }
        lli iter = 0;
        while(total + won <= th)
        {
            if(f[a[iter].y] == 0)
            {
                total++;
                num += a[iter].x;
            }
            iter++;
        }
        ans = min(ans,num);
    }
    cout << ans << endl;
}
