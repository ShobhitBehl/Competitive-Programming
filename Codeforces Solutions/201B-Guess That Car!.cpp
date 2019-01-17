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
    lli n,m;
    cin >> n >> m;
    lli a[n+1][m+1];
    unordered_map <lli,lli> row,col;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            cin >> a[i][j];
            row[i] += a[i][j];
            col[j] += a[i][j];
        }
    }
    lli min = 1e18,r,c;
    lli sum;
    for(int i = 0; i<=n; i++)
    {
        sum = 0;
        for(int j = 1; j<=n; j++)
        {
            if(j > i)
            {
                sum += (4*(j-i-1) + 2)*(4*(j-i-1) + 2)*row[j];
            }
            else
            {
                sum += (4*(i-j) + 2)*(4*(i-j) + 2)*row[j];
            }
        }
        if(sum < min)
        {
            min = sum;
            r = i;
        }
    }
    lli out = min;
    min = 1e18;
    for(int i = 0; i<=m; i++)
    {
        sum = 0;
        for(int j = 1; j<=m; j++)
        {
            if(j > i)
            {
                sum += (4*(j-i-1) + 2)*(4*(j-i-1) + 2)*col[j];
            }
            else
            {
                sum += (4*(i-j) + 2)*(4*(i-j) + 2)*col[j];
            }
        }
        if(sum < min)
        {
            min = sum;
            c = i;
        }
    }
    out += min;
    cout << out << endl;
    cout << r << " " << c << endl;
}
