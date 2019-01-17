#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
typedef set<lli> sl;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;
#define x first
#define y second
#define mp make_pair
#define pb push_back

lli M = 1000000007;

lli gcd(lli a, lli b)
{
    if(b < a)
    {
        lli temp = a;
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

double distsqrd(double x1, double y1, double x2, double y2)
{
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

lli fact(lli x)
{
    lli ans = 1;
    if(x == 0)
    {
        return 1;
    }
    while(x > 0)
    {
        ans = (ans*x)%1000000007;
        x--;
    }
    return ans%1000000007;
}

lli power(lli a,lli b, lli m)
{
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

vector <int> getbinary(int x)
{
    vector <int> bin(10,0);
    int iter = 0;
    while(x > 0)
    {
        if(x%2 == 1)
        {
            bin[iter] = 1;
        }
        else
        {
            bin[iter] = 0;
        }
        iter++;
        x/=2;
    }
    return bin;
}

int getnum(vector <int> bin)
{
    int t = 1;
    int n = bin.size();
    int ret = 0;
    for(int i = 0; i<n; i++)
    {
        ret += t*bin[i];
        t*=2;
    }
    return ret;
}

long long big_multiply(long long a, long long b, long long m){
  a %= m;
  b %= m;
  long long res = 0;
  while(b > 0){
    if(b & 1) res = (res + a) % m;
    a = (a + a) % m;
    b >>= 1;
  }
  return res;
}

const int MAX = 100005;
vector<int> adj[MAX];
int d[MAX], sz[MAX];
void dfs(int v)
{
	sz[v] = 1;
	for (int i = 0; i < (int)adj[v].size(); i++)
	{
		int u = adj[v][i];
		d[u] = d[v] + 1;
		dfs(u);
		sz[v] += sz[u];
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int p;
		cin >> p;
		p--;
		adj[p].push_back(i);
	}
	dfs(0);
	for (int i = 0; i < n; i++)
	{
		int ans = n - sz[i] - d[i] + 2 * (d[i] + 1);
		cout << ans / 2 << ".";
		if (ans & 1)
			cout << "5 ";
		else
			cout << "0 ";
	}
	cout << endl;
	return 0;
}
