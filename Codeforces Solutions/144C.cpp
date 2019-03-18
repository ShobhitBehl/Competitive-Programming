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

bool ispal(int x)
{
    vector <int> dig;
    while(x > 0)
    {
        dig.pb(x%10);
        x/=10;
    }
    int n = dig.size();
    int l = 0,r = n-1;
    while(l <= r)
    {
        if(dig[l] != dig[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}
lli fib(lli a,lli b,lli n)
{
    a %= M;
    b %= M;
    if(n == 1)
    {
        return a%M;
    }
    else if(n == 2)
    {
        return b%M;
    }
    else
    {
        int c;
        for(int i = 3; i<=n; i++)
        {
            c = (a+b)%M;
            a = b;
            b = c;
        }
        return c%M;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    cin >> s1 >> s2;
    int win = s2.size();
    map <char,int> m1,m2;
    for(int i = 0; i<win; i++)
    {
        m1[s2[i]]++;
    }
    int n = s1.size();
    int l = 0,r = win-1;
    for(int i = 0; i<=r; i++)
    {
        m2[s1[i]]++;
    }
    int ans = 0;
    while(r < n)
    {
        int flag = 0;
        for(int i = 0; i<26; i++)
        {
            if(m1[i+'a'] < m2[i+'a'])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            ans++;
        }
        m2[s1[l]]--;
        m2[s1[r+1]]++;
        r++;
        l++;
    }
    cout << ans << endl;
}
