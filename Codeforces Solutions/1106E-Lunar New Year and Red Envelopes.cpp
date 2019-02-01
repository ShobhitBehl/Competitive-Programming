#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

//#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
typedef set<lli> sl;
typedef map<int,int> mii;
typedef set<int> si;
typedef pair<double,double> pdd;
typedef map<double,lli> mdl;
typedef set<double> sd;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define fin cin
#define fout cout
const lli mod = 1e9 + 7;

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.f<<", "<<p.s<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
lli l=v.size();for(lli i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}


lli gcd(lli a, lli b)
{
    if(b < a)
    {
        swap(a,b);
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

lli primefactorise(int n)
{
    if(n == 1)
    {
        return 1;
    }
    lli ans = n;
    while (n%2 == 0)
    {
        n = n/2;
        if(n != 1)
        {
            ans += n;
        }
    }

    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            n = n/i;
            if(n != 1)
            {
                ans += n;
            }
        }
    }
    ans += 1;
    return ans;
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

vector<lli> getbinary(lli x, lli size)
{
    vector <lli> bin(size,0);
    lli iter = 0;
    while(x > 0)
    {
        if(x%2 == 0)
        {
            bin[iter] = 0;
        }
        else
        {
            bin[iter] = 1;
        }
        x/=2;
        iter++;
    }
    return bin;
}

vector <lli> getprimes()
{
    vector <lli> primes(1000000,0);
    vector <lli> ans;
    for(int i = 2; i<1000000; i++)
    {
        if(primes[i] == 0)
        {
            for(int j = 2*i; j<1000000; j+=i)
            {
                primes[j] = 1;
            }
            ans.pb(i);
        }
    }
    return ans;
}

//-----------------------TRIE-START---------------------------------------------
const lli size = 10;
struct tnode
{
    tnode *child[size];
    lli isword;
};

tnode* makenode()
{
    tnode *temp = new tnode;
    for(int i = 0; i<size; i++)
    {
        temp->child[i] = NULL;
    }
    temp->isword = 0;
    return temp;
}

void insert(tnode *root, string s)
{
    tnode *temp = root;
    for(int i = 0; i<s.size(); i++)
    {
        lli key = s[i]-'a';
        if(temp->child[key] == NULL)
        {
            temp->child[key] = makenode();
        }
        temp = temp->child[key];
    }
    temp->isword = 1;
}

lli search(tnode *root,string s)
{
    tnode *temp = root;
    for(int i = 0; i<s.size(); i++)
    {
        lli key = s[i]-'a';
        if(temp->child[key] == NULL)
        {
            return 0;
        }
        temp = temp->child[key];
    }
    return temp->isword;
}

//------------------------TRIE-END----------------------------------------------

struct env
{
    lli s,t,d,w;
    bool operator <(const env &a)
    {
        if(w == a.w)
        {
            return d > a.d;
        }
        return w > a.w;
    }
};



void solve()
{
    lli n,m,k;
    cin >> n >> m >> k;
    env a[k];
    for(int i = 0; i<k; i++)
    {
        cin >> a[i].s >> a[i].t >> a[i].d >> a[i].w;
    }
    sort(a,a+k);
    set <lli> se;
    for(lli i = 1; i<=n; i++)
    {
        se.insert(i);
    }
    map <lli,lli> ma;
    for(lli i = 0; i<k; i++)
    {
        set <lli> :: iterator it1,it2;
        it1 = se.lower_bound(a[i].s);
        it2 = se.upper_bound(a[i].t);
        vector <lli> v;
        for(auto j = it1; j!=it2; j++)
        {
            ma[(*j)] = i+1;
            v.pb(*j);
        }
        for(int blah = 0; blah<(lli)v.size(); blah++)
        {
            se.erase(v[blah]);
        }
    }
    lli dp[n+1][m+1];
    for(int i = 1; i<=m; i++)
    {
        dp[n][i] = 0;
    }
    if(ma[n] == 0)
    {
        dp[n][0] = 0;
    }
    else
    {
        dp[n][0] = a[ma[n]-1].w;
    }
    for(lli i = n-1; i>=1; i--)
    {
        for(int j = 0; j<=m; j++)
        {
            lli d;
            lli w;
            if(ma[i] == 0)
            {
                d = i;
                w = 0;
            }
            else
            {
                env e = a[ma[i]-1];
                d = e.d;
                w = e.w;
            }
            if(d+1 > n)
            {
                if(j == 0)
                {
                    dp[i][j] = w;
                }
                else
                {
                    dp[i][j] = min(w,dp[i+1][j-1]);
                }
            }
            else
            {
                if(j == 0)
                {
                    dp[i][j] = w + dp[d+1][j];
                }
                else
                {
                    dp[i][j] = min(w+dp[d+1][j],dp[i+1][j-1]);
                }
            }
        }
    }
    cout << dp[1][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(50);
    // lli t;
    // cin >> t;
    // while(t--)
    // {
    //     solve();
    // }
    solve();
}
