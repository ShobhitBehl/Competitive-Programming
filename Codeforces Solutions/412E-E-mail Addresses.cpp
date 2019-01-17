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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    string s;
    cin >> s;
    lli ans = 0,f,sec;
    lli n = s.size();
    for(int i = 0; i<n; i++)
    {
        if(s[i] == '@')
        {
            lli flag = 0;
            lli iter = i-1;
            while(iter >= 0 && s[iter] != '@' && s[iter] != '.')
            {
                iter--;
            }
            f = 0;
            while(iter+1 < i)
            {
                if(s[iter+1] >= 'a' && s[i] <= 'z')
                {
                    f++;
                }
                iter++;
            }
            iter = i+1;
            while(iter < n && s[iter] != '.')
            {
                if(s[iter] == '@' || s[iter] == '_')
                {
                    flag = 1;
                    break;
                }
                iter++;
            }
            if(flag == 1 || iter-(i+1) == 0)
            {
                continue;
            }
            lli iter2 = iter+1;
            while(iter2 < n && s[iter2] >= 'a' && s[iter2] <= 'z')
            {
                iter2++;
            }
            sec = iter2 - (iter + 1);
            ans += f*sec;
        }
    }
    cout << ans << endl;
}
