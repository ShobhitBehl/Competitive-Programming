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
    lli n,m,k;
    cin >> n >> m >> k;
    if(k == -1 && n%2 != m%2)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << power(power(2,n-1),m-1) << endl;
}
