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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n,temp,q;
    cin >> n >> q;
    set <lli> s;
    vector <lli> a;
    unordered_map <lli,lli> m;
    for(int i= 0; i<n; i++)
    {
        cin >> temp;
        if(s.find(temp) == s.end())
        {
            s.insert(temp);
            a.pb(temp);
        }
        m[temp]++;
    }
    sort(a.rbegin(),a.rend());
    n = a.size();
    for(int i = 0; i<q; i++)
    {
        lli query;
        cin >> query;
        lli ans = 0;
        for(int j = 0; j<n; j++)
        {
            if(query >= a[j])
            {
                lli req = min(query/a[j],m[a[j]]);
                ans += req;
                query -= req*a[j];
            }
        }
        if(query != 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
}
