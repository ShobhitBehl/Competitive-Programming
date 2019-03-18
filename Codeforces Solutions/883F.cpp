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
string reduce(string s){
	while(1){
		ll si = s.size() ; 
		string k = "";
		bool flag = 0;
		for(ll i = 0 ; i < si-1 ; i++){
			string temp  = "";
			temp+=s[i];
			temp+=s[i+1];
			if(temp == "kh"){
				flag = 1;
				for(ll j = 0 ; j < si ; j++){
					if(j == i)
						k+='h';
					else if(j != i+1)
						k+=s[j];
				}
				s = k;
				break;
			}
			if(temp == "oo"){
				flag = 1;
				for(ll j = 0 ; j < si ; j++){
					if(j == i)
						k+='u';
					else if(j != i+1)
						k+=s[j];
				}
				s = k;
				break;
			}
			if(temp == "ou"){
				flag = 1;
				for(ll j = 0 ; j < si ; j++){
					if(j == i)
						k+="uo";
					else if(j != i+1)
						k+=s[j];
				}
				s = k;
				break;
			}
		}
		if(flag == 0)
			break;
	}
	return s;
}
int main(){
	ll n;
	cin >> n;
	set<string> s;
	for(ll i = 0 ; i < n  ; i++){
		string temp;
		cin >> temp;
		temp = reduce(temp);
		// tr(temp);
		s.insert(temp);
	}
	cout << s.size() << endl;
	return 0;
}