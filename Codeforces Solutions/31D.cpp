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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli w,h,n,x1,y1,x2,y2;
    cin >> w >> h >> n;
    set < pair<pll,pll> > s;
    s.insert(mp(mp(0,0),mp(w,h)));
    pair<pll,pll> a[n];
    int check[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i].x.x >> a[i].x.y >> a[i].y.x >> a[i].y.y;
        check[i] = 0;
    }
    lli  flag = 1;
    while(flag)
    {
        flag = 0;
        for(int i = 0; i<n; i++)
        {
            if(check[i] == 0)
            {
                if(a[i].x.x == a[i].y.x)
                {
                    for(auto e : s)
                    {
                        if(a[i].x.x > e.x.x && a[i].x.x < e.y.x && a[i].x.y == e.x.y && a[i].y.y == e.y.y)
                        {
                            s.insert(mp(e.x,a[i].y));
                            s.insert(mp(a[i].x,e.y));
                            s.erase(s.find(e));
                            check[i] = 1;
                            break;
                        }
                    }
                }
                else
                {
                    for(auto e : s)
                    {
                        if(a[i].x.y > e.x.y && a[i].x.y < e.y.y && a[i].x.x == e.x.x && a[i].y.x == e.y.x)
                        {
                            s.insert(mp(e.x,a[i].y));
                            s.insert(mp(a[i].x,e.y));
                            s.erase(s.find(e));
                            check[i] = 1;
                            break;
                        }
                    }
                }
                flag = 1;
            }
        }
    }
    vector <lli> arr;
    for(auto e : s)
    {
        arr.pb((e.y.x - e.x.x) * (e.y.y - e.x.y));
    }
    sort(arr.begin(),arr.end());
    for(int i = 0; i<n+1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
