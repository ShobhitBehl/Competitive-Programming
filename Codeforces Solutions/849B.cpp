#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
typedef set<lli> sl;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;
#define x first
#define y second
#define mp make_pair
#define pb push_back

lli M = 1000000007;

lli gcd(lli a, lli b)
{
    if(b < a)
    {
        lli temp = a;
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

double distsqrd(double x1, double y1, double x2, double y2)
{
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

lli fact(lli x)
{
    lli ans = 1;
    if(x == 0)
    {
        return 1;
    }
    while(x > 0)
    {
        ans = (ans*x)%1000000007;
        x--;
    }
    return ans%1000000007;
}

lli power(lli a,lli b, lli m)
{
    lli ans = 1;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            ans *= a;
            ans = ans%m;
        }
        b/=2;
        a*=a;
        a = a%m;
    }
    return ans%m;
}

vector <int> getbinary(int x)
{
    vector <int> bin(10,0);
    int iter = 0;
    while(x > 0)
    {
        if(x%2 == 1)
        {
            bin[iter] = 1;
        }
        else
        {
            bin[iter] = 0;
        }
        iter++;
        x/=2;
    }
    return bin;
}

int getnum(vector <int> bin)
{
    int t = 1;
    int n = bin.size();
    int ret = 0;
    for(int i = 0; i<n; i++)
    {
        ret += t*bin[i];
        t*=2;
    }
    return ret;
}

long long big_multiply(long long a, long long b, long long m){
  a %= m;
  b %= m;
  long long res = 0;
  while(b > 0){
    if(b & 1) res = (res + a) % m;
    a = (a + a) % m;
    b >>= 1;
  }
  return res;
}


const int N = 1010;


int n, h[N];

bool check(double k1) {
	int ans = 1, sta = -1, can = 0;
	for(int i = 2; i <= n; ++i) {
		if(h[i] - h[1] == k1 * (i - 1)) continue;
		can = 1;
		if(sta < 0) sta = i;
		else if(h[i] - h[sta] != k1 * (i - sta)) {
			ans = 0;
			break;
		}
	}
	if(can && ans) {
		return 1;
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", h + i);
	double k1 = h[2] - h[1], k2 = (h[3] - h[1]) / 2.0, k3 = h[3] - h[2];
	if(check(k1) || check(k2) || check(k3)) puts("Yes");
		else puts("No");
	return 0;
}
