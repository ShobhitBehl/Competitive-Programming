#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
typedef set<lli> sl;
//typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;
#define x first
#define y second
#define mp make_pair
#define pb push_back
typedef vector<double> vd;
typedef pair<int,double> pid;
typedef vector< pid > vdd;
#define INF 0x3f3f3f3f

bool check(double mid,lli n, lli l, lli v1, lli v2, lli k, lli groups)
{
    if(v1*mid >= l)
    {
        return 1;
    }
    double t = 0;
    double q = (l - v1*mid)/(v2-v1);
    double z = q*(v2-v1)/(v1+v2);
    for(int i = 0; i<groups; i++)
    {
        t += q;
        if(t >mid)
        {
            return 0;
        }
        t += z;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n,l,v1,v2,k;
    cin >> n >> l >> v1 >> v2 >> k;
    lli groups = ((n-1)/k) + 1;
    double left = 0, right = 1e16;
    double mid;
    lli iter = 100;
    while(iter)
    {
        mid = (left+right)*0.5;
        if(check(mid,n,l,v1,v2,k,groups) == 1)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
        iter--;
    }
    cout << setprecision(20) << mid << endl;
}
