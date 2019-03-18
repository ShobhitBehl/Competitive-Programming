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
const ll MAXN = 1000005;

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
    ll k;
    string res;
    while(true)
    {
        cout << "next 0 1" << endl;
        cout.flush();
        cin >> k;
        for(ll i = 0; i < k; i++)
        {
            cin >> res;
        }
        cout << "next 1" << endl;
        cout.flush();
        cin >> k;
        for(int i = 0; i < k; i++)
        {
            cin >> res;
        }
        if(k == 2)
        {
            break;
        }
    }
    while(true)
    {
        cout << "next ";
        for(int i = 0; i < 10; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        cout .flush();
        cin >> k;
        for(int i = 0; i < k; i++)
        {
            cin >> res;
        }
        if(k == 1)
        {
            cout << "done\n";
            cout.flush();
            return;
        }
    }
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
