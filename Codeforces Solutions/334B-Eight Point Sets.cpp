#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
typedef set<lli> sl;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;
#define x first
#define y second
#define mp make_pair
#define pb push_back

lli M = 1000000007;

lli min(lli a, lli b, lli c, lli d)
{
    lli arr[4] = {a,b,c,d};
    sort(arr,arr+4);
    return arr[0];
}

lli max(lli a, lli b, lli c, lli d)
{
    lli arr[4] = {a,b,c,d};
    sort(arr,arr+4);
    return arr[3];
}

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

double distsqrd(double x1, double y1, double x2, double y2)
{
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

lli fact(lli x)
{
    lli ans = 1;
    if(x == 0)
    {
        return 1;
    }
    while(x > 0)
    {
        ans = (ans*x)%1000000007;
        x--;
    }
    return ans%1000000007;
}

lli power(lli a,lli b)
{
    lli ans = 1;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            ans *= a;
            ans = ans%M;
        }
        b/=2;
        a*=a;
        a = a%M;
    }
    return ans%M;
}

lli mod(lli a, lli b)
{
    return (((a%b)+b)%b);
}

vector <int> getbinary(int x)
{
    vector <int> bin(16,0);
    int iter = 0;
    while(x > 0)
    {
        if(x%2 == 1)
        {
            bin[iter] = 1;
        }
        else
        {
            bin[iter] = 0;
        }
        iter++;
        x/=2;
    }
    return bin;
}

struct aim
{
    double x,y,p,t;
};

bool comparator(const aim &a, const aim &b)
{
    return a.t < b.t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pii a[8];
    map <pii,int> m;
    si s1,s2;
    for(int i = 0; i<8; i++)
    {
        cin >> a[i].x >> a[i].y;
        s1.insert(a[i].x);
        s2.insert(a[i].y);
        m[a[i]] = 1;
    }
    if(s1.size() != 3 || s2.size() != 3)
    {
        cout << "ugly\n";
        return 0;
    }
    else
    {
        int x1,x2,x3 = 0,y1,y2,y3 = 0;
        for(auto e : s1)
        {
            if(x3 == 0)
            {
                x1 = e;
            }
            else if(x3 == 1)
            {
                x2 = e;
            }
            else
            {
                x3 = e;
                break;
            }
            x3++;
        }
        for(auto e : s2)
        {
            if(y3 == 0)
            {
                y1 = e;
            }
            else if(y3 == 1)
            {
                y2 = e;
            }
            else
            {
                y3 = e;
                break;
            }
            y3++;
        }
        if(m[mp(x2,y2)] == 1 || m[mp(x1,y1)] == 0 || m[mp(x1,y2)] == 0 || m[mp(x1,y3)] == 0 || m[mp(x2,y1)] == 0 || m[mp(x2,y3)] == 0 || m[mp(x3,y1)] == 0 || m[mp(x3,y2)] == 0 || m[mp(x3,y3)] == 0)
        {
            cout << "ugly\n";
            return 0;
        }
    }
    cout << "respectable\n";
}
