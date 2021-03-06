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
            ans = ans%1000000007;
        }
        b/=2;
        a*=a;
        a = a%1000000007;
    }
    return ans%1000000007;
}

lli mod(lli a, lli b)
{
    return (((a%b)+b)%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,k;
    cin >> n >> k;
    lli a[n+1];
    lli sum[n+1];
    sum[0] = 0;
    for(int i = 1; i<=n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1]+a[i];
    }
    lli sum1 = 0,sum2 = 0;
    lli total = -1;
    pll max = mp(-1,-1);
    pll ans;
    for(int i = n-2*k; i>=0; i--)
    {
        sum1 = sum[i+k] - sum[i];
        sum2 = sum[i+2*k] - sum[i+k];
        //cout << sum1 << " " << sum2 << endl;
        if(sum2 >= max.x)
        {
            //cout << "changing max to " << sum2 << " " << i+k << endl;
            max = mp(sum2,i+k);
        }
        if(sum1+max.x >= total)
        {
            //cout << "found better answer " << total << endl;
            total = sum1+max.x;
            ans = mp(i,max.y);
        }
    }
    cout << ans.x+1 << " "  << ans.y+1 << endl;
}
