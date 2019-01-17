#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define pi 3.141592653589793238
typedef pair<int,int> pii;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    vector <int> ones;
    int z = 0,o = 0;
    for(int i = 0; i<n; i++)
    {
        if(s[i] == '1')
        {
            ones.push_back(i);
            o++;
        }
        else
        {
            z++;
        }
        if(o > z)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    z = 0, o = 0;
    for(int i = n-1; i>=0; i--)
    {
        if(s[i] == '1')
        {
            o++;
        }
        else
        {
            z++;
        }
        if(o > z)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    z = 0,o = 0;
    vector <int> zb,za;
    for(int i = 0; i<n; i++)
    {
        if(s[i] == '1')
        {
            o++;
        }
        else if(s[i] == '0')
        {
            if(o > 0)
            {
                o--;
                za.push_back(i);
            }
        }
    }
    o = 0;
    for(int i = n-1; i>=0; i--)
    {
        if(s[i] == '1')
        {
            o++;
        }
        else if(s[i] == '0')
        {
            if(o > 0)
            {
                o--;
                zb.push_back(i);
            }
        }
    }
    o = za.size()-1;
    /*for(int i = 0; i<=o; i++)
    {
        cout << za[i] << " ";
    }
    cout << endl;
    for(int i = 0 ;i <=o; i++)
    {
        cout << zb[o-i] << " ";
    }
    cout << endl;*/
    vector <int> b(n,0),a(n,0);
    vector <int> temp;
    vector < vector<int> > ans;
    map <int,int> m;
    for(int i = 0; i<=o; i++)
    {
        //cout << zb[o-i] << " " << ones[i] << " " << za[i] << " " << m[zb[o-i]] << endl;
        if(m[zb[o-i]] == 0)
        {
            temp.pb(zb[o-i]);
            temp.pb(ones[i]);
            temp.pb(za[i]);
            ans.pb(temp);
            temp.clear();
            m[za[i]] = ans.size();
            a[zb[o-i]] = 1;
            a[ones[i]] = 1;
            a[za[i]] = 1;
        }
        else
        {
            ans[m[zb[o-i]]-1].pb(ones[i]);
            ans[m[zb[o-i]]-1].pb(za[i]);
            m[za[i]] = m[zb[o-i]];
            a[za[i]] = 1;
            a[ones[i]] = 1;
            a[zb[o-i]] = 1;
        }
    }
    temp.clear();
    for(int i = 0; i<n; i++)
    {
        if(a[i] == 0)
        {
            temp.pb(i);
            ans.pb(temp);
            temp.clear();
        }
    }
    cout << ans.size() << endl;
    int siz = ans.size();
    for(int i =0 ; i<siz; i++)
    {
        cout << ans[i].size();
        for(int j = 0; j<ans[i].size(); j++)
        {
            cout << " " << ans[i][j]+1;
        }
        cout << endl;
    }
}
