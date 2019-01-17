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

lli mini(lli a, lli b, lli c, lli d)
{
    if(min(a,b,c,d) == a)
    {
        return 1;
    }
    else if(min(a,b,c,d) == b)
    {
        return 2;
    }
    else if(min(a,b,c,d) == c)
    {
        return 3;
    }
    else if(min(a,b,c,d) == d)
    {
        return 4;
    }
}

lli maxi(lli a, lli b, lli c, lli d)
{
    if(max(a,b,c,d) == 0)
    {
        return 0;
    }
    else if(max(a,b,c,d) == a)
    {
        return 1;
    }
    else if(max(a,b,c,d) == b)
    {
        return 2;
    }
    else if(max(a,b,c,d) == c)
    {
        return 3;
    }
    else if(max(a,b,c,d) == d)
    {
        return 4;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,t,k;
    cin >> n >> t >> k;
    lli a[t];
    lli b[t];
    lli minleaf = 0;
    for(int i = 0; i<t; i++)
    {
        cin >> a[i];
        if(i == 0)
        {
            b[i] = a[i]+1;
        }
        else
        {
            b[i] = b[i-1] + a[i];
        }
        if(i > 0)
        {
            if(a[i] < a[i-1])
            {
                minleaf += a[i-1] - a[i];
            }
        }
        if(i == t-1)
        {
            minleaf += a[i];
        }
        //cout << b[i] << " ";
    }
    lli maxleaf = (n-1)-(t-1);
    //cout << endl << minleaf << " " << maxleaf << endl;
    if(k < minleaf || k > maxleaf)
    {
        cout << -1 << endl;
    }
    else
    {
        vector < vector<int> > g(n+1);
        int toaddto = 1;
        int topush = 2;
        int temp = maxleaf - k;
        //cout << temp << endl;
        for(int i = 0; i<t; i++)
        {
            for(int j = 0; j < a[i]; j++)
            {
                //cout << toaddto << " " << topush << " " << temp << endl << endl;
                if(i == 0)
                {
                    g[toaddto].push_back(topush);
                    topush++;
                }
                else
                {
                    g[toaddto].push_back(topush);
                    topush++;
                    if(temp > 0 && toaddto < b[i-1] && j != a[i]-1)
                    {
                        toaddto++;
                        temp--;
                    }
                }
            }
            if(i == 0)
            {
                toaddto = 2;
            }
            else
            {
                toaddto = b[i-1]+1;
            }
        }
        cout << n  << endl;
        for(int i = 1; i<n; i++)
        {
            int temp = g[i].size();
            for(int j = 0; j<temp; j++)
            {
                cout << i << " " << g[i][j] << endl;
            }
        }
    }
}
