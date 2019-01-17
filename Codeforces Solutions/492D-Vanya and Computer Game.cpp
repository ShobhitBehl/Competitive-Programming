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

char mat[1024][1024];

void construct(char mat[1024][1024],int prev)
{
    for(int i = 0; i<prev; i++)
    {
        for(int j = 0; j<prev; j++)
        {
            mat[i][prev+j] = mat[i][j];
            mat[prev+i][j] = mat[i][j];
            if(mat[i][j] == '+')
            {
                mat[prev+i][prev+j] = '*';
            }
            else
            {
                mat[prev+i][prev+j] = '+';
            }
        }
    }
    prev *= 2;
    if(prev == 1024)
    {
        return;
    }
    else
    {
        construct(mat,prev);
    }
}

struct line
{
    int x1,x2,y1,y2;
};

bool comparator(const line &a, const line &b)
{
    return a.x1 > b.x1;
}

lli MAX = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n,x,y;
    cin >> n >> x >> y;
    int iter1 = 1,iter2 = 1;
    vector <string> ans;
    while(iter1 <= x || iter2 <= y)
    {
        if(iter1*y > iter2*x)
        {
            iter2++;
            ans.pb("Vova");
        }
        else if(iter1*y < iter2*x)
        {
            iter1++;
            ans.pb("Vanya");
        }
        else
        {
            iter1++;
            iter2++;
            ans.pb("Both");
            ans.pb("Both");
        }
    }
    for(int i = 0; i<n; i++)
    {
        lli temp;
        cin >> temp;
        cout << ans[(temp-1)%(x+y)] << endl;
    }
}
