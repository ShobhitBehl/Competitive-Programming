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

bool comparator(const pll &a,const pll &b)
{
    if(a.x == b.x)
    {
        return a.y < b.y;
    }
    return a.x > b.x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    lli n,k;
    cin >> n >> k;
    lli temp;
    vector <pll> negdist;
    lli curr = 0;
    lli ans = 0;
    lli prev = -1;
    for(int i = 0; i<n; i++)
    {
        cin >> temp;
        if(temp >= 0 && curr == 1)
        {
            ans++;
            curr = 0;
        }
        else if(temp < 0 && curr == 0)
        {
            k--;
            ans++;
            curr = 1;
            if(prev != -1)
            {
                negdist.pb(mp(2,i-prev-1));
            }
            prev = i;
        }
        else if(temp < 0 && curr == 1)
        {
            k--;
            negdist.pb(mp(2,i-prev-1));
            prev = i;
        }
    }
    if(prev != -1)
    {
        negdist.pb(mp(1,n-prev-1));
    }
    if(k < 0)
    {
        cout << -1 << endl;
        return 0;
    }
    sort(negdist.begin(),negdist.end(),comparator);
    for(int i = 0; i<negdist.size(); i++)
    {
        if(negdist[i].y <= k && negdist[i].y != 0)
        {
            ans-=negdist[i].x;
            k-=negdist[i].y;
        }
    }
    cout << ans << endl;
}
