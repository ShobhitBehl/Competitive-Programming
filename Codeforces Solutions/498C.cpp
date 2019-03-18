#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

//#define pi 3.141592653589793238
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

struct BipartiteMatcher {
    vector<vector<int>> G;
    vector<int> L, R, Viz;
    
    BipartiteMatcher(int n, int m) :
    G(n), L(n, -1), R(m, -1), Viz(n) {}
    
    void AddEdge(int a, int b) {
      G[a].push_back(b);
    }
    
    bool Match(int node) {
      if (Viz[node])
        return false;
      Viz[node] = true;
      
      for (auto vec : G[node]) {
        if (R[vec] == -1) {
          L[node] = vec;
          R[vec] = node;
          return true;
        }
      }
      
      for (auto vec : G[node]) {
        if (Match(R[vec])) {
          L[node] = vec;
          R[vec] = node;
          return true;
        }
      }
      
      return false;
    }
    
    int Solve() {
      int ok = true;
      while (ok--) {
        fill(Viz.begin(), Viz.end(), 0);
        for (int i = 0; i < (int)L.size(); ++i)
          if (L[i] == -1)
            ok |= Match(i);
      }
      
      int ret = 0;
      for (int i = 0; i < L.size(); ++i)
        ret += (L[i] != -1);
      return ret;
    }
  };

void solve()
{
    BipartiteMatcher bpm(5000,5000);
    ll n,m,val;
    cin >> n >> m;
    ll k = 0;
    map < ll , vector <pll> > factor;
    for(int i = 0; i<n; i++)
    {
        cin >> val;
        for(int p = 2; p*p <= val; p++)
        {
            while(val%p == 0)
            {
                factor[i].pb(mp(p,k++));
                val/=p;
            }
        }
        if(val != 1)
        {
            factor[i].pb(mp(val,k++));
        }
    }

    for(int i = 0; i<m; i++)
    {
        ll u,v;
        cin >> u >> v;
        u--,v--;
        if(u%2)
        {
            swap(u,v);
        }
        for(auto e1 : factor[u])
        {
            for(auto e2 : factor[v])
            {
                if(e2.first == e1.first)
                {
                    bpm.AddEdge(e1.second,e2.second);
                }
            }
        }
    }
    cout << bpm.Solve() << endl;
}

int main()
{
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
