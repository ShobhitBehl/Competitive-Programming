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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    lli n,m;
    cin >> n;
    vector <pll> a;
    for(int i = 0; i<n; i++)
    {
        lli temp;
        cin >> temp;
        a.pb(mp(temp,1));
    }
    cin >> m;
    for(int i = 0; i<m; i++)
    {
        lli temp;
        cin >> temp;
        a.pb(mp(temp,2));
    }
    sort(a.begin(),a.end());
    lli f = 3*n,s = 3*m,diff = f-s,ansa = f,ansb = s;
    for(int i = 0; i<n+m; i++)
    {
        lli flag = 0;
        while(i+1<n+m && a[i].x == a[i+1].x)
        {
            flag = 1;
            if(a[i].y == 1)
            {
                f--;
            }
            else
            {
                s--;
            }
            i++;
        }
        if(flag == 1)
        {
            if(a[i].y == 1)
            {
                f--;
            }
            else
            {
                s--;
            }
            if(f-s > diff)
            {
                diff = f-s;
                ansa = f;
                ansb = s;
            }
        }
        else
        {
            if(a[i].y == 1)
            {
                f--;
            }
            else
            {
                s--;
            }
            if(diff < f-s)
            {
                diff = f-s;
                ansa = f;
                ansb = s;
            }
        }
    }
    cout << ansa << ":" << ansb << endl;
}
