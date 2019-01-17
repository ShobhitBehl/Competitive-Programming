#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

/*
#define cin fin
#define cout fout

ifstream fin("input.txt");
ofstream fout("output.txt");
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
int main(){
    lli t;
    SI(t);
    while(t--){
        double d, x;
        SI(d);
        if(d==0){
            TO("Y", 0, 0);
            continue;
        }
        else if(d<4){
            SO("N");
            continue;
        }
        x=(d+sqrt(d*d-4*d))/2;
        printf("Y %0.20f %0.20f\n", x, d/x);
    }
}
