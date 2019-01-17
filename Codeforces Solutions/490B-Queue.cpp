#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
#define x first
#define y second
#define mp make_pair
#define pb push_back

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
            ans = ans;
        }
        b/=2;
        a*=a;
        a = a;
    }
    return ans;
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
    int n;
    cin >> n;
    map <int,int> a,b,m;
    int ans[n];
    for(int i = 0; i<n; i++)
    {
        int x,y;
        cin >> x >> y;
        a[x+1] = y+1;
        b[y+1] = x+1;
    }
    if(n%2 == 0)
    {
        int start = 1;
        for(int i = 1; i<n; i+=2)
        {
            ans[i] = a[start]-1;
            start = a[start];
        }
        start = 1;
        for(int i = n-2; i>-1; i-=2)
        {
            ans[i] = b[start]-1;
            start = b[start];
        }
    }
    else
    {
        int start = 1;
        m[1] = 1;
        for(int i = 1; i<n; i+=2)
        {
            ans[i] = a[start]-1;
            start = a[start];
            m[start] = 1;
        }
        for(auto e: a)
        {
            if(m[e.x] == 0 && m[e.y] == 0)
            {
                start = e.x;
            }
        }
        while(a[start]!=0)
        {
            start = a[start];
        }
        for(int i = n-1; i>-1; i-=2)
        {
            ans[i] = start-1;
            start = b[start];
        }
    }
    for(int i = 0; i<n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
