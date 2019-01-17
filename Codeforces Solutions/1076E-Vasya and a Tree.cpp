#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define f first
#define s second
#define sd(x) scanf("%d", &x)
#define sd2(x, y) scanf("%d%d", &x, &y)
#define sd3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sdl(x) scanf("%lld", &x)
#define sdl2(x, y) scanf("%lld%lld", &x, &y)
#define sdl3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
#define pb(x) push_back(x)
#define LET(x, a) __typeof(a) x(a)
#define foreach(it, v) for (LET(it, v.begin()); it != v.end(); it++)
#define Forp(i, s, e) for (ll i = s; i <= e; i++)
#define Forn(i, s, e) for (ll i = s; i >= e; i--)
#define modfix(a, mod) ((((a) % (mod)) + (mod)) % (mod))
#define mod_sum(a, b, mod) modfix(((a) + (b)), (mod))
#define mod_sub(a, b, mod) modfix(((a) - (b)), (mod))
#define mod_mul(a, b, mod) modfix(((ll)(a) * (ll)(b)), (mod))
#define For(i,n) for(ll i = 0 ; i < n ; i++)

#define _                             \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define __                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

#define tr(...)                                       \
    cout << __FUNCTION__ << ' ' << __LINE__ << " = "; \
    trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

template <typename S, typename T>
ostream &operator<<(ostream &out, pair<S, T> const &p)
{
    out << p.f << " " << p.s;
    return out;
}

template <typename T>
ostream &operator<<(ostream &out, vector<T> const &v)
{
    ll l = v.size();
    for (ll i = 0; i < l - 1; i++)
        out << v[i] << ' ';
    if (l > 0)
        out << v[l - 1];
    return out;
}

template <typename T>
void trace(const char *name, T &&arg1) { cout << name << " : " << arg1 << endl; }

template <typename T, typename... Args>
void trace(const char *names, T &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    trace(comma + 1, args...);
}
//Here n is a global variable denoting the number of nodes in the graph
#define LSOne(S) (S & (-S))
// using namespace std;

// typedef long long ll;

// Fenwick tree
// Only the updates are stored. Original array entries are not
// stored and are assumed to be 0. If the original array entries
// are non-zero, we can store them in another array A and modify
// point query to return query(b) + A[b].
ll ft[300005];	

// Array size
ll N;

// Point query: Returns the value at position b in the array
ll query(ll b)	{
	ll sum = 0;
	for (; b; b -= LSOne(b)) sum += ft[b];
	return sum;
}

// Point update: Adds v to the value at position k in the array
void update(ll k, ll v) {
	for (; k <= N; k += LSOne(k)) ft[k] += v;
}

// Range update: Adds v to each element in [i...j] in the array
void range_update(ll i, ll j, ll v)	{
	update(i, v);
	update(j + 1, -v);
}
vll adj[300000];
vector<pll> q[300000];
ll ans[300000];
void dfs(ll s, ll p, ll h){
    for(auto &e : q[s]){
        range_update(h,min(N,e.f+h),e.s);
    }
    ans[s] = query(h);
    for(auto &e : adj[s]){
        if(e != p){
            dfs(e,s,h+1);
        }
    }
    for(auto &e : q[s]){
        range_update(h,min(N,e.f+h),-e.s);
    }
}
int main()
{
    _
   ll n;
   cin >> n;
   N = n;
   For(i,n-1){
       ll u,v;
       cin >> u >> v;
       u--;v--;
       adj[u].pb(v);
       adj[v].pb(u);

   }
   ll m;
   cin >> m;
   For(i,m){
       ll v,d,x;
       cin >> v >> d >> x;
       v--;
       q[v].pb(mp(d,x));
   }
   dfs(0,-1,1);
   for(ll i = 0 ; i < n ; i++)
    cout << ans[i] << ' ';
    cout << endl;

    

    

    return 0;
}

