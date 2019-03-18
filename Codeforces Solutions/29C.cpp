#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
typedef set<lli> sl;
//typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;
#define x first
#define y second
#define mp make_pair
#define pb push_back

lli power(lli a, lli p)
{
    lli ans = 1;
    while(p > 0)
    {
        if(p%2)
        {
            ans *= a;
            ans %= 1000000007;
        }
        a*=a;
        a%=1000000007;
        p/=2;
    }
    return ans%1000000007;
}

vector <lli> getbinary(lli x)
{
    vector <lli> bin(2000,0);
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
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n,u,v;
    cin >> n;
    map <lli,lli> m;
    map <lli, vector <lli> > g;
    for(int i = 0; i<n; i++)
    {
        cin >> u >> v;
        m[u]++;
        m[v]++;
        g[u].pb(v);
        g[v].pb(u);
    }
    lli end1 = -1,end2 = -1;
    for(auto v : m)
    {
        if(v.y == 1)
        {
            if(end1 == -1)
            {
                end1 = v.x;
            }
            else
            {
                end2 = v.x;
            }
        }
    }
    lli curr = end1;
    lli prev = end1;
    while(curr != end2)
    {
        cout << curr << " ";
        for(auto v : g[curr])
        {
            if(v != prev)
            {
                prev = curr;
                curr = v;
                break;
            }
        }
    }
    cout << end2 << endl;
}
