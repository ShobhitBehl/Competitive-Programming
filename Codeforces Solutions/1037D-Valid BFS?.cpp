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

struct pls
{
    lli cibil,risk;
    string s;
};

struct comparator
{
  bool operator()(const pls& a,const pls& b) const
  {
      if(a.cibil == b.cibil)
      {
          if(a.risk == b.risk)
          {
              return a.s < b.s;
          }
          return a.risk > b.risk;
      }
      return a.cibil < b.cibil;
  }
};
const int N=300000;
lli b[N], bfs[N], vis[N], g[N], par[N], r[N], s[N], q[N];
vector<lli> a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(50);
    lli n, i, x1, y1, j;
    cin>>n;
    for(i=0;i<n-1;i++){
        cin>>x1>>y1;
        a[x1].pb(y1);
        a[y1].pb(x1);
    }
    for(i=0;i<n;i++){
        cin>>g[i];
        q[g[i]]=i;
    }
    x1=1;
    bfs[x1]=1;
    vis[1]=1;
    par[1]=-1;
    x1=2;
    for(i=0;i<x1;i++){
        y1=bfs[i];
        for(j=0;j<a[y1].size();j++){
            if(vis[a[y1][j]]==0){
                bfs[x1]=a[y1][j];
                vis[bfs[x1]]=vis[y1]+1;
                par[bfs[x1]]=bfs[i];
                x1++;
            }
        }
    }
    for(i=0;i<n;i++){
        r[i]=vis[g[i]];
        if(i>0 && r[i]<r[i-1]){
            cout<<"No";
            return 0;
        }
    }
    x1=-1;
    for(i=0;i<n;i++)
        r[i]=0;
    for(i=0;i<n;i++){
        r[i]=par[g[i]];
        if(i>0 && r[i-1]!=r[i]){
            if(s[q[r[i]]]!=0){
                cout<<"No";
                return 0;
            }
            else{
                if(q[r[i]]<x1){
                    cout<<"No";
                    return 0;
                }
                s[q[r[i]]]=1;
                x1=q[r[i]];
            }
        }
    }
    cout<<"Yes";
    x1=0;
}
