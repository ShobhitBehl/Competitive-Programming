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

vector<lli> getbinary(lli x)
{
    vector <lli> bin(8,0);
    lli iter = 0;
    while(x > 0)
    {
        if(x%2 == 0)
        {
            bin[iter] = 0;
        }
        else
        {
            bin[iter] = 1;
        }
        x/=2;
        iter++;
    }
    return bin;
}

lli dist(pll a, pll b)
{
    return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y - a.y);
}

vector <lli> a;

void construct(lli x)
{
    if(x > 1e18)
    {
        return;
    }
    a.pb(x*10 + 4);
    a.pb(x*10 + 7);
    construct(x*10 + 4);
    construct(x*10 + 7);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    construct(0);
    a.pb(0);
    sort(a.begin(),a.end());
    lli l1,r1,l2,r2,k;
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    lli iter1 = 1,iter2 = k;
    lli num = 0,templ,tempr;
    while(iter2 < a.size())
    {
        lli lrange = a[iter1-1] + 1;
        lli rrange = a[iter2+1] - 1;
        lli ansr = min(a[iter1],r1);
        lli ansl = max(lrange,l1);
        lli templ = ansl,tempr = ansr;
        lli num1 = ansr-ansl+1;
        ansl = max(a[iter2],l2);
        ansr = min(rrange,r2);
        templ = max(ansl,templ);
        tempr = min(ansr,tempr);
        if(tempr - templ+1 >= 0)
        {
            num -= tempr - templ + 1;
        }
        lli num2 = ansr - ansl +1;
        if(num1 >= 0 && num2 >= 0)
        {
            num += num1*num2;
        }
        ansr = min(a[iter1],r2);
        ansl = max(lrange,l2);
        tempr = ansr;
        templ = ansl;
        num1 = ansr-ansl+ 1;
        ansl = max(a[iter2],l1);
        ansr = min(rrange,r1);
        templ = max(ansl,templ);
        tempr = min(ansr,tempr);
        num2 = ansr-ansl+1;
        if(num1 >= 0 && num2 >= 0)
        {
            num += num1*num2;
        }
        iter1++;
        iter2++;
    }
    double ans = num*1.0/(1.0*(r1-l1+1)*(r2-l2+1));
    cout << ans << endl;
}
