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

lli seq[200001];
vector <lli> toadd(200001,0);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d",&n);
    int len = 1;
    seq[1] = 0;
    double sum = 0;
    for(int i = 0; i<n; i++)
    {
        int type;
        scanf("%d",&type);
        if(type == 1)
        {
            int a,x;
            scanf("%d %d",&a,&x);
            toadd[a] += x;
            sum += a*x;
        }
        else if(type == 2)
        {
            int num;
            scanf("%d",&num);
            seq[len+1] = num;
            sum += num;
            len++;
        }
        else
        {
            toadd[len-1] += toadd[len];
            sum -= seq[len]+toadd[len];
            toadd[len] = 0;
            len--;
        }
        printf("%.12lf\n",sum/len);
    }
}
