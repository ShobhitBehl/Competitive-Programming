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

struct bun
{
    lli a,b,c,d;
};

bool comparator(bun &a,bun &b)
{
    return b.c*a.d > a.c*b.d;
}

const int MAX=1005, MAXM=13;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n;
    string s;
    cin >> n;
    map <string,int> m;
    for(int i = 0; i<n; i++)
    {
        cin >> s;
        string temp;
        for(int j = 0; j<s.size(); j++)
        {
            temp += tolower(s[j]);
        }
        m[temp] = 1;
    }
    cin >> s;
    char c;
    cin >> c;
    n = s.size();
    vector<int> rep(n,0);
    for(int l = 0; l<n; l++)
    {
        string temp;
        int maxr = -1;
        for(int r = l; r<n; r++)
        {
            temp += tolower(s[r]);
            if(m[temp] == 1)
            {
                maxr = r;
            }
        }
        for(int r = l; r<=maxr; r++)
        {
            rep[r] = 1;
        }
    }
    for(int i = 0; i<n; i++)
    {
        if(rep[i] == 1)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
            {
                if(s[i] != toupper(c))
                {
                    s[i] = toupper(c);
                }
                else
                {
                    if(s[i]!='A')
                    {
                        s[i] = 'A';
                    }
                    else
                    {
                        s[i] = 'B';
                    }
                }
            }
            else if(s[i] >= 'a' && s[i] <= 'z')
            {
                if(s[i] != tolower(c))
                {
                    s[i] = tolower(c);
                }
                else
                {
                    if(s[i]!='a')
                    {
                        s[i] = 'a';
                    }
                    else
                    {
                        s[i] = 'b';
                    }
                }
            }
        }
    }
    cout << s << endl;
}
