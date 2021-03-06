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
    int n,m;
    cin >> n >> m;
    e a[m];
    map <int,int> m1;
    vector <int> ans;
    for(int i = 0; i<m; i++)
    {
        cin >> a[i].s >> a[i].d >> a[i].c;
        m1[i] = a[i].c;
    }
    for(int i = 1; i<=n; i++)
    {
        int exam = 0;
        int minex = INT_MAX;
        int minind = -1;
        //cout << "day " << i << endl;
        for(int j = 0; j<m; j++)
        {
            if(a[j].d == i)
            {
                exam = 1;
                if(m1[j] != 0)
                {
                    cout << -1 << endl;
                    return 0;
                }
                else
                {
                    //cout << "giving exam\n";
                    ans.pb(m+1);
                    break;
                }
            }
            if(a[j].s <= i && m1[j] > 0)
            {
                if(minex > a[j].d)
                {
                    minex = a[j].d;
                    minind = j;
                }
            }
        }
        if(exam == 0)
        {

            //cout << "studying for " << minind + 1 << endl;
            ans.pb(minind + 1);
            m1[minind]--;
        }
    }
    for(int i = 0; i<n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
