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

bool solve(lli n, lli k, lli d1, lli d2)
{
    for(int i = -1; i<2; i++)
    {
        for(int j = -1; j<2; j++)
        {
            if(i == 0 || j == 0)
            {
                continue;
            }
            else
            {
                lli D1 = i*d1;
                lli D2 = j*d2;
                if((k+D2-D1) % 3 != 0)
                {
                    continue;
                }
                else
                {
                    lli x2 = (k+D2-D1)/3;
                    if(x2 >= 0 && x2 <= k)
                    {
                        lli x1 = x2 + D1;
                        lli x3 = x2 - D2;
                        if(x1 >= 0 && x1 <=k && x3 >=0 && x3 <= k)
                        {
                            if(x1 <= n/3 && x2 <=n/3 && x3 <= n/3)
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for(int t1 = 0; t1<t; t1++)
    {
        lli n,k,d1,d2;
        cin >> n >> k >> d1 >> d2;
        if(n%3 != 0)
        {
            cout << "no\n";
        }
        else
        {
            if(solve(n,k,d1,d2))
            {
                cout << "yes\n";
            }
            else
            {
                cout << "no\n";
            }
        }
    }
}
