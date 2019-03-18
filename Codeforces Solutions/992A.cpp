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
#define B(i, a, n) for(i=n-1;i>=0;i--)


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
            ans = ans;
        }
        b/=2;
        a*=a;
        a = a;
    }
    return ans;
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
double pDistance(lli x, lli y, lli x1, lli y1, lli x2, lli y2) {

  lli A = x - x1;
  lli B = y - y1;
  lli C = x2 - x1;
  lli D = y2 - y1;

  lli dot = A * C + B * D;
  lli len_sq = C * C + D * D;
  double param = -1;
  if (len_sq != 0) //in case of 0 length line
      param = 1.0 * dot / len_sq;
  else{
      //SO("varada");
      return sqrt(1.0*dist(x, y, x1, y1));
  }
  double xx, yy;

  if (param < 0) {
    xx = x1;
    yy = y1;
  }
  else if (param > 1) {
    xx = x2;
    yy = y2;
  }
  else {
    xx = x1 + param * C;
    yy = y1 + param * D;
  }

  double dx = x - xx;
  double dy = y - yy;
  return sqrt(1.0 * dx * dx + 1.0 * dy * dy);
}

int main(){
    FASTER;
    lli n, i, x=0;
    SI(n);
    lli a[n];
    F(i, 0, n)
        SI(a[i]);
    sort(a, a+n);
    F(i, 0, n)
        if(a[i]!=0)
            break;
    if(i>=n){
        SO(0);
        return 0;
    }
    x++;
    i++;
    while(i<n){
        if(a[i]!=a[i-1] && a[i]!=0)
            x++;
        i++;
    }
    SO(x);
}