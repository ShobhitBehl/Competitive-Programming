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
    vector <lli> bin(2000,0);
    int iter = 0;
    while(x > 0)
    {
        bin[iter] = x%2;
        iter++;
        x/=2;
    }
    return bin;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    lli n = s.size();
    map <char,lli> m;
    for(int i = 0; i<n; i++)
    {
        m[s[i]]++;
    }
    vector <lli> done(n,0);
    for(int i =2 ; i<=n; i++)
    {
        if(!done[i-1])
        {
            lli req = 0;
            char c = '!';
            for(int j = i-1; j<n; j+=i)
            {
                if(done[j] == 0)
                {
                    req++;
                }
                else
                {
                    c = s[j];
                }
            }
            if(c == '!')
            {
                lli max = -1;
                for(int j = 0; j<26; j++)
                {
                    if(m[j+'a'] >= req && m[j+'a'] > max)
                    {
                        c = 'a'+j;
                        max = m[j+'a'];
                    }
                }
                if(c == '!')
                {
                    cout << "NO\n";
                    return 0;
                }
            }
            else
            {
                if(m[c] < req)
                {
                    cout << "NO\n";
                    return 0;
                }
            }
            m[c] -= req;
            for(int j = i-1; j<n; j+=i)
            {
                s[j] = c;
                done[j] = 1;
            }
        }
    }
    for(int i = 0; i<2; i++)
    {
        for(int j = 0; j<26; j++)
        {
            if(m[j+'a'] != 0)
            {
                m[j+'a']--;
                s[i] = j+'a';
            }
        }
    }
    cout << "YES\n";
    cout << s << endl;
}
