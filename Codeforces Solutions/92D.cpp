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

vector <int> getbinary(int x)
{
    vector <int> bin(10,0);
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

int getnum(vector <int> bin)
{
    int t = 1;
    int n = bin.size();
    int ret = 0;
    for(int i = 0; i<n; i++)
    {
        ret += t*bin[i];
        t*=2;
    }
    return ret;
}

vector <vector <int> > dp(200001,vector <int> (1,0));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    pair <int,int> a[n+1];
    int b[n+1];
    for(int i = 1; i<=n; i++)
    {
        int temp;
        cin >> b[i];
        a[i] = mp(b[i],n-i+1);
    }
    sort(a+1,a+n+1);
    int minind = a[1].y;
    int prevminind = a[1].y;
    int ans[n+1];
    ans[a[1].y] = -1;
    for(int i = 2; i<=n; i++)
    {
        if(minind < a[i].y)
        {
            if(b[n-minind+1] == a[i].x)
            {
                if(prevminind == minind)
                {
                    ans[a[i].y] = -1;
                }
                else
                {
                    if(a[i].y > prevminind)
                    {
                        ans[a[i].y] = a[i].y - prevminind - 1;
                    }
                    else
                    {
                        ans[a[i].y] = -1;
                    }
                }
            }
            else
            {
                ans[a[i].y] = a[i].y - minind - 1;
            }
        }
        else
        {
            ans[a[i].y] = -1;
            prevminind = minind;
            minind = a[i].y;
        }
    }
    for(int i = n; i>=1; i--)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
