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

bool poss(lli m, lli s)
{
    if(m == 0)
    {
        if(s != 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    if(s < 0)
    {
        return false;
    }
    if(s > 9*m)
    {
        return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli m,s;
    cin >> m >> s;
    lli temps = s;
    string min,max;
    if(s == 0)
    {
        if(m == 1)
        {
            cout << 0 << " " << 0 << endl;
        }
        else
        {
            cout << -1 << " " << -1 << endl;
        }
    }
    else if(poss(m,s))
    {
        for(int i = 1; i<=m; i++)
        {
            for(int j = 0; j<=9; j++)
            {
                if(i == 1 && j == 0)
                {
                    continue;
                }
                if(poss(m-i,s-j))
                {
                    min += '0' + j;
                    s-=j;
                    break;
                }
            }
        }
        s = temps;
        for(int i = 1; i<=m; i++)
        {
            for(int j = 9; j >= 0; j--)
            {
                if(i == 1 && j == 0)
                {
                    continue;
                }
                if(poss(m-i,s-j))
                {
                    max += '0'+j;
                    s-=j;
                    break;
                }
            }
        }
        cout << min << " " << max << endl;
    }
    else
    {
        cout << -1 << " " << -1 << endl;
    }
}
