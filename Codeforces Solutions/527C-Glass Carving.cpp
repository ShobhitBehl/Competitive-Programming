#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
typedef set<lli> sl;
typedef map<int,int> mii;
typedef set<int> si;
#define x first
#define y second
#define mp make_pair
#define pb push_back
const lli mod = 1e9 + 7;

lli power(lli a, lli p)
{
    lli ans = 1;
    while(p > 0)
    {
        if(p%2)
        {
            ans *= a;
            ans %= mod;
        }
        a*=a;
        a%=mod;
        p/=2;
    }
    return ans%mod;
}

vector <lli> getbinary(lli x)
{
    vector <lli> bin(101,0);
    int iter = 0;
    while(x > 0)
    {
        bin[iter] = x%2;
        iter++;
        x/=2;
    }
    return bin;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli w,h,n;
    cin >> w >> h >> n;
    set <lli> a1,a2;
    multiset <lli> q1,q2;
    set <lli> ::iterator it1,it2;
    a1.insert(h),a1.insert(0);
    a2.insert(w),a2.insert(0);
    q1.insert(h),q2.insert(w);
    for(int i = 0; i<n; i++)
    {
        char type;
        lli dist;
        cin >> type >> dist;
        if(type == 'H')
        {
            it1 = a1.lower_bound(dist);
            it2 = --it1;
            ++it1;
            q1.erase(q1.find(*it1 - *it2));
            a1.insert(dist);
            q1.insert(dist - *it2);
            q1.insert(*it1 - dist);
        }
        else
        {
            it1 = a2.lower_bound(dist);
            it2 = --it1;
            ++it1;
            q2.erase(q2.find(*it1 - *it2));
            a2.insert(dist);
            q2.insert(dist - *it2);
            q2.insert(*it1 - dist);
        }
        cout << (*q1.rbegin()) * (*q2.rbegin()) << endl;
    }
}
