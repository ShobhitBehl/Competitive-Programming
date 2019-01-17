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
    lli n,m;
    cin >> n >> m;
    char mat[n+1][m+1];
    vector < vector<lli> > hor(n+1,vector<lli>(m+1,0)),ver(n+1, vector <lli>(m+1,0));
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            cin >> mat[i][j];
        }
        for(int j = 1; j<=m; j++)
        {
            if(mat[i][j] == '.' && mat[i-1][j] == '.')
            {
                ver[i][j]++;
            }
            if(mat[i][j] == '.' && mat[i][j-1] == '.')
            {
                hor[i][j]++;
            }
            hor[i][j] += hor[i-1][j] + hor[i][j-1] - hor[i-1][j-1];
            ver[i][j] += ver[i-1][j] + ver[i][j-1] - ver[i-1][j-1];
        }
    }
    lli q;
    cin >> q;
    for(int i = 0; i<q; i++)
    {
        lli x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lli temp1 = ver[x2][y2] - ver[x1][y2] - ver[x2][y1-1] + ver[x1][y1-1];
        lli temp2 = hor[x2][y2] - hor[x2][y1] - hor[x1-1][y2] + hor[x1-1][y1];
        cout << temp1 + temp2 << endl;
    }
}
