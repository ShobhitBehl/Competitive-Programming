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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    lli n,m;
    cin >> n >> m;
    lli k;
    cin >> k;
    pll a[k];
    for(int i = 0; i<k; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    lli maxx = -1;
    lli ansi,ansj;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            lli minn = 1e18;
            for(int l = 0; l<k; l++)
            {
                minn = min(minn, abs(a[l].x - i) + abs(a[l].y-j));
            }
            if(maxx < minn)
            {
                maxx = minn;
                ansi = i;
                ansj = j;
            }
        }
    }
    cout << ansi << " " << ansj << endl;
}
