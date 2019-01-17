#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
typedef set<lli> sl;
typedef map<int,int> mii;
typedef set<int> si;
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
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n,mit;
    cin >> n >> mit;
    lli a[n];
    map <lli,lli> m;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    lli b[n];
    priority_queue <pll, vector <pll> > q;
    for(auto e : m)
    {
        q.push(mp(e.y,e.x));
    }
    int start = q.size();
    lli iter = 0;
    for(int i = 0; i<n;)
    {
        pll top = q.top();
        q.pop();
        while(top.x >0)
        {
            a[i] = top.y;
            if(q.size() == start-1)
            {
                b[n-i-1] = top.y;
            }
            else
            {
                b[iter] = top.y;
                iter++;
            }
            i++;
            top.x--;
        }
    }
    lli ans = 0;
    for(int i = 0; i<n; i++)
    {
        if(a[i] != b[i])
        {
            ans++;
        }
    }
    cout << ans << endl;
    for(int i = 0; i<n; i++)
    {
        cout << a[i] << " " << b[i] << endl;
    }
}
