#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
typedef set<lli> sl;
typedef map<int,int> mii;
typedef set<int> si;
#define x first
#define y second
#define mp make_pair
#define pb push_back

lli power(lli a, lli p)
{
    lli ans = 1;
    while(p > 0)
    {
        if(p%2)
        {
            ans *= a;
            ans %= 1000000007;
        }
        a*=a;
        a%=1000000007;
        p/=2;
    }
    return ans%1000000007;
}

vector <lli> getbinary(lli x)
{
    vector <lli> bin(101,0);
    int iter = 0;
    while(x > 0)
    {
        bin[iter] = x%2;
        iter++;
        x/=2;
    }
    return bin;
}

unordered_map <string,lli> m;

lli value(string s)
{
    lli temp = s.size();
    lli iter1 = 0,num = 0;
    while(iter1 < temp && s[iter1] == '&')
    {
        iter1++;
        num--;
    }
    lli iter2 = temp-1;
    while(iter2 > -1 && s[iter2] == '*')
    {
        iter2--;
        num++;
    }
    string t;
    for(int i = iter1; i<=iter2; i++)
    {
        t += s[i];
    }
    if(m.find(t) == m.end())
    {
        return -1;
    }
    if(m[t] == -1)
    {
        return -1;
    }
    if(m[t]+num < 0)
    {
        return -1;
    }
    return m[t]+num;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli k1,k2,k3,t1,t2,t3;
    cin >> k1 >> k2 >> k3 >> t1 >> t2 >> t3;
    lli n;
    cin >> n;
    lli a[n],b[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    for(int i = 0; i<k1 && i<n; i++)
    {
        b[i] += t1;
    }
    int iter = k1;
    while(iter < n)
    {
        b[iter] = max(b[iter-k1],b[iter]) + t1;
        iter++;
    }
    for(int i = 0; i<k2 && i<n; i++)
    {
        b[i] += t2;
    }
    iter = k2;
    while(iter < n)
    {
        b[iter] = max(b[iter-k2],b[iter]) + t2;
        iter++;
    }
    for(int i = 0; i<k3 && i<n; i++)
    {
        b[i] += t3;
    }
    iter = k3;
    while(iter < n)
    {
        b[iter] = max(b[iter-k3],b[iter]) + t3;
        iter++;
    }
    lli ans = -1;
    for(int i = 0; i<n; i++)
    {
        ans = max(ans,b[i]-a[i]);
    }
    cout << ans << endl;
}
