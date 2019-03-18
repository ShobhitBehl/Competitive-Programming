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
	ll n;
	cin >> n;
	string s;
	cin >> s;
	set<char> left;
	for(char i = 'a' ; i <= 'z' ; i++)
		left.insert(i);
	vll starloc;
	for(ll i = 0 ; i < n ; i++){
		if(s[i] != '*')
			left.erase(s[i]);
		else
			starloc.pb(i);
	}
	vector<string> sd;
	ll m;
	cin >> m;
	// for(auto &e : left)
	// 	cout << e << ' ';
	// cout << endl;
	for(ll i = 0 ; i < m ; i++){
		string temp;
		cin >> temp;
		bool flag = 1;
		for(ll j = 0 ; j < n ; j++){
			if(s[j] != '*'){
				if(s[j] != temp[j]){
					// cout << 1 << endl;
					flag = 0;
					break;
				}
			}
			else{
				if(left.find(temp[j]) == left.end()){
					// cout << 2 << endl;
					// tr(j,temp[j]);
					flag = 0;
					break;
				}
			}
		}
		if(flag){
			// cout << "hi\n";
			sd.push_back(temp);
			// tr(temp);
		}

	}
	ll ans = 0;
	for(auto &i : left){
		ll count = 0;
		for(auto &e : sd){
			bool flag = 0;
			for(auto &loc : starloc){
				if(e[loc] == i){
					flag = 1;
					break;
				}
			}
			count+=flag;

		}
		if(count == sd.size())
			ans++;
	}
	cout << ans << endl;

	return 0;
}