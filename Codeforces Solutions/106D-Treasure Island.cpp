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

struct bun
{
    lli a,b,c,d;
};

bool comparator(bun &a,bun &b)
{
    return b.c*a.d > a.c*b.d;
}

const int MAX=1005, MAXM=13;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n,m;
    cin >> n >> m;
    map <char,pll> m1;
    char a[n][m];
    lli N[n][m],S[n][m],E[n][m],W[n][m];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            N[i][j] = 0;
            S[i][j] = 0;
            E[i][j] = 0;
            W[i][j] = 0;
            cin >> a[i][j];
            if(a[i][j] != '#' && a[i][j] != '.')
            {
                m1[a[i][j]] = mp(i,j);
            }
        }
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(j > 0)
            {
                if(a[i][j-1] != '#')
                {
                    W[i][j] = W[i][j-1] + 1;
                }
                if(a[i][m-j] != '#')
                {
                    E[i][m-j-1] = E[i][m-j] + 1;
                }
            }
            if(i > 0)
            {
                if(a[i-1][j] != '#')
                {
                    N[i][j] = N[i-1][j] + 1;
                }
                if(a[n-i][j] != '#')
                {
                    S[n-i-1][j] = S[n-i][j] + 1;
                }
            }
        }
    }
    lli k;
    cin >> k;
    pair <char,int> q[k];
    vector <char> ans;
    for(int i = 0; i<k; i++)
    {
        cin >> q[i].x >> q[i].y;
    }
    for(auto e : m1)
    {
        int si = e.y.x;
        int sj = e.y.y;
        int flag = 0;
        for(int i = 0; i<k; i++)
        {
            if(q[i].x == 'N')
            {
                if(N[si][sj] < q[i].y)
                {
                    flag = 1;
                    break;
                }
                else
                {
                    si -= q[i].y;
                }
            }
            else if(q[i].x == 'S')
            {
                if(S[si][sj] < q[i].y)
                {
                    flag = 1;
                    break;
                }
                else
                {
                    si += q[i].y;
                }
            }
            else if(q[i].x == 'E')
            {
                if(E[si][sj] < q[i].y)
                {
                    flag = 1;
                    break;
                }
                else
                {
                    sj += q[i].y;
                }
            }
            else
            {
                if(W[si][sj] < q[i].y)
                {
                    flag = 1;
                    break;
                }
                else
                {
                    sj -= q[i].y;
                }
            }
        }
        if(flag == 0)
        {
            ans.pb(e.x);
        }
    }
    if(ans.size() == 0)
    {
        cout << "no solution\n";
        return 0;
    }
    for(int i = 0; i<ans.size(); i++)
    {
        cout << ans[i];
    }
}
