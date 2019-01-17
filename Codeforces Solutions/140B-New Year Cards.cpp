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
    int n;
    cin >> n;
    map < pair<int,int>,int > m1;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            int temp;
            cin >> temp;
            m1[mp(i,temp)] = j;
        }
    }
    int b[n+1];
    map <int,int> m2;
    for(int i = 1; i<=n; i++)
    {
        cin >> b[i];
        m2[b[i]] = i;
    }
    int ans[n+1][n+1];
    set <int> s;
    for(int i = 1; i<=n; i++)
    {
        s.insert(i);
        int no1 = -1,no2 = -1,min1 = n+1,min2 = n+1;
        for(auto e : s)
        {
            if(m2[e] < min1)
            {
                min2 = min1;
                min1 = m2[e];
                no2 = no1;
                no1 = e;
            }
            else if(m2[e] < min2)
            {
                min2 = m2[e];
                no2 = e;
            }
        }
        if(no2 == -1)
        {
            no2 = no1;
        }
        for(int j = 1; j<=n; j++)
        {
            if(j == no1 && j == no2)
            {
                ans[i][j] = -1;
            }
            else if(j != no1)
            {
                ans[i][j] = no1;
            }
            else if(j == no1 && j!=no2)
            {
                ans[i][j] = no2;
            }
        }
    }
    for(int j = 1; j<=n; j++)
    {
        int min = 1e9,out;
        for(int i = 1; i<=n; i++)
        {
            if(ans[i][j] != -1)
            {
                if(m1[mp(j,ans[i][j])] < min)
                {
                    min = m1[mp(j,ans[i][j])];
                    out = i;
                }
            }
        }
        cout << out << " ";
    }
    cout << endl;
}
