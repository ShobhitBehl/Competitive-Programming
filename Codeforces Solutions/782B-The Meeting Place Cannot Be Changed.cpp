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

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
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

bool dfs(map <int,vector<int> > g, int start, int end, vector <int> col)
{
    stack <int> s;
    s.push(start);
    col[start] = 1;
    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        for(auto v: g[top])
        {
            if(col[v] == 0)
            {
                if(v == end)
                {
                    return true;
                }
                s.push(v);
                col[v] = 1;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    double x[n];
    double v[n];
    for(int i = 0; i<n; i++)
    {
        cin >> x[i];
    }
    for(int i = 0; i<n; i++)
    {
        cin >> v[i];
    }
    long double l = 0,r = 1e9,ans;
    while(l<=r)
    {
        long double mid = (l+r)/2;
        long double maxl = -1,minr = 1e9+1;
        for(int i = 0; i<n; i++)
        {
            long double a = x[i] + mid*v[i];
            long double b = x[i] - mid*v[i];
            if(a < minr)
            {
                minr = a;
            }
            if(b > maxl)
            {
                maxl = b;
            }
        }
        if(maxl <= minr)
        {
            r = mid-0.000000001;
            ans = mid;
        }
        else
        {
            l = mid+0.000000001;
        }
    }
    cout << setprecision(20) << ans << endl;
}
