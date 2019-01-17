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
vector<pll> adj1[300000];
ll n,m,k;
map<pll,ll> edges;
set<ll> tree[300000];
set<ll> degree[300000];
void dijkstra(ll s, ll d[], ll p[]) {
    fill(d, d+n, inf);
    fill(p, p+n, -1);

    d[s] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;
        ll dist = d[v];
        for (auto edge : adj1[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (dist + len < d[to]) {
                d[to] = dist + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

int main()
{
    _
    // ll n,m,k;
    cin >> n >> m >> k;
    for(ll i = 0 ; i < m ; i++){
        ll u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        adj1[u].pb(mp(v,w));
        adj1[v].pb(mp(u,w));
        edges[mp(u,v)] = i;
        edges[mp(v,u)] = i;
    }

    ll d[n], p[n];
    dijkstra(0, d, p);
    set<pll> final_edges;
    for(ll i = 1 ; i <n ; i++){

        final_edges.insert(mp(i,p[i]));
        final_edges.insert(mp(p[i],i));
        tree[p[i]].insert(i);
    }
    for(ll i = 0 ; i < n ; i++){
        degree[tree[i].size()].insert(i);
    }
    if(k < n-1){
        for(ll i = 0 ; i < n-1-k ; i++){
            ll leaf = *degree[0].begin();
            degree[0].erase(leaf);
            degree[tree[p[leaf]].size()].erase(p[leaf]);
            tree[p[leaf]].erase(leaf);
            degree[tree[p[leaf]].size()].insert(p[leaf]);
            final_edges.erase(mp(leaf,p[leaf]));
            final_edges.erase(mp(p[leaf],leaf));
        }
    }
    set<ll> ans;
    for(auto &e : final_edges){
        ans.insert(edges[e]);
    }
    cout << ans.size() << endl;
    for(auto &e: ans){
        cout << e+1 << ' ';
    }
    

    

    return 0;
}

