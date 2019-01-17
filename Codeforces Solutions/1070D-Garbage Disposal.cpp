#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

/*
#define cin fin
#define cout fout

ifstream fin("robbers.txt");
ofstream fout("robbers.txt");
*/

#define SI(x) cin>>x
#define DI(x, y) cin>>x>>y
#define TI(x, y, z) cin>>x>>y>>z
#define FI(w, x, y, z) cin>>w>>x>>y>>z

#define SO(x) cout<<x<<endl
#define DO(x, y) cout<<x<<" "<<y<<endl
#define TO(x, y, z) cout<<x<<" "<<y<<" "<<z<<endl
#define FO(w, x, y, z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl

#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define pr pair<int,int>
#define V(x) vector<x>
#define pb(x) push_back(x)
#define SORT(ls) sort(ls.begin(), ls.end())
#define DESC(ls) sort(ls.rbegin(), ls.rend()); 
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second

#define F(i, a, n) for(i=a;i<n;i++)
#define B(i, a, n) for(i=n-1;i>=a;i--)


#define mod 1000000007
#define pi 3.141592653589793238

/*template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<p.f<<" "<<p.s;return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}
*/
//GCD
lli gcd(lli a, lli b){
    if(b < a)    {
        lli temp = a;
        a = b;
        b = temp;
    }
    if(a == 0){
        return b;
    }
    return gcd(b%a,a);
}

//LCM
lli lcm(lli a, lli b){
    return (a*b/gcd(a,b));
}

//Factorial
lli fact(lli x){
    lli ans = 1;
    if(x == 0){
        return 1;
    }
    while(x > 0){
        ans = (ans*x)%mod;
        x--;
    }
    return ans%mod;
}

//power a^b
lli power(lli a, lli b){
    lli ans = 1;
    while(b > 0){
        if(b%2 == 1){
            ans *= a;
            ans = (ans%mod);
        }
        b/=2;
        a*=a;
        a=a%mod;
    }
    return (ans%mod);
}

//binary of a number
vector <lli> getbinary(int x){
    vector <lli> bin(10,0);
    lli iter = 0;
    while(x > 0){
        if(x%2 == 1){
            bin[iter] = 1;
        }
        else{
            bin[iter] = 0;
        }
        iter++;
        x/=2;
    }
    return bin;
}

lli dist(lli x1, lli y1, lli x2, lli y2){
    return (1.0*(x1-x2)*(x1-x2) + 1.0*(y1-y2)*(y1-y2));
}
int main(){
    FASTER;
    lli n, k, i, x=0, y=0;
    DI(n, k);
    lli a[n];
    F(i, 0, n){
        SI(a[i]);
        y+=(x+a[i])/k;
        if((x+a[i])%k>a[i]){
            y++;
            x=0;
        }
        else{
            x=(x+a[i])%k;
        }
    }
    if(x!=0)
        y++;
    SO(y);
}