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
        }
        a*=a;
        p/=2;
    }
    return ans;
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
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    if(n == 1)
    {
        cout << -1 << endl;
        return 0;
    }
    sort(a,a+n);
    lli b[n];
    for(int i = 1; i<n; i++)
    {
        b[i] = a[i] - a[i-1];
    }
    sort(b+1,b+n);
    if(b[1] == b[n-1])
    {
        if(b[1] == 0)
        {
            cout << 1 << endl;
            cout << a[0] << endl;
            return 0;
        }
        else
        {
            if(n == 2)
            {
                if((a[1]-a[0])%2 == 0)
                {
                    cout << 3 << endl;
                    cout << a[0] - b[1] << " " << (a[0]+a[1])/2 << " " << a[n-1] + b[1] << endl;
                    return 0;
                }
            }
            cout << 2 << endl;
            cout << a[0] - b[1] << " " << a[n-1] + b[1] << endl;
            return 0;
        }
    }
    else if(b[1] == b[n-2] && b[n-1] == 2*b[1])
    {
        for(int i = 1; i<n; i++)
        {
            if(a[i] - a[i-1] == b[n-1])
            {
                cout << 1 << endl;
                cout << a[i-1] + b[1] << endl;
                return 0;
            }
        }
    }
    else
    {
        cout << 0 << endl;
        return 0;
    }
}
