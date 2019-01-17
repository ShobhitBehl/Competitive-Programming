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
    vector < vector<int> >x,y;
    for(int i = 0; i<4; i++)
    {
        vector <int> temp(4);
        cin >> temp[0] >> temp[1] >> temp[2] >> temp[3];
        if(temp[0] == temp[2])
        {
            y.pb(temp);
        }
        else if(temp[1] == temp[3])
        {
            x.pb(temp);
        }
    }
    vector <pll> points;
    if(x.size() == 2 && y.size() == 2)
    {
        for(int i = 0; i<2; i++)
        {
            for(int j = 0; j<2; j++)
            {
                lli tempx = y[i][0],tempy = x[j][1];
                if(((tempx == x[j][0] && tempy == x[j][1]) || (tempx == x[j][2] && tempy == x[j][3])) && ((tempx == y[i][0] && tempy == y[i][1]) || (tempx == y[i][2] && tempy == y[i][3])))
                {
                    points.pb(mp(tempx,tempy));
                }
                else
                {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
        set <int> sides;
        for(int i = 0; i<4; i++)
        {
            for(int j = i+1; j<4; j++)
            {
                if(points[i].x == points[j].x)
                {
                    sides.insert(abs(points[i].y-points[j].y));
                }
                else if(points[i].y == points[j].y)
                {
                    sides.insert(abs(points[i].x - points[j].x));
                }
            }
        }
        if(sides.size() > 2)
        {
            cout << "NO\n";
            return 0;
        }
        for(auto e : sides)
        {
            if(e == 0)
            {
                cout << "NO\n";
                return 0;
            }
        }
        cout << "YES\n";
        return 0;
    }
    else
    {
        cout << "NO\n";
    }
}
