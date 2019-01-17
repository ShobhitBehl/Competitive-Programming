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

lli getcnt(string s)
{
    lli ret = 0;
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i] == ')')
        {
            ret--;
        }
        else
        {
            ret++;
        }
        if(ret < 0)
        {
            break;
        }
    }
    return ret;
}

lli cnt[300002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for(int i = 0; i<300002; i++)
    {
        cnt[i] = 0;
    }
    lli n;
    cin >> n;
    string s[n];
    for(int i = 0; i<n; i++)
    {
        cin >> s[i];
        lli count = getcnt(s[i]);
        if(count >= 0)
        {
            cnt[count]++;
        }
    }
    lli ans = 0;
    for(int i = 0; i<n; i++)
    {
        reverse(s[i].begin(),s[i].end());
        for(int j = 0; j<s[i].size(); j++)
        {
            if(s[i][j] == '(')
            {
                s[i][j] = ')';
            }
            else
            {
                s[i][j] = '(';
            }
        }
        lli count = getcnt(s[i]);
        if(count >= 0)
        {
            ans += cnt[count];
        }
    }
    cout << ans << endl;
}
