#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

#define pi 3.141592653589793238
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

long long int min(long long int a, long long int b)
{
    return a>b?b:a;
}

long long int min(long long int a, long long int b, lli c)
{
    if(a<=b && a<=c)
    {
        return a;
    }
    else if(b<=a && b<=c)
    {
        return b;
    }
    else
    {
        return c;
    }
}

long long int max(long long int a, long long int b)
{
    return a>b?a:b;
}

lli lcm(lli a, lli b)
{
    return (a*b/gcd(a,b));
}

bool check(lli x)
{
    while(x%2 == 0)
    {
        x/=2;
    }
    while(x%3 == 0)
    {
        x/=3;
    }
    if(x != 1)
    {
        return false;
    }
    return true;
}

lli ans(int num, int n)
{
    if(n == 1)
    {
        return num;
    }
    else if(n == 2)
    {
        return num+1;
    }
    else if(n == 3)
    {
        return num+2;
    }
    else if(n%3 == 0)
    {
        return ans(num+2,(n-1)/2);
    }
    else if(n%2 == 0)
    {
        return ans(num+1,n/2);
    }
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
lli ans(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else if(n == 1 || n == 2)
    {
        return 0;
    }
    else if(n<0)
    {
        return 0;
    }
    else
    {
        return (ans(n-7) | ans(n-3));
    }
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
            ans = ans%1000000009;
        }
        b/=2;
        a*=a;
        a = a%1000000009;
    }
    return ans%1000000009;
}

lli dist(int x1, int y1, int x2, int y2)
{
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

unordered_map <int,int> m1;
int a[1000001];

bool check(int n, int m, int xc, int yc)
{
    unordered_map <int,int> temp;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            int req = abs(xc-i) + abs(yc-j);
            temp[req]++;
        }
    }
    for(auto e : temp)
    {
        if(e.y != m1[e.x])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int maxx = -1;
    for(int i = 0; i<t; i++)
    {
        cin >> a[i];
        m1[a[i]]++;
        maxx = max(maxx,a[i]);
    }
    if(t==1 and a[0]==0)
    {
        cout<<1<<" "<<1<<endl;
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    else if(t==1)
    {
        cout<<-1<<endl;
        return 0;
    }
    int xc = 1e9;
    for(auto e : m1)
    {
        if(e.y != 4*e.x && e.x != 0)
        {
            xc = min(xc,e.x);
        }
    }
    for(int i = 1; i*i <= t; i++)
    {
        if(t%i == 0)
        {
            int n = i;
            int m = t/i;
            int yc = n+m-xc-maxx;
            if(check(n,m,xc,yc))
            {
                cout << n << " " << m << endl;
                cout << xc << " " << yc << endl;
                return 0;
            }
            else if(check(m,n,xc,yc))
            {
                cout << m << " " << n << endl;
                cout << xc << " " << yc << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}
