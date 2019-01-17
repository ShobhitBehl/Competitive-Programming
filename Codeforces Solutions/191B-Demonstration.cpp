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

lli power(lli a, lli b)
{
    lli ans = 1;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            ans *= a;
        }
        a *= a;
        b/=2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n,k,b,temp;
    cin >> n >> k >> b;
    k--;
    pair <lli,lli> a[n];
    for(int i = 0; i<n; i++)
    {
        if(i == n)
        {
            cin >> temp;
        }
        else
        {
            cin >> a[i].x;
            a[i].y = i;
        }
    }
    sort(a,a+n-1);
    lli sum = 0;
    for(int i = 1; i<=k; i++)
    {
        sum += a[n-i-1].x;
    }
    lli min = n;
    for(int i = 0; i<n-1; i++)
    {
        //cout << "value " << a[i].x << " index " << a[i].y << " ";
        if(i >= n-k-1)
        {
            sum -= a[i].x;
            sum += a[i-1].x;
        }
        //cout << " b-a[i].x " << b-a[i].x << " sum " << sum << endl;
        if(sum > b-a[i].x)
        {
            if(a[i].y + 1 < min)
            {
                min = a[i].y+1;
            }
        }
    }
    cout << min << endl;
}
