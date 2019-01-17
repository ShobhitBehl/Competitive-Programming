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

struct e
{
    int s,d,c;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n;
    cin >> n;
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    lli m = s1.size();
    map <char,int> m1,m2,m3;
    for(int i = 0; i<m; i++)
    {
        m1[s1[i]]++;
        m2[s2[i]]++;
        m3[s3[i]]++;
    }
    int max1,max2,max3,temp1 = -1,temp2 = -1,temp3 = -1;
    for(auto e : m1)
    {
        max1 = e.y + n;
        if(max1 > m && n != 1)
        {
            max1 = m;
        }
        else if(max1 > m && n == 1)
        {
            max1 = m-1;
        }
        temp1 = max(temp1,max1);
    }
    for(auto e : m2)
    {
        max2 = e.y + n;
        if(max2 > m && n != 1)
        {
            max2 = m;
        }
        else if(max2 > m && n == 1)
        {
            max2 = m-1;
        }
        temp2 = max(temp2,max2);
    }
    for(auto e : m3)
    {
        max3 = e.y + n;
        if(max3 > m && n!=1)
        {
            max3 = m;
        }
        else if(max3 > m && n == 1)
        {
            max3 = m-1;
        }
        temp3 = max(temp3,max3);
    }
    if(temp1 > temp2 && temp1 > temp3)
    {
        cout << "Kuro\n";
    }
    else if(temp2 > temp1 && temp2 > temp3)
    {
        cout << "Shiro\n";
    }
    else if(temp3 > temp1 && temp3 > temp2)
    {
        cout << "Katie\n";
    }
    else
    {
        cout << "Draw\n";
    }
}
