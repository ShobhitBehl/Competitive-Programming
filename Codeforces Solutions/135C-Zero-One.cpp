#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
typedef set<lli> sl;
typedef map<int,int> mii;
typedef set<int> si;
typedef pair<double,double> pdd;
typedef map<double,lli> mdl;
typedef set<double> sd;
#define x first
#define y second
#define mp make_pair
#define pb push_back
const lli mod = 1e9 + 7;

lli power(lli a, lli p)
{
    lli ans = 1;
    while(p > 0)
    {
        if(p%2)
        {
            ans *= a;
            ans %= mod;
        }
        a*=a;
        a%=mod;
        p/=2;
    }
    return ans%mod;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    lli o = 0,z = 0,q = 0;
    cin >> s;
    int temp = s.size();
    for(int i = 0; i<temp; i++)
    {
        if(s[i] == '1')
        {
            o++;
        }
        else if(s[i] == '0')
        {
            z++;
        }
        else
        {
            q++;
        }
    }
    lli turns = temp-2,temp1,temp2,can1 = 0, can0 = 0;
    temp1 = (turns+1)/2;
    temp2 = turns/2;
    if(o <= temp1)
    {
        cout << "00\n";
    }
    if(o+q > temp1 && z+q > temp2)
    {
        if(o <= temp1)
        {
            can1 = 1;
        }
        if(z <= temp2)
        {
            can0 = 1;
        }
        if(s[temp-1] == '1')
        {
            cout << "01\n";
        }
        else if(s[temp-1] == '0')
        {
            cout << "10\n";
        }
        else
        {
            if(can1)
            {
                cout << "01\n";
            }
            if(can0)
            {
                cout << "10\n";
            }
        }
    }
    if(z <= temp2)
    {
        cout << "11\n";
    }
}
