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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    string out;
    int x = 0;
    for(int i = 0; i<n; i++)
    {
        if(s[i] == 'e')
        {
            i++;
            while(i<n)
            {
                x *=10;
                x += (s[i]-'0');
                i++;
            }
        }
    }
    int dec = 0;
    for(int i = 0; i<n; i++)
    {
        if(s[i] != '.' && s[i] != 'e')
        {
            out += s[i];
        }
        else if(s[i] == '.')
        {
            i++;
            while(x > 0 && s[i] != 'e')
            {
                out += s[i];
                x--;
                i++;
            }
            if(s[i] == 'e')
            {
                break;
            }
            else
            {
                out += '.';
                dec = 1;
            }
            i--;
        }
        else if(s[i] == 'e')
        {
            break;
        }
    }
    while(x > 0)
    {
        out += '0';
        x--;
    }
    n = out.size();
    int start = 0,end = n-1;
    for(int i = 0; i<n; i++)
    {
        if(out[i] == '0')
        {
            start = i+1;
        }
        if(out[i] == '.')
        {
            start = i-1;
            break;
        }
        if(out[i] != '0')
        {
            start = i;
            break;
        }
    }
    if(dec == 1)
    {
        for(int i = n-1; i>=0; i--)
        {
            if(out[i] == '0')
            {
                end = i-1;
            }
            if(out[i] == '.')
            {
                end = i-1;
                break;
            }
            if(out[i] != '0')
            {
                end = i;
                break;
            }
        }
    }
    for(int i = start; i<=end; i++)
    {
        cout << out[i];
    }
    cout << endl;
}
