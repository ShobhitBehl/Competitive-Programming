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

int n,k;
char a[2][100001],s[4];

void dfs(int x, int y, int w, int dy) {
     int i,j;
     if (x+k >= n) {strcpy(s,"YES");}
     if (strcmp(s,"YES")!=0) {
        a[y][x]='X';
        if (a[y+dy][x+k]!='X') {dfs(x+k,y+dy,w+1,-dy);}
        if (a[y][x+1]!='X') {dfs(x+1,y,w+1,dy);}
        if ((a[y][x-1]!='X')&(x-1>w+1)) {dfs(x-1,y,w+1,dy);}
     }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int i,j;
    char g[100001];
    scanf("%i %i",&n,&k);
    scanf("%s",a[0]);
    scanf("%s",a[1]);
    strcpy(s,"NO");
    dfs(0,0,-1,1);
    printf("%s",s);
}
