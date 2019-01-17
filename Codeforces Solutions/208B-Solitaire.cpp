#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

//#define pi 3.141592653589793238
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
            ans = ans%mod;
        }
        b/=2;
        a*=a;
        a = a%mod;
    }
    return ans%mod;
}

string ans = "NO";
vector <string> a;
map <vector<string>,lli> m;

void solve(vector <string> a)
{
    if(m[a] == 1)
    {
        return;
    }
    else
    {
        m[a] = 1;
        lli temp = a.size();
        if(temp == 1)
        {
            ans = "YES";
        }
        if(temp > 1 && (a[temp-1][0] == a[temp-2][0] || a[temp-1][1] == a[temp-2][1]))
        {
            vector <string> b = a;
            b[temp-2] = b[temp-1];
            b.erase(b.end()-1);
            solve(b);
        }
        if(temp > 3 && (a[temp-1][0] == a[temp-4][0] || a[temp-1][1] == a[temp-4][1]))
        {
            vector <string> b = a;
            b[temp-4] = b[temp-1];
            b.erase(b.end()-1);
            solve(b);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        string s;
        cin >> s;
        a.pb(s);
    }
    solve(a);
    cout << ans << endl;
}
