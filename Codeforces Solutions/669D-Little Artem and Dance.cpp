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
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n,q;
    cin >> n >> q;
    lli one = 0,two = 1;
    for(int i = 0; i<q; i++)
    {
        lli type,shift;
        cin >> type;
        if(type == 1)
        {
            cin >> shift;
            one = ((one+shift)%n + n)%n;
            two = ((two+shift)%n + n)%n;
        }
        else
        {
            if(one%2 == 0)
            {
                shift = 1;
                one = ((one+shift)%n + n)%n;
                shift = -1;
                two = ((two+shift)%n + n)%n;
            }
            else
            {
                shift = -1;
                one = ((one+shift)%n + n)%n;
                shift = 1;
                two = ((two+shift)%n + n)%n;
            }
        }
    }
    vector <lli> a(n,-1);
    lli iter = one,put = 1;
    while(a[iter] == -1)
    {
        a[iter] = put;
        put += 2;
        iter = (iter+2)%n;
    }
    iter = two,put = 2;
    while(a[iter] == -1)
    {
        a[iter] = put;
        put += 2;
        iter = (iter+2)%n;
    }
    for(int i = 0; i<n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
