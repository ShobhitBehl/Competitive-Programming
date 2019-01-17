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
    lli n,a,b;
    cin >> n >> a >> b;
    if(n == 2 || n == 3)
    {
        if(a == 1 && b == 1)
        {
            cout << "NO\n";
            return 0;
        }
    }
    if(a!=1 && b!=1)
    {
        cout << "NO\n";
        return 0;
    }
    else
    {
        int flag = 1;
        lli mat[n][n];
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                mat[i][j] = 0;
            }
        }
        if(a > b)
        {
            lli temp = a;
            a = b;
            b = temp;
            flag = 0;
        }
        for(int i = 0; i<n-b; i++)
        {
            mat[i][i+1] = 1;
            mat[i+1][i] = 1;
        }
        cout << "YES\n";
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(i == j)
                {
                    cout << 0;
                }
                else
                {
                    cout << (mat[i][j] + flag)%2;
                }
            }
            cout << endl;
        }
    }
}
