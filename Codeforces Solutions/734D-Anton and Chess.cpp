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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n;
    cin >> n;
    lli x0,y0;
    cin >> x0 >> y0;
    pll a[8];
    lli t[8];
    for(int i = 0; i<8; i++)
    {
        t[i] = 0;
        if(i%2 == 0)
        {
            a[i] = mp(1e18,1e18);
        }
        else
        {
            a[i] = mp(-1e18,-1e18);
        }
    }
    lli attack = 0;
    for(int i = 0; i<n; i++)
    {
        lli x1,y1;
        char c;
        cin >> c >> x1 >> y1;
        if(x1 == x0)
        {
            if(y1 > y0)
            {
                if(y1 < a[0].y)
                {
                    a[0].y = y1;
                    if(c == 'R' || c == 'Q')
                    {
                        t[0] = 1;
                    }
                    else
                    {
                        t[0] = 0;
                    }
                }
            }
            else
            {
                if(y1 > a[1].y)
                {
                    a[1].y = y1;
                    if(c == 'R' || c == 'Q')
                    {
                        t[1] = 1;
                    }
                    else
                    {
                        t[1] = 0;
                    }
                }
            }
        }
        else if(y1 == y0)
        {
            if(x1  > x0)
            {
                if(x1 < a[2].x)
                {
                    a[2].x = x1;
                    if(c == 'R' || c == 'Q')
                    {
                        t[2] = 1;
                    }
                    else
                    {
                        t[2] = 0;
                    }
                }
            }
            else
            {
                if(x1 > a[3].x)
                {
                    a[3].x = x1;
                    if(c == 'R' || c == 'Q')
                    {
                        t[3] = 1;
                    }
                    else
                    {
                        t[3] = 0;
                    }
                }
            }
        }
        else if(y1-x1 == y0-x0)
        {
            if(y1 > y0)
            {
                if(y1 < a[4].y)
                {
                    a[4].y = y1;
                    if(c == 'B' || c == 'Q')
                    {
                        t[4] = 1;
                    }
                    else
                    {
                        t[4] = 0;
                    }
                }
            }
            else if(y1 < y0)
            {
                if(y1 > a[5].y)
                {
                    a[5].y = y1;
                    if(c == 'B' || c == 'Q')
                    {
                        t[5] = 1;
                    }
                    else
                    {
                        t[5] = 0;
                    }
                }
            }
        }
        else if(y1+x1 == x0+y0)
        {
            if(y1 > y0)
            {
                if(y1 < a[6].y)
                {
                    a[6].y = y1;
                    if(c == 'B' || c == 'Q')
                    {
                        t[6] = 1;
                    }
                    else
                    {
                        t[6] = 0;
                    }
                }
            }
            else if(y1 < y0)
            {
                if(y1 > a[7].y)
                {
                    a[7].y = y1;
                    if(c == 'B' || c == 'Q')
                    {
                        t[7] = 1;
                    }
                    else
                    {
                        t[7] = 0;
                    }
                }
            }
        }
    }
    for(int i = 0; i<8; i++)
    {
        if(t[i] == 1)
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "No\n";
}
