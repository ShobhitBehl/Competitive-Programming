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
    lli n;
    cin >> n;
    lli a[n+1],b[n+1],sum[n+1];
    sum[0] = 0;
    for(int i = 1; i<=n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    set <int> s;
    for(int i = 1; i<=n; i++)
    {
        cin >> b[i];
        s.insert(b[i]);
    }
    vector <lli> ans;
    ans.pb(0);
    lli anstill = -1;
    for(int i = n; i>1; i--)
    {
        s.erase(b[i]);
        set <int> :: iterator it = s.lower_bound(b[i]);
        int l;
        if(it == s.begin())
        {
            l =  0;
        }
        else
        {
            l = *(--it);
        }
        it = s.upper_bound(b[i]);
        int r;
        if(it == s.end())
        {
            r = n+1;
        }
        else
        {
            r = *it;
        }
        //cout << l << " " << r << " " << sum[r-1]-sum[l] << endl;
        anstill = max(anstill,sum[r-1]-sum[l]);
        ans.pb(anstill);
    }
    for(int i = n-1; i>=0 ;i--)
    {
        cout << ans[i] << endl;
    }
}
