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
#define f first
#define s second
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

lli dist(pll a, pll b)
{
    return (b.f-a.f)*(b.f-a.f) + (b.s-a.s)*(b.s - a.s);
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

char a[1305][1305];

void initialise()
{
    for(int i = 0; i<1001; i++)
    {
        for(int j = 0; j<1001; j++)
        {
            a[i][j] = 'N';
        }
    }
    return;
}

void solve()
{
    initialise();
    lli k;
    cin >> k;
    lli p;
    lli num = 3;
    lli maxp;
    p = 1;
    for(int i = 0; i<=35; i++)
    {
        if(p <= k)
        {
            maxp = i;
        }
        else
        {
            break;
        }
        p*=2;
    }
    p = power(2,maxp);
    lli prevl,prevr;
    for(lli i = maxp; i>=0; i--)
    {
        //tr(p,k);
        if(p <= k)
        {
            //tr(p);
            if(i == maxp)
            {
                prevl = 1, prevr = 1;
                for(int j = 0; j<i; j++)
                {
                    a[prevl][num] = 'Y';
                    a[prevr][num] = 'Y';
                    a[prevl][num+1] = 'Y';
                    a[prevr][num+1] = 'Y';
                    a[num][prevl] = 'Y';
                    a[num][prevr] = 'Y';
                    a[num+1][prevl] = 'Y';
                    a[num+1][prevr] = 'Y';
                    prevl = num;
                    prevr = num+1;
                    num += 2;
                }
            }
            else
            {
                lli temp = i;
                prevl = 2*i + 1, prevr = 2*i + 2;
                if(i == 0)
                {
                    prevl = 1,prevr = 1;
                }
                while(temp < maxp)
                {
                    a[prevl][num] = 'Y';
                    a[prevr][num] = 'Y';
                    a[num][prevl] = 'Y';
                    a[num][prevr] = 'Y';
                    prevl = num;
                    prevr = num;
                    temp++;
                    num++;
                }
            }
            a[prevl][2] = 'Y';
            a[prevr][2] = 'Y';
            a[2][prevl] = 'Y';
            a[2][prevr] = 'Y';
            k-=p;
        }
        p/=2;
    }
    cout << num << endl;
    for(int i = 1; i<=num; i++)
    {
        for(int j = 1; j<=num; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
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
