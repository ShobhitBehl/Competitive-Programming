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

vector<int> getprimes()
{
    vector <int> pl(2000001,1);
    for(int i = 2; i<2000001; i++)
    {
        if(pl[i] == 1)
        {
            for(int j = 2*i; j<2000001; j+=i)
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    vector < vector <int> > g(100,vector <int> (100,0));
    int vertices = 3;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(i!=j)
            {
                g[i][j] = 1;
            }
        }
    }
    k--;
    while(k)
    {
        int n = 1;
        while(n<vertices && n*(n-1)/2 <= k)
        {
            n++;
        }
        if(n*(n-1)/2 > k)
        {
            n--;
        }
        //cout << n << endl;
        k -= n*(n-1)/2;
        for(int i = 0; i<n; i++)
        {
            g[i][vertices] = 1;
            g[vertices][i] = 1;
        }
        vertices++;
    }
    cout << vertices << endl;
    for(int i = 0; i<vertices; i++)
    {
        for(int j = 0; j<vertices; j++)
        {
            cout << g[i][j];
        }
        cout << endl;
    }
    /*int t;
    scanf("%d",&t);
    for(int x = 0; x<t; x++)
    {
        int n;
        scanf("%d",&n);
        int a[n+1];
        vector <int> can;
        int sum[n+1];
        sum[0] = 0;
        for(int i = 1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            can.pb(i);
            sum[i] = sum[i-1]+a[i];
        }
    }*/
}
