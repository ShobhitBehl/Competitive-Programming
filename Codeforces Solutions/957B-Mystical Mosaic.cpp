#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
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

lli mod(lli a, lli b)
{
    return (((a%b)+b)%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,m;
    cin >> n >> m;
    char mat[n][m];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin >> mat[i][j];
        }
    }
    vector < vector<int> > r(100),c(100);
    mll mapr,mapc;
    int iter = 1;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(mat[i][j] == '#')
            {
                //cout << i << " " << j << " " << mapr[i] << " " << mapc[j] << endl;
                if(mapr[i] > 0 && mapc[j] == 0)
                {
                    //cout << "b" << " " << mapr[i] << endl;
                    mapc[j] = mapr[i];
                    c[mapr[i]].pb(j);
                }
                else if(mapc[j] > 0 && mapr[i] == 0)
                {
                    //cout << "c" << " " << mapc[j] << endl;
                    mapr[i] = mapc[j];
                    r[mapc[j]].pb(i);
                }
                else if(mapr[i] == 0 && mapc[j] == 0)
                {
                    //cout << "a" << " " << iter << endl;
                    mapr[i] = iter;
                    mapc[j] = iter;
                    r[iter].pb(i);
                    c[iter].pb(j);
                    iter++;
                }
                else if(mapr[i] != mapc[j])
                {
                    cout << "No\n";
                    return 0;
                }
                //cout << endl;
            }
        }
    }
    for(int i = 1; i<iter; i++)
    {
        for(int j = 0; j<r[i].size(); j++)
        {
            for(int k = 0; k<c[i].size(); k++)
            {
                if(mat[r[i][j]][c[i][k]] == '.')
                {
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }
    cout << "Yes\n";
}
