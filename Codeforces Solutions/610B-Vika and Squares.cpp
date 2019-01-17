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

lli power(lli a, lli p)
{
    lli ans = 1;
    while(p > 0)
    {
        if(p%2)
        {
            ans *= a;
            ans %= 1000000007;
        }
        a*=a;
        a%=1000000007;
        p/=2;
    }
    return ans%1000000007;
}

vector <lli> getbinary(lli x)
{
    vector <lli> bin(2000,0);
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
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n;
    cin >> n;
    lli a[n];
    lli mini = 1e18;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
        if(a[i] < mini)
        {
            mini = a[i];
        }
    }
    vector <lli> pos;
    for(int i = 0; i<n; i++)
    {
        if(a[i] == mini)
        {
            pos.pb(i);
        }
    }
    if(pos.size() == 1)
    {
        cout << ((mini+1)*n) - 1 << endl;
    }
    else
    {
        lli temp = pos.size();
        lli maxadd = -1,prevpos = pos[temp-1];
        for(int i = 0; i<temp; i++)
        {
            if(i == 0)
            {
                maxadd = max(maxadd,pos[i]+n-prevpos-1);
            }
            else
            {
                maxadd = max(maxadd,pos[i]-prevpos-1);
            }
            prevpos = pos[i];
        }
        cout << (mini*n) + maxadd << endl;
    }
}
