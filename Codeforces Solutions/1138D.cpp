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

void computeLPSArray(string pat, int M,int *lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void solve(){
    string s,t;
    cin >> s >> t;
    ll count[2];
    ll n = s.size(), m = t.size();
    for(int i = 0; i<n; i++)
    {
        count[s[i]-'0']++;
    }
    if(m > n)
    {
        cout << s << endl;
        return;
    }
    int lps[MAXN];
    computeLPSArray(t, m, lps);
    string ans;
    for(int i = 0; i<m; i++)
    {
        if(count[t[i]-'0'] > 0)
        {
            count[t[i]-'0']--;
            ans += t[i];
        }
        else
        {
            break;
        }
        if(i == m-1)
        {
            i = lps[m-1] - 1;
        }
    }
    while(count[1] > 0)
    {
        ans += '1';
        count[1]--;
    }
    while(count[0] > 0)
    {
        ans += '0';
        count[0]--;
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
