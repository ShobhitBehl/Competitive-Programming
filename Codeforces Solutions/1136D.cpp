#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

#define pi 3.141592653589793238
typedef pair<ll,ll> pll;
typedef map<ll,ll> mll;
typedef set<ll> sl;
typedef map<int,int> mii;
typedef set<int> si;
typedef pair<double,double> pdd;
typedef map<double,ll> mdl;
typedef set<double> sd;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define fin cin
#define fout cout
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.f<<", "<<p.s<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

void solve(){
    ll n,m;
    cin >> n >> m;
    ll a[n];
    map <ll, set<ll> > g;
    unordered_map <ll,ll> check;
    for(ll i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    for(ll i = 0; i<m; i++)
    {
        ll u,v;
        cin >> u >> v;
        g[u].insert(v);
    }
    set <ll> after;
    for(ll i = n-2; i>=0; i--)
    {
        ll num = 0;
        if(g[a[i]].find(a[n-1]) != g[a[i]].end())
        {
            for(auto v : g[a[i]])
            {
                if(after.find(v) != after.end())
                {
                    num++;
                }
            }
            check[i + num]++;
            if(num != after.size())
            {
                after.insert(a[i]);
            }
        }
        else
        {
            after.insert(a[i]);
        }
    }
    ll ans = 0;
    for(int i = n-2; i>=0; i--)
    {
        if(check[i] == 0)
        {
            break;
        }
        else
        {
            ans += check[i];
            i -= check[i]-1;
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(50);
    // ll t;
    // cin >> t;
    // while(t--)
    // {
    //     solve();
    // }
	solve();
}
