#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define f first
#define s second
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sdl(x) scanf("%lld",&x)
#define sdl2(x,y) scanf("%lld%lld",&x,&y)
#define sdl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define pb(x) push_back(x)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define Forp(i,s,e) for (ll i = s; i <= e; i++)
#define Forn(i,s,e) for (ll i = s; i >= e; i--)
#define modfix(a, mod) ((((a) % (mod)) + (mod)) % (mod))
#define mod_sum(a, b, mod) modfix(((a) + (b)), (mod))
#define mod_sub(a, b, mod) modfix(((a) - (b)), (mod))
#define mod_mul(a, b, mod) modfix(((ll)(a) * (ll)(b)), (mod))

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<p.f<<" "<<p.s;return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

int main(){_
	ll a,b,c;
	cin >> a >> b >> c;
	ll count = 0;
	while(1){
		ll t;
		bool flag = 0;
		if(a+b <= c){
			flag = 1;
			t = c+1 - (a+b);
			count+=t;
			if(a < b){
				a+=(min(t,b-a));
				t-=(min(t,b-a));
				if(t%2){
					a++;
					a+=t/2;
					b+=t/2;
				}
				else{
					a+=t/2;
					b+=t/2;
				}
			}
			else{
				b+=(min(t,a-b));
				t-=(min(t,a-b));
				if(t%2){
					a++;
					a+=t/2;
					b+=t/2;
				}
				else{
					a+=t/2;
					b+=t/2;
				}
			}
		}
		if(b+c <= a){
			flag = 1;
			t = a+1 - (b+c);
			count+=t;
			if(c < b){
				c+=(min(t,b-c));
				t-=(min(t,b-c));
				if(t%2){
					c++;
					c+=t/2;
					b+=t/2;
				}
				else{
					c+=t/2;
					b+=t/2;
				}
			}
			else{
				b+=(min(t,c-b));
				t-=(min(t,c-b));
				if(t%2){
					c++;
					c+=t/2;
					b+=t/2;
				}
				else{
					c+=t/2;
					b+=t/2;
				}
			}
		}
		if(a+c <= b){
			flag = 1;
			t = b+1 - (a+c);
			count+=t;
			if(c < a){
				c+=(min(t,a-c));
				t-=(min(t,a-c));
				if(t%2){
					c++;
					c+=t/2;
					a+=t/2;
				}
				else{
					c+=t/2;
					a+=t/2;
				}
			}
			else{
				a+=(min(t,c-a));
				t-=(min(t,c-a));
				if(t%2){
					c++;
					c+=t/2;
					a+=t/2;
				}
				else{
					c+=t/2;
					a+=t/2;
				}
			}
		}
		if(flag == 0)
			break;

	}
	cout << count << endl;
	return 0;
}