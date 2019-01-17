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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(50);
    lli n,m;
    cin >> n >> m;
    lli a[n][m];
    lli hor[n][m],ver[n][m], diag1[n][m],diag2[n][m];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            char c;
            cin >> c;
            a[i][j] = c - '0';
            hor[i][j] = ver[i][j] = diag1[i][j] = diag2[i][j] = a[i][j];
        }
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(j-1 >= 0)
            {
                hor[i][j] += hor[i][j-1];
            }
            if(i-1 >= 0)
            {
                ver[i][j] += ver[i-1][j];
            }
            if(i-1 >= 0 && j-1 >= 0)
            {
                diag1[i][j] += diag1[i-1][j-1];
            }
            if(i-1 >= 0 && j+1 <= m)
            {
                diag2[i][j] += diag2[i-1][j+1];
            }
        }
    }
    lli ans = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            for(int k = j+1; k<m; k++)
            {
                if(hor[i][k] - hor[i][j] + a[i][j] == 0)
                {
                    lli len = k-j;
                    if(i + len < n)
                    {
                        if(ver[i+len][j] - ver[i][j] + a[i][j] == 0 && diag2[i+len][j] - diag2[i][k] + a[i][k] == 0)
                        {
                            ans++;
                        }
                        if(ver[i+len][k] - ver[i][k] + a[i][k] == 0 && diag1[i+len][k] - diag1[i][j] + a[i][j] == 0)
                        {
                            ans++;
                        }
                    }
                    if(i-len >= 0)
                    {
                        if(ver[i][j] - ver[i-len][j] + a[i-len][j] == 0 && diag1[i][k] - diag1[i-len][j] + a[i-len][j] == 0)
                        {
                            ans++;
                        }
                        if(ver[i][k] - ver[i-len][k] + a[i-len][k] == 0 && diag2[i][j] - diag2[i-len][k] + a[i-len][k] == 0)
                        {
                            ans++;
                        }
                    }
                    if(len%2 == 0)
                    {
                        lli temp = len/2;
                        if(i+temp < n && j+temp < m && diag1[i+temp][j+temp] - diag1[i][j] + a[i][j] == 0 && diag2[i+temp][j+temp] - diag2[i][k] + a[i][k] == 0)
                        {
                            ans++;
                            //tr(i,j,k,i+temp,j+temp);
                        }
                        if(i-temp >= 0 && j + temp < m && diag2[i][j] - diag2[i-temp][j+temp] + a[i-temp][j+temp] == 0 && diag1[i][k] - diag1[i-temp][j+temp] + a[i-temp][j+temp] == 0)
                        {
                            ans++;
                            //tr(i,j,k,i-temp,j+temp);
                        }
                    }
                }
            }
        }
    }
    for(int j = 0; j<m; j++)
    {
        for(int i1 = 0; i1<n; i1++)
        {
            for(int i2 = i1+1; i2<n; i2++)
            {
                if(ver[i2][j] - ver[i1][j] + a[i1][j] == 0)
                {
                    lli len = i2-i1;
                    if(len%2 == 0)
                    {
                        lli temp = len/2;
                        if(i1 + temp < n && j+temp < m && diag1[i1+temp][j+temp] - diag1[i1][j] + a[i1][j] == 0 && diag2[i2][j] - diag2[i1+temp][j+temp] + a[i1+temp][j+temp] == 0)
                        {
                            ans++;
                            //tr(j,i1,i2,i1+temp,j+temp);
                        }
                        if(i1+temp < n && j-temp >= 0 && diag2[i1+temp][j-temp] - diag2[i1][j] + a[i1][j] == 0 && diag1[i2][j] - diag1[i1+temp][j-temp] + a[i1+temp][j-temp] == 0)
                        {
                            ans++;
                            //tr(j,i1,i2,i1+temp,j-temp);
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
