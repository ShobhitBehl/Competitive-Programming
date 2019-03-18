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

lli power(lli a,lli b)
{
    lli ans = 1;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            ans *= a;
            ans = ans;
        }
        b/=2;
        a*=a;
        a = a;
    }
    return ans;
}

vector <int> getbinary(int x)
{
    vector <int> bin(16,0);
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m,k;
    cin >> m >> k;
    mii fav;
    for(int i = 0; i<k; i++)
    {
        int temp;
        cin >> temp;
        fav[temp] = 1;
    }
    int n;
    cin >> n;
    int sure[n],can[n];
    for(int i = 0; i<n; i++)
    {
        string st;
        cin >> st;
        int temp,z = 0, favin = 0,nfavin = 0;
        cin >> temp;
        for(int j = 0; j<temp; j++)
        {
            int temp1;
            cin >> temp1;
            if(temp1 == 0)
            {
                z++;
            }
            else if(fav[temp1] == 1)
            {
                favin++;
            }
            else
            {
                nfavin++;
            }
        }
        //cout << favin <<  max(0, z-(m-k-nfavin)) << endl;
        sure[i] = favin + max(0, z-(m-k-nfavin));
        can[i] = min(k,favin + z);
        //cout << sure[i] << " " << can[i] << endl << endl;
    }
    for(int i = 0; i<n; i++)
    {
        int must = 1;
        for(int j = 0; j<n; j++)
        {
            if(i == j)
            {
                continue;
            }
            if(can[i] < sure[j])
            {
                must = -1;
                break;
            }
            if(sure[i] < can[j])
            {
                must = 0;
            }
        }
        if(must == -1)
        {
            cout << 1 << endl;
        }
        else if(must == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
}
