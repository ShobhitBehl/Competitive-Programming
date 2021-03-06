#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pii;
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
    lli hh,mm;
    lli h,d,c,n;
    cin >> hh >> mm;
    cin >> h >> d >> c >> n;
    if(hh >= 20)
    {
        int temp = h/n;
        if(h%n != 0)
        {
            temp++;
        }
        double cost = temp*c*0.8;
        cout << setprecision(20) << cost << endl;
        return 0;
    }
    int dh,dm;
    dh = 20-hh;
    dm = -mm;
    if(mm < 0)
    {
        dh--;
        mm += 60;
    }
    int nob1, nob2;
    nob1 = h/n;
    if(h%n != 0)
    {
        nob1++;
    }
    h = h + d*(dh*60 + dm);
    nob2 = h/n;
    if(h%n != 0)
    {
        nob2++;
    }
    long double cost1, cost2;
    cost1 = nob1*c;
    cost2 = nob2*0.8*c;
    if(cost1 < cost2)
    {
        cout << setprecision(20) << cost1 << endl;
    }
    else
    {
        cout << setprecision(20) << cost2 << endl;
    }
}
