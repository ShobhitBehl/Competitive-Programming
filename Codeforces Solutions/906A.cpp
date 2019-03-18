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
            ans = ans%M;
        }
        b/=2;
        a*=a;
        a = a%M;
    }
    return ans%M;
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

struct aim
{
    double x,y,p,t;
};

bool comparator(const aim &a, const aim &b)
{
    return a.t < b.t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    pair <char,string> a[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    char fin = (a[n-1].y)[0];
    int max = -1;
    for(int i = 0; i<26; i++)
    {
        char c = 'a'+i;
        if(c == fin)
        {
            continue;
        }
        //cout << c << endl;
        int flagx = 0;
        for(int i = 0; i<n; i++)
        {
            string temp = a[i].y;
            //cout << a[i].x << " " << temp << endl;
            if(a[i].x == '?' && (a[i].y)[0] == c)
            {
                if(max < i)
                {
                    max = i;
                }
                flagx = 1;
                break;
            }
            else if(a[i].x == '!')
            {
                int n1 = temp.size(),flag = 0;
                for(int j = 0; j<n1; j++)
                {
                    if(temp[j] == c)
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    if(max < i)
                    {
                        max = i;
                    }
                    flagx = 1;
                    break;
                }
            }
            else
            {
                int n1 = a[i].y.size(),flag = 0;
                for(int j = 0; j<n1; j++)
                {
                    if((a[i].y)[j] == c)
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1)
                {
                    if(max < i)
                    {
                        max = i;
                    }
                    flagx = 1;
                    break;
                }
            }
        }
        if(flagx == 0)
        {
            max = n-1;
        }
        //cout << max << endl << endl;
    }
    int ext = 0;
    for(int i = max+1; i<n; i++)
    {
        if((a[i].x == '?' && i != n-1) || a[i].x == '!')
        {
            ext++;
        }
    }
    cout << ext << endl;
}
