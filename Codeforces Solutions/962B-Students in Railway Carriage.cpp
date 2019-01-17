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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,a,b;
    cin >> n >> a >> b;
    char s[n];
    for(int i = 0; i<n; i++)
    {
        cin >> s[i];
    }
    char prev = '*';
    lli ans = 0;
    for(int i = 0; i<n; i++)
    {
        if(s[i] == '.')
        {
            if(prev == '*')
            {
                if(a > b && a!=0)
                {
                    //cout << "1\n";
                    a--;
                    prev = 'a';
                }
                else if(b >= a && b!=0)
                {
                    b--;
                    //cout << "2\n";
                    prev = 'b';
                }
                ans++;
            }
            else if(prev == 'a' && b > 0)
            {
                //cout << "3\n";
                b--;
                ans++;
                prev = 'b';
            }
            else if(prev == 'b' && a > 0)
            {
                //cout << "4\n";
                a--;
                ans++;
                prev = 'a';
            }
            else if(prev == 'a' && b == 0)
            {
                //cout << "5\n";
                prev = '*';
            }
            else if(prev == 'b' && a == 0)
            {
                //cout << "6\n";
                prev = '*';
            }
        }
        else
        {
            //cout << "7\n";
            prev = '*';
        }
        if(a == 0 && b == 0)
        {
            break;
        }
    }
    cout << ans << endl;
}
