#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

//#define pi 3.141592653589793238
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


lli gcd(lli a, lli b)
{
    if(b < a)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if(a == 0)
    {
        return b;
    }
    return gcd(b%a,a);
}

lli lcm(lli a, lli b)
{
    return (a*b/gcd(a,b));
}

vector<lli> getprimes()
{
    vector <lli> pl(101,1);
    for(int i = 2; i<=100; i++)
    {
        if(pl[i] == 1)
        {
            for(int j = 2*i; j<=100; j+=i)
            {
                pl[j] = 0;
            }
        }
    }
    return pl;
}

lli primefactorise(int n)
{
    if(n == 1)
    {
        return 1;
    }
    lli ans = n;
    while (n%2 == 0)
    {
        n = n/2;
        if(n != 1)
        {
            ans += n;
        }
    }

    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            n = n/i;
            if(n != 1)
            {
                ans += n;
            }
        }
    }
    ans += 1;
    return ans;
}

lli power(lli a,lli b)
{
    lli ans = 1;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            ans *= a;
            ans = ans%mod;
        }
        b/=2;
        a*=a;
        a = a%mod;
    }
    return ans%mod;
}

vector<lli> getbinary(lli x)
{
    vector <lli> bin(8,0);
    lli iter = 0;
    while(x > 0)
    {
        if(x%2 == 0)
        {
            bin[iter] = 0;
        }
        else
        {
            bin[iter] = 1;
        }
        x/=2;
        iter++;
    }
    return bin;
}

lli dist(pll a, pll b)
{
    return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y - a.y);
}

lli n;
map <pll,vector <pll> > g;
char a[3][105];
bool possible[3][105];


void dfs(pll u)
{
    if(u.y > 104)
    {
        return;
    }
    if(possible[u.x][u.y] == true)
    {
        return;
    }
    possible[u.x][u.y] = true;
    lli i = u.x,j = u.y;
    if(i-1 >= 0 && j+3 < 105 && a[i][j+1] == '.' && a[i-1][j+1] == '.' && a[i-1][j+2] == '.' && a[i-1][j+3] == '.')
    {
        dfs(mp(i-1,j+3));
    }
    if(j+3 < 105 && a[i][j+1] == '.' && a[i][j+2] == '.' && a[i][j+3] == '.')
    {
        dfs(mp(i,j+3));
    }
    if(i+1 < 3 && j+3 < 105 && a[i][j+1] == '.' && a[i+1][j+1] == '.' && a[i+1][j+2] == '.' && a[i+1][j+3] == '.')
    {
        dfs(mp(i+1,j+3));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    lli t;
    cin >> t;
    while(t--)
    {
        for(int i = 0; i<3; i++)
        {
            for(int j = 0; j<105; j++)
            {
                possible[i][j] = false;
                a[i][j] = '.';
            }
        }
        lli num;
        cin >> n >> num;
        lli si,sj;
        for(int i = 0; i<3; i++)
        {
            for(int j = 0; j<n; j++)
            {
                cin >> a[i][j];
                if(a[i][j] == 's')
                {
                    si = i;
                    sj = j;
                }
            }
        }
        dfs(mp(si,sj));
        int flag = 0;
        for(int i = 0; i<3; i++)
        {
            for(int j = n-1; j<105; j++)
            {
                if(possible[i][j] == true)
                {
                    flag = 1;
                }
            }
        }
        cout << (flag == 1 ? "YES\n" : "NO\n"); 
    }
}
