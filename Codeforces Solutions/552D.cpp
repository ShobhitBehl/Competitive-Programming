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

char mat[51][51];

lli checkpaths(pll a, pll b)
{
    pll tempa = a,tempb = b;
    lli flg1 = 0,flg2 = 0;
    while(tempa.x != tempb.x)
    {
        if(b.x > a.x)
        {
            tempa.x++;
        }
        else
        {
            tempa.x--;
        }
        if(mat[tempa.x][tempa.y] == 'W')
        {
            flg1 = 1;
            break;
        }
    }
    while(tempa.y != tempb.y)
    {
        if(b.y > a.y)
        {
            tempa.y++;
        }
        else
        {
            tempa.y--;
        }
        if(mat[tempa.x][tempa.y] == 'W')
        {
            flg1 = 1;
            break;
        }
    }
    tempa = a,tempb = b;
    while(tempa.y != tempb.y)
    {
        if(b.y > a.y)
        {
            tempa.y++;
        }
        else
        {
            tempa.y--;
        }
        if(mat[tempa.x][tempa.y] == 'W')
        {
            flg2 = 1;
            break;
        }
    }
    while(tempa.x != tempb.x)
    {
        if(b.x > a.x)
        {
            tempa.x++;
        }
        else
        {
            tempa.x--;
        }
        if(mat[tempa.x][tempa.y] == 'W')
        {
            flg2 = 1;
            break;
        }
    }
    return 2 - flg1 - flg2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n;
    cin >> n;
    pair <double,double> a[n];
    unordered_map <double,set <pair <double,double> > > m;
    set < pair<double,double> > lel;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    lli sub = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(i == j)
            {
                continue;
            }
            if(a[j].x - a[i].x == 0)
            {
                lel.insert(a[j]);
                continue;
            }
            else
            {
                double slope = (a[j].y - a[i].y)/(a[j].x - a[i].x);
                m[slope].insert(a[j]);
            }
        }
        for(auto e: m)
        {
            lli temp = e.y.size();
            sub += temp*(temp-1)/2;
        }
        sub += lel.size()*(lel.size()-1)/2;
        m.clear();
        lel.clear();
    }
    lli ans = n*(n-1)*(n-2)/6;
    ans -= sub/3;
    cout << ans << endl;
}
