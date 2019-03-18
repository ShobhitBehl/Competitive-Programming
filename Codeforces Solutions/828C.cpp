#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
typedef set<lli> sl;
typedef map<int,int> mii;
typedef set<int> si;
typedef pair<double,double> pdd;
typedef map<double,lli> mdl;
typedef set<double> sd;
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

struct ball
{
    double x,v,m;
    lli ind;
};

bool comparator1 (const ball &a, const ball &b)
{
    return a.x < b.x;
}

bool comparator2 (const ball &a, const ball &b)
{
    return a.ind < b.ind;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n;
    cin >> n;
    vector <pll> m;
    string ss[n+1];
    lli maxsize = 0;
    for(int i = 0; i<n; i++)
    {
        string s;
        cin >> s;
        ss[i] = s;
        lli temp;
        cin >> temp;
        for(int j = 0; j<temp; j++)
        {
            lli ind;
            cin >> ind;
            maxsize = max(maxsize,(lli)(ind+s.size()-1));
            m.pb(mp(ind,i));
        }
    }
    sort(m.begin(),m.end());
    lli done = 0;
    char ans[maxsize+1];
    for(int i = 0; i<=maxsize; i++)
    {
        ans[i] = 'a';
    }
    for(auto e : m)
    {
        lli tempo = ss[e.y].size();
        if(done < tempo + e.x-1)
        {
            for(int j = max(done+1,e.x); j<tempo + e.x; j++)
            {
                ans[j] = ss[e.y][j-e.x];
            }
            done = tempo+e.x-1;
        }
    }
    for(int i = 1; i<=maxsize; i++)
    {
        cout << ans[i];
    }
    cout << endl;
}
