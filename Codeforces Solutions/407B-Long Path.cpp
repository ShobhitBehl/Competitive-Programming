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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n;
    cin >> n;
    lli a[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    lli dp[n+1];
    dp[0] = 0;
    for(int i = 0; i<n; i++)
    {
        dp[i+1] = (dp[i] + dp[i] - dp[a[i]-1] + 2)%1000000007;
    }
    if(dp[n] < 0)
    {
        dp[n] += 1000000007;
    }
    cout << dp[n]%1000000007 << endl;
}
