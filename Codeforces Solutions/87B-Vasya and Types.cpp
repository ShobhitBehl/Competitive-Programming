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
    lli n;
    cin >> n;
    m["void"] = 0;
    for(int i = 0; i<n; i++)
    {
        string type;
        cin >> type;
        if(type == "typedef")
        {
            string s1,s2;
            cin >> s1 >> s2;
            m[s2] = value(s1);
        }
        else
        {
            string s;
            cin >> s;
            lli check = value(s);
            if(check == -1)
            {
                cout << "errtype\n";
            }
            else
            {
                cout << "void";
                for(int j = 0; j<check; j++)
                {
                    cout << "*";
                }
                cout << endl;
            }
        }
    }
}
