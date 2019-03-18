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


ll gcd(ll a, ll b)
{
    if(b < a)
    {
        swap(a,b);
    }
    if(a == 0)
    {
        return b;
    }
    return gcd(b%a,a);
}

ll lcm(ll a, ll b)
{
    return (a*b/gcd(a,b));
}

ll primefactorise(int n)
{
    if(n == 1)
    {
        return 1;
    }
    ll ans = n;
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

ll power(ll a,ll b)
{
    ll ans = 1;
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

vector<ll> getbinary(ll x, ll size)
{
    vector <ll> bin(size,0);
    ll iter = 0;
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

vector <ll> getprimes()
{
    vector <ll> primes(1000000,0);
    vector <ll> ans;
    for(int i = 2; i<1000000; i++)
    {
        if(primes[i] == 0)
        {
            for(int j = 2*i; j<1000000; j+=i)
            {
                primes[j] = 1;
            }
            ans.pb(i);
        }
    }
    return ans;
}

//-----------------------TRIE-START---------------------------------------------
const ll size = 10;
struct tnode
{
    tnode *child[size];
    ll isword;
};

tnode* makenode()
{
    tnode *temp = new tnode;
    for(int i = 0; i<size; i++)
    {
        temp->child[i] = NULL;
    }
    temp->isword = 0;
    return temp;
}

void insert(tnode *root, string s)
{
    tnode *temp = root;
    for(int i = 0; i<s.size(); i++)
    {
        ll key = s[i]-'a';
        if(temp->child[key] == NULL)
        {
            temp->child[key] = makenode();
        }
        temp = temp->child[key];
    }
    temp->isword = 1;
}

ll search(tnode *root,string s)
{
    tnode *temp = root;
    for(int i = 0; i<s.size(); i++)
    {
        ll key = s[i]-'a';
        if(temp->child[key] == NULL)
        {
            return 0;
        }
        temp = temp->child[key];
    }
    return temp->isword;
}

//------------------------TRIE-END----------------------------------------------
struct edge
{
	ll to, flow, cap, cost, rev;
};

struct MinCostMaxFlow
{
	ll nodes;
	vector<ll> prio, curflow, prevedge, prevnode, q, pot;
	vector<bool> inqueue;
	vector<vector<edge> > graph;
	MinCostMaxFlow() {}

	MinCostMaxFlow(ll n): nodes(n), prio(n, 0), curflow(n, 0),
	prevedge(n, 0), prevnode(n, 0), q(n, 0), pot(n, 0), inqueue(n, 0), graph(n) {}

	void addEdge(ll source, ll to, ll capacity, ll cost)
	{
		edge a = {to, 0, capacity, cost, (ll)graph[to].size()};
		edge b = {source, 0, 0, -cost, (ll)graph[source].size()};
		graph[source].push_back(a);
		graph[to].push_back(b);
	}

	void bellman_ford(ll source, vector<ll> &dist)
	{
		fill(dist.begin(), dist.end(), INT_MAX);
		dist[source] = 0;
		ll qt=0;
		q[qt++] = source;
		for(ll qh=0;(qh-qt)%nodes!=0;qh++)
		{
			ll u = q[qh%nodes];
			inqueue[u] = false;
			for(auto &e : graph[u])
			{
				if(e.flow >= e.cap)
					continue;
				ll v = e.to;
				ll newDist = dist[u] + e.cost;
				if(dist[v] > newDist)
				{
					dist[v] = newDist;
					if(!inqueue[v])
					{
						inqueue[v] = true;
						q[qt++ % nodes] = v;
					}
				}
			}
		}
	}

	pair<ll, ll> minCostFlow(ll source, ll dest, ll maxflow)
	{
		bellman_ford(source, pot);
		ll flow = 0;
		ll flow_cost = 0;
		while(flow < maxflow)
		{
			priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > q;
			q.push({0, source});
			fill(prio.begin(), prio.end(), INT_MAX);
			prio[source] = 0;
			curflow[source] = INT_MAX;
			while(!q.empty())
			{
				ll d = q.top().first;
				ll u = q.top().second;
				q.pop();
				if(d != prio[u])
					continue;
				for(ll i=0;i<graph[u].size();i++)
				{
					edge &e=graph[u][i];
					ll v = e.to;
					if(e.flow >= e.cap)
						continue;
					ll newPrio = prio[u] + e.cost + pot[u] - pot[v];
					if(prio[v] > newPrio)
					{
						prio[v] = newPrio;
						q.push({newPrio, v});
						prevnode[v] = u;
						prevedge[v] = i;
						curflow[v] = min(curflow[u], e.cap - e.flow);
					}
				}
			}
			if(prio[dest] == INT_MAX)
				break;
			for(ll i=0;i<nodes;i++)
				pot[i]+=prio[i];
			ll df = min(curflow[dest], maxflow - flow);
			flow += df;
			for(ll v=dest;v!=source;v=prevnode[v])
			{
				edge &e = graph[prevnode[v]][prevedge[v]];
				e.flow += df;
				graph[v][e.rev].flow -= df;
				flow_cost += df * e.cost;
			}
		}
		return {flow, flow_cost};
	}
};

void solve()
{
    ll n;
    string s;
    cin >> n;
    cin >> s;
    ll b[n];
    map <char, ll> m;
    for(int i = 0; i<n; i++)
    {
        cin >> b[i];
    }
    for(int i = 0; i<n; i++)
    {
        m[s[i]]++;
    }
    MinCostMaxFlow mcmf(101);
    for(char i = 'a'; i<='z'; i++)
    {
        mcmf.addEdge(0, i - 'a' + 1, m[i], 0);
    }
    for(int i = 0; i<n/2; i++)
    {
        for(int j = 'a'; j<='z'; j++)
        {
            if(s[i] == j and s[n-i-1] == j)
            {
                mcmf.addEdge(j - 'a' + 1, 27 + i, 1, min(-b[i],-b[n-i-1]));
            }
            else if(s[i] == j)
            {
                mcmf.addEdge(j - 'a' + 1, 27 + i, 1, -b[i]);
            }
            else if(s[n-i-1] == j)
            {
                mcmf.addEdge(j - 'a' + 1, 27 + i, 1, -b[n-i-1]);
            }
            else
            {
                mcmf.addEdge(j - 'a' + 1, 27 + i, 1, 0);
            }
        }
        mcmf.addEdge(27+i, 100, 2, 0);
    }
    cout << -mcmf.minCostFlow(0,100,n).second << endl;
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
