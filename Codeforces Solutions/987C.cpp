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

char mat[1024][1024];

void construct(char mat[1024][1024],int prev)
{
    for(int i = 0; i<prev; i++)
    {
        for(int j = 0; j<prev; j++)
        {
            mat[i][prev+j] = mat[i][j];
            mat[prev+i][j] = mat[i][j];
            if(mat[i][j] == '+')
            {
                mat[prev+i][prev+j] = '*';
            }
            else
            {
                mat[prev+i][prev+j] = '+';
            }
        }
    }
    prev *= 2;
    if(prev == 1024)
    {
        return;
    }
    else
    {
        construct(mat,prev);
    }
}

struct line
{
    int x1,x2,y1,y2;
};

bool comparator(const line &a, const line &b)
{
    return a.x1 > b.x1;
}

lli MAX = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n;
    cin >> n;
    lli s[n],c[n];
    for(int i = 0; i<n; i++)
    {
        cin >> s[i];
    }
    lli dp[n][3];
    for(int i = 0; i<n; i++)
    {
        cin >> c[i];
        dp[i][0] = c[i];
        dp[i][1] = MAX;
        dp[i][2] = MAX;
    }
    lli ans = MAX;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<i; j++)
        {
            if(s[j] < s[i])
            {
                dp[i][1] = min(dp[i][1],dp[j][0] + c[i]);
                dp[i][2] = min(dp[i][2],dp[j][1] + c[i]);
            }
        }
        if(dp[i][2] != MAX)
        {
            ans = min(ans,dp[i][2]);
        }
    }
    ans = ans == MAX ? -1 : ans;
    cout << ans << endl; 
}
