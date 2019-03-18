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
        }
        a*=a;
        p/=2;
    }
    return ans;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli l,r;
    cin >> l >> r;
    if(l == r)
    {
        cout << 0 << endl;
        return 0;
    }
    vector <lli> bin1,bin2;
    bin1 = getbinary(l);
    bin2 = getbinary(r);
    lli num;
    for(int i = 0; i<2000; i++)
    {
        if(bin1[i] != bin2[i])
        {
            num = i;
        }
    }
    cout << power(2,num+1)-1 << endl;
}
