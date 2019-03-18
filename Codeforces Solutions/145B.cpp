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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli a1,a2,a3,a4;
    cin >> a1 >> a2 >> a3 >> a4;
    if(abs(a3-a4) > 1)
    {
        cout << -1 << endl;
        return 0;
    }
    string start,mid,end;
    if(a3 > a4)
    {
        while(a3)
        {
            mid += "47";
            a1--;
            a2--;
            a3--;
        }
    }
    else if(a3 == a4)
    {
        lli temp3 = a3,temp2 = a2,temp1 = a1;
        while(temp3)
        {
            mid += "47";
            temp1--;
            temp2--;
            temp3--;
        }
        mid += "4";
        temp1--;
        if(temp1 < 0 || temp2 < 0)
        {
            mid = "";
            while(a3)
            {
                mid += "74";
                a2--;
                a1--;
                a3--;
            }
            mid += "7";
            a2--;
        }
        else
        {
            a1 = temp1;
            a2 = temp2;
            a3 = temp3;
        }
    }
    else
    {
        while(a4)
        {
            mid += "74";
            a4--;
            a1--;
            a2--;
        }
    }
    if(a1 < 0 || a2 < 0)
    {
        cout << -1 << endl;
        return 0;
    }
    while(a1--)
    {
        start += "4";
    }
    while(a2--)
    {
        end += "7";
    }
    int flag = 0;
    int ff,ls;
    for(int i = 0; i<mid.size(); i++)
    {
        if(mid[i] == '4')
        {
            ff = i;
            break;
        }
    }
    for(int i = 0; i<mid.size(); i++)
    {
        if(mid[i] == '7')
        {
            ls = i;
        }
    }
    for(int i = 0; i<mid.size(); i++)
    {
        cout << mid[i];
        if(i == ff)
        {
            cout << start;
        }
        else if(i == ls)
        {
            cout << end;
        }
    }
    cout << endl;
}
