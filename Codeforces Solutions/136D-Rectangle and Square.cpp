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

lli check(pll a,pll b, pll c, pll d)
{
    lli d1,d2,d3,d4,d5,d6;
    d1 = dist(a,b);
    d2 = dist(b,c);
    d3 = dist(c,d);
    d4 = dist(a,d);
    d5 = dist(a,c);
    d6 = dist(b,d);
    unordered_map <lli,lli> m;
    set <lli> s;
    m[d1]++;
    m[d2]++;
    m[d3]++;
    m[d4]++;
    m[d5]++;
    m[d6]++;
    s.insert(d1);
    s.insert(d2);
    s.insert(d3);
    s.insert(d4);
    s.insert(d5);
    s.insert(d6);
    if(s.size() == 2)
    {
        lli o,t;
        for(auto e : m)
        {
            if(e.y == 4)
            {
                o = e.x;
            }
            else if(e.y == 2)
            {
                t = e.x;
            }
            else
            {
                return 0;
            }
        }
        if(2*o == t)
        {
            return 1;
        }
    }
    if(s.size() == 3)
    {
        lli o = -1,t = -1,th = -1;
        for(auto e : m)
        {
            if(e.y == 2)
            {
                if(o == -1)
                {
                    o = e.x;
                }
                else if(t == -1)
                {
                    t = e.x;
                }
                else
                {
                    th = e.x;
                }
            }
            else
            {
                return 0;
            }
        }
        if(o + t == th || o + th == t || th + t == o)
        {
            return 2;
        }
    }
    return 0;
    s.clear();
    m.clear();
}

lli notinline(pll a,pll b, pll c, pll d)
{
    pll pts[4] = {a,b,c,d};
    lli zero = 0;
    unordered_map <double,lli> m;
    for(int i = 0; i<4; i++)
    {
        for(int j = i+1; j<4; j++)
        {
            if(pts[j].x - pts[i].x == 0)
            {
                zero++;
            }
            else
            {
                m[((double)(pts[j].y) - (double)(pts[i].y))*1.0/((double)(pts[j].x) - (double)(pts[i].x))*1.0]++;
            }
        }
    }
    if(zero > 2)
    {
        return 0;
    }
    for(auto e : m)
    {
        if(e.y > 2)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    pll a[8];
    for(int i = 0; i<8; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    lli temp = power(2,8);
    for(int i = 1; i<temp; i++)
    {
        vector <lli> bin = getbinary(i);
        lli count = 0;
        for(int i = 0; i<8; i++)
        {
            if(bin[i] == 1)
            {
                count++;
            }
        }
        if(count == 4)
        {
            vector <pll> fir,sec;
            for(int i = 0; i<8; i++)
            {
                if(bin[i] == 1)
                {
                    fir.pb(a[i]);
                }
                else
                {
                    sec.pb(a[i]);
                }
            }
            if(notinline(fir[0],fir[1],fir[2],fir[3]) && notinline(sec[0],sec[1],sec[2],sec[3]))
            {
                if(check(fir[0],fir[1],fir[2],fir[3]) == 1)
                {
                    if(check(sec[0],sec[1],sec[2],sec[3]) != 0)
                    {
                        cout << "YES\n";
                        for(int i = 0; i<8; i++)
                        {
                            if(bin[i] == 1)
                            {
                                cout << i+1 << " ";
                            }
                        }
                        cout << endl;
                        for(int i = 0; i<8; i++)
                        {
                            if(bin[i] == 0)
                            {
                                cout << i+1 << " ";
                            }
                        }
                        cout << endl;
                        return 0;
                    }
                }
                else if(check(sec[0],sec[1],sec[2],sec[3]) == 1)
                {
                    if(check(fir[0],fir[1],fir[2],fir[3]) != 0)
                    {
                        cout << "YES\n";
                        for(int i = 0; i<8; i++)
                        {
                            if(bin[i] == 0)
                            {
                                cout << i+1 << " ";
                            }
                        }
                        cout << endl;
                        for(int i = 0; i<8; i++)
                        {
                            if(bin[i] == 1)
                            {
                                cout << i+1 << " ";
                            }
                        }
                        cout << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO\n";
}
