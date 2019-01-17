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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    map <char,int> m;
    int n = s.size();
    for(int i = 0; i<n; i++)
    {
        m[s[i]]++;
    }
    m['1']--;
    m['6']--;
    m['8']--;
    m['9']--;
    int r = 0;
    string ans;
    for(int i = 1; i<10; i++)
    {
        while(m[i+'0'] > 0)
        {
            ans += i+'0';
            m[i+'0']--;
            r = 10*r + i;
            r %= 7;
        }
    }
    int cons = r;
    string num = "1689";
    string ending;
    while(true)
    {
        r = cons;
        for(int i = 0; i<4; i++)
        {
            r = 10*r + (num[i]-'0');
            r %= 7;
        }
        for(int i = 0; i<m['0']; i++)
        {
            ending += '0';
            r *= 10;
            r %= 7;
        }
        if(r == 0)
        {
            cout << ans + num + ending << endl;
            return 0;
        }
        else
        {
            ending.clear();
            next_permutation(num.begin(),num.end());
        }
    }
}
