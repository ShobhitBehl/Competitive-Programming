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
    FASTER;
    lli n, i, j, x, y, p=1, ind=1, r;
    SI(n);
    lli a[n], min=0, max=0;
    pair<lli, lli> b[n+1];
    b[0].fi=0;
    b[0].se=0;
    F(i, 0, n){
        SI(a[i]);
        b[i+1].fi=b[i].fi+a[i];
        if(i%2!=0){
            b[i+1].se=b[i].se-a[i];
        }
        else
            b[i+1].se=b[i].se+a[i];
        if(b[i+1].se>max)
            max=b[i+1].se;
        if(b[i+1].se<min)
            min=b[i+1].se;
    }
    //TO(b[n].fi, max, min);
    //F(i, 0, n+1)
    //    DO(b[i].fi, b[i].se);
    x=b[n].fi;
    y=max-min+1;
    char c[y][x];
    r=max-b[0].se;
    F(i, 0, x){
        //cout<<r<<" ";
        if(p==1){
            c[r][i]='/';
            F(j, 0, y){
                if(j!=r){
                    c[j][i]=' ';
                }
            }
            if(r==max+1-b[ind].se){
                /*i++;
                r--;
                c[r][i]='/';
                F(j, 0, y){
                    if(j!=r){
                        c[j][i]=' ';
                    }
                }*/
                //i--;
                //r++;
                p*=-1;
                ind++;
                continue;
            }
            r--;
        }
        else{
            c[r][i]=92;
            F(j, 0, y){
                if(j!=r){
                    c[j][i]=' ';
                }
            }
            
            if(r==max-b[ind].se){
                /*i++;
                r++;
                c[r][i]=92;
                F(j, 0, y){
                    if(j!=r){
                        c[j][i]=' ';
                    }
                }*/
                //i--;
                //r--;
                p*=-1;
                ind++;
                continue;
            }
            r++;
        }
    }
    //cout<<endl;
    F(j, 1, y){
        //cout<<j<<" : ";
        F(i, 0, x){
            cout<<c[j][i];
        }
        cout<<endl;
    }
}