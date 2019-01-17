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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli k;
    cin >> k;
    lli p = power(2,k);
    mat[0][0] = '+';
    construct(mat,1);
    for(int i = 0; i<p; i++)
    {
        for(int j = 0; j<p; j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
}
