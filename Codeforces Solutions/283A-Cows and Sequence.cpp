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
typedef vector<double> vd;
typedef pair<int,double> pid;
typedef vector< pid > vdd;
#define INF 0x3f3f3f3f

lli power(lli a, lli b)
{
    lli ans = 1;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            ans *= a;
        }
        a *= a;
        b/=2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    vector <lli> op1(200001,0);
    vector <lli> seq(200001,0);
    int n;
    scanf("%d",&n);
    double sum = 0;
    lli len = 1;
    for(int i = 0; i<n; i++)
    {
        int u;
        scanf("%d",&u);
        if(u == 1)
        {
            int a,toadd;
            scanf("%d %d",&a,&toadd);
            sum += a*toadd;
            op1[a] += toadd;
        }
        else if(u == 2)
        {
            int app;
            scanf("%d",&app);
            sum += app;
            len++;
            seq[len] = app;
        }
        else
        {
            op1[len-1] += op1[len];
            sum -= seq[len]+op1[len];
            op1[len] = 0;
            len--;
        }
        printf("%.15f\n",sum/len);
    }
}
