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
    lli n,m;
    cin >> n >> m;
    char a[n][m];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin >> a[i][j];
        }
    }
    lli ones[n][m+1];
    for(int i = 0; i<n; i++)
    {
        ones[i][m] = 0;
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = m-1; j>=0; j--)
        {
            ones[i][j] = a[i][j] == '1' ? ones[i][j+1] + 1:0;
        }
    }
    lli temp[n];
    lli ans = -1;
    for(int j = 0; j<m; j++)
    {
        for(int i = 0; i<n; i++)
        {
            temp[i] = ones[i][j];
        }
        sort(temp,temp+n);
        for(int i = 0; i<n; i++)
        {
            ans = max(ans,temp[i]*(n-i));
        }
    }
    cout << ans << endl;
}
