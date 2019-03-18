#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define pi 3.141592653589793238
typedef pair<int,int> pii;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,k;
    cin >> n >> k;
    lli a[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    lli maxi = 0,mini = 0;
    for(int i = 0; i<n; i++)
    {
        if(a[i] > a[maxi])
        {
            maxi = i;
        }
        if(a[i] < a[mini])
        {
            mini = i;
        }
    }
    lli balance = a[maxi] - a[mini],prev1,prev2;
    if(balance <= 1)
    {
        cout << balance << " " << 0 << endl;
        return 0;
    }
    lli ans = 0;
    vector < pair <lli,lli> > out;
    while(k)
    {
        a[maxi]--;
        a[mini]++;
        prev1 = maxi;
        prev2 = mini;
        maxi = 0,mini = 0;
        for(int i = 0; i<n; i++)
        {
            if(a[i] > a[maxi])
            {
                maxi = i;
            }
            if(a[i] < a[mini])
            {
                mini = i;
            }
        }
        balance = a[maxi]-a[mini];
        k--;
        out.pb(mp(prev1,prev2));
        ans++;
        if(a[maxi] <= a[mini] + 1)
        {
            break;
        }
    }
    cout << balance << " " << ans << endl;
    for(int i = 0; i<ans; i++)
    {
        cout << out[i].first+1 << " " << out[i].second+1 << endl;
    }
}
