#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
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
            ans = ans;
        }
        b/=2;
        a*=a;
        a = a;
    }
    return ans;
}

lli mod(lli a, lli b)
{
    return (((a%b)+b)%b);
}

vector <int> getbinary(int x)
{
    vector <int> bin(16,0);
    int iter = 0;
    while(x > 0)
    {
        if(x%2 == 1)
        {
            bin[iter] = 1;
        }
        else
        {
            bin[iter] = 0;
        }
        iter++;
        x/=2;
    }
    return bin;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n;
    cin >> n;
    int digits = 0;
    vector <int> dig;
    int temp1 = n;
    while(temp1 > 0)
    {
        dig.pb(temp1%10);
        digits++;
        temp1/=10;
    }
    reverse(dig.begin(),dig.end());
    lli x = power(2,digits) - 1;
    vector <int> temp;
    int maxdig = -1;
    for(int i = 1; i<=x; i++)
    {
        temp = getbinary(i);
        int tempnum = 0;
        int ten = 1;
        int flag = 0,tempdig = 0;
        for(int i = 0; i<digits; i++)
        {
            if(temp[i] == 1)
            {
                if(dig[i] == 0 && flag == 0)
                {
                    break;
                }
                else if(dig[i] != 0 && flag == 0)
                {
                    flag = 1;
                    tempnum*=10;
                    tempnum += dig[i];
                    tempdig++;
                }
                else
                {
                    tempnum *= 10;
                    tempnum += dig[i];
                    tempdig++;
                }
            }
            //cout << dig[i];
            //cout << temp[i];
        }
        int x = sqrt(tempnum);
        if(x*x == tempnum && tempnum > 0)
        {
            //cout << tempnum << endl;
            if(maxdig < tempdig)
            {
                maxdig = tempdig;
            }
        }
        //cout << endl;
        temp.clear();
    }
    if(maxdig == -1)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << digits-maxdig << endl;
}
