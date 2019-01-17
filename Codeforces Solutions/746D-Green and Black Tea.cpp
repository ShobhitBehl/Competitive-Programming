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
    lli n,k,a,b;
    cin >> n >> k >> a >> b;
    string s;
    char prev = 'A';
    int temp = 0;
    while(a != 0 || b != 0)
    {
        if(temp == k)
        {
            if(prev == 'G')
            {
                if(b == 0)
                {
                    cout << "NO\n";
                    return 0;
                }
                b--;
                s += "B";
                prev = 'B';
                temp = 1;
            }
            else
            {
                if(a == 0)
                {
                    cout << "NO\n";
                    return 0;
                }
                a--;
                s += "G";
                prev = 'G';
                temp = 1;
            }
        }
        else if(a > b)
        {
            a--;
            s += "G";
            if(prev == 'G')
            {
                temp++;
            }
            else
            {
                prev = 'G';
                temp = 1;
            }
        }
        else
        {
            b--;
            s += "B";
            if(prev == 'B')
            {
                temp++;
            }
            else
            {
                prev = 'B';
                temp = 1;
            }
        }
    }
    cout << s << endl;
}
