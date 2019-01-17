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
            ans = ans;
        }
        b/=2;
        a*=a;
        a = a;
    }
    return ans;
}

vector <int> getbinary(int x)
{
    vector <int> bin(10,0);
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

int getnum(vector <int> bin)
{
    int t = 1;
    int n = bin.size();
    int ret = 0;
    for(int i = 0; i<n; i++)
    {
        ret += t*bin[i];
        t*=2;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    int n,k;
    cin >> n >> k;
    cin >> s;
    s += '!';
    int num = 0;
    if(k == 2)
    {
        string s1,s2;
        for(int i = 0; i<n; i++)
        {
            if(i%2 == 0)
            {
                s1 += "A";
                s2 += "B";
            }
            else
            {
                s1 += "B";
                s2 += "A";
            }
        }
        int num1 = 0,num2 = 0;
        for(int i = 0; i<n; i++)
        {
            if(s[i] != s1[i])
            {
                num1++;
            }
            if(s[i] != s2[i])
            {
                num2++;
            }
        }
        if(num1 < num2)
        {
            cout << num1 << endl << s1 << endl;
        }
        else
        {
            cout << num2 << endl << s2 << endl;
        }
    }
    else
    {
        string ans;
        for(int i = 0; i<n; i++)
        {
            int count = 1;
            int start = i;
            while(i+1<n && s[i] == s[i+1])
            {
                count++;
                i++;
            }
            num += count/2;
            if(count%2 == 1)
            {
                for(int j = 0; j<count; j++)
                {
                    if(j%2 == 0)
                    {
                        ans += s[start];
                    }
                    else
                    {
                        if(s[start] == 'A' + k - 1)
                        {
                            ans += "A";
                        }
                        else
                        {
                            ans += s[start] + 1;
                        }
                    }
                }
            }
            else
            {
                char c;
                for(int j = 0; j<k; j++)
                {
                    c = 'A' + j;
                    if(s[i] != c && s[i+1] != c)
                    {
                        break;
                    }
                }
                for(int j = 0; j<count; j++)
                {
                    if(j%2 == 0)
                    {
                        ans += s[start];
                    }
                    else
                    {
                        ans += c;
                    }
                }
            }
        }
        cout << num << endl << ans << endl;
    }
}
