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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve()
{
	lli n;
	cin >> n;
	lli ans = 1e10;
	lli left = 0, right = 1e9;
	vector <lli> v;
	set <lli> s;
	while(left <= right)
	{
		lli mid = (left+right)/2;
		cout << "> " << mid << endl;
		cout.flush();
		lli r;
		cin >> r;
		if(r == 0)
		{
			right = mid-1;
			ans = min(ans,mid);
		}
		else
		{
			left = mid+1;
		}
	}
	for(int iter = 0; iter<min(n,30ll); iter++)
	{
		lli i;
		while(true)
		{
			i = getRand(1,n);
			if(s.find(i) == s.end())
			{
				s.insert(i);
				break;
			}
		}
		cout << "? " << i << endl;
		cout.flush();
		lli r;
		cin >> r;
		v.pb(r);
	}
	v.pb(ans);
	sort(v.begin(),v.end());
	lli diff = v[1]-v[0];
	for(int i=2; i<v.size(); i++)
	{
		diff = gcd(diff,v[i]-v[i-1]);
	}
	cout << "! " << ans - (n-1)*diff << " " << diff << endl;
	cout.flush();
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
