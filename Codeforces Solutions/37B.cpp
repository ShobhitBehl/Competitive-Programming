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
    lli n,max,reg;
    cin >> n >> max >> reg;
    pair <int,int> s[n];
    for(int i = 0; i<n; i++)
    {
        cin >> s[i].x >> s[i].y;
        s[i].x = s[i].x * max/100;
    }
    int health = max;
    int damage = 0;
    vector < pair<int,int> > ans;
    lli tim = 0;
    map <int,int> m;
    while(health > 0)
    {
        int maxx = -1,maxind;
        for(int i = 0; i<n; i++)
        {
            if(s[i].x >= health && m[i] == 0)
            {
                if(maxx < s[i].y)
                {
                    maxx = s[i].y;
                    maxind = i;
                }
            }
        }
        //cout << maxx << " " << reg << endl;
        if(maxx == -1 && damage <= reg)
        {
            cout << "NO\n";
            return 0;
        }
        if(maxx != -1)
        {
            ans.pb(mp(tim,maxind+1));
            //cout << "adding scroll " << maxind;
            m[maxind] = 1;
            damage += maxx;
        }
        //cout << " " << damage << endl;
        health -= damage;
        health += reg;
        if(health > max)
        {
            health = max;
        }
        //cout << health << endl;
        tim++;
    }
    cout << "YES\n";
    cout << tim << " " << ans.size() << endl;
    for(int i = 0; i<ans.size(); i++)
    {
        cout << ans[i].x << " " << ans[i].y << endl;
    }
}
