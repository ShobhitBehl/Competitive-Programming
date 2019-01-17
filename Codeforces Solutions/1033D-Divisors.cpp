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
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

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
            ans = ans%mod;
        }
        b/=2;
        a*=a;
        a = a%mod;
    }
    return ans%mod;
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

lli dist(pll a, pll b)
{
    return 0;
    //return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y - a.y);
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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(50);
    lli n;
    cin >> n;
    map <lli,lli> m;
    lli a[n];
    lli flag[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
        flag[i] = 0;
    }
    for(int i = 0; i<n; i++)
    {
        lli sq,b,c;
        sq = llround(sqrt(a[i]));
        b = llround(cbrt(a[i]));
        c = llround(sqrt(llround(sqrt(a[i]))));
        if(c*c*c*c == a[i])
        {
            m[c] += 4;
            flag[i] = 1;
        }
        else if(b*b*b == a[i])
        {
            m[b] += 3;
            flag[i] = 1;
        }
        else if(sq*sq == a[i])
        {
            m[sq] += 2;
            flag[i] = 1;
        }
    }
    lli ans = 1;
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(a[i] == a[j])
            {
                continue;
            }
            lli p = gcd(a[i],a[j]);
            if(p != 1)
            {
                if(flag[i] == 0)
                {
                    m[p]++;
                    m[a[i]/p]++;
                    flag[i] = 1;
                }
                if(flag[j] == 0)
                {
                    m[p]++;
                    m[a[j]/p]++;
                    flag[j] = 1;
                }
            }
        }
    }
    map <lli,lli> m1;
    for(int i = 0; i<n; i++)
    {
        if(flag[i] == 0)
        {
            m1[a[i]]++;
        }
    }
    for(auto e : m1)
    {
        //tr(e.x);
        ans *= (e.y+1);
        ans %= 998244353;
        ans *= (e.y+1);
        ans %= 998244353;
    }
    for(auto e : m)
    {
        //tr(e.x);
        ans *= (e.y + 1);
        ans %= 998244353;
    }
    cout << ans << endl;
    cout.flush();
}
