#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define pi 3.141592653589793238
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back

lli min(lli a, lli b, lli c, lli d)
{
    lli arr[4] = {a,b,c,d};
    sort(arr,arr+4);
    return arr[0];
}

lli max(lli a, lli b, lli c, lli d)
{
    lli arr[4] = {a,b,c,d};
    sort(arr,arr+4);
    return arr[3];
}

lli gcd(lli a, lli b)
{
    if(b < a)
    {
        int temp = a;
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

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
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

lli power(lli a,lli b)
{
    lli ans = 1;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            ans *= a;
            ans = ans%1000000007;
        }
        b/=2;
        a*=a;
        a = a%1000000007;
    }
    return ans%1000000007;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n;
    cin >> n;
    string s1,s2;
    string a[n],b[n];
    for(int i = 0; i<n; i++)
    {
        cin >> s1 >> s2;
        a[i] = s1.substr(0,3);
        b[i] = s1.substr(0,2) + s2[0];
    }
    map <string,int> insol;
    vector <int> ans(n,0);
    string out[n];
    for(int i = 0 ;i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(a[i][0] == a[j][0] && a[i][1] == a[j][1] && a[i][2] == a[j][2])
            {
                insol[a[i]] = 1;
                insol[b[i]] = 1;
                ans[i] = 2;
            }
        }
    }
    int flag = 1;
    while(flag)
    {
        flag = 0;
        for(int i = 0; i<n; i++)
        {
            if(ans[i])
            {
                continue;
            }
            if(insol[a[i]])
            {
                ans[i] = 1;
                insol[a[i]] = 1;
                insol[b[i]] = 1;
                flag = 1;
            }
        }
    }

    for(int i = 0; i<n; i++)
    {
        if(ans[i])
        {
            out[i] = b[i];
        }
        else
        {
            out[i] = a[i];
        }
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(out[i] == out[j])
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for(int i = 0; i<n; i++)
    {
        cout << out[i] << endl;
    }
}
