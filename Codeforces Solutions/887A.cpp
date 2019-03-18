#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <climits>
using namespace std;

/*lli power(lli a,lli b)
{
    lli ans;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            ans *= a;
        }
        b /=2;
        a*=a;
    }
    return ans;
}*/

typedef long long int lli;

lli gcd(lli a, lli b)
{
    if(a == 0)
    {
        return b;
    }
    return gcd(b%a,a);
}

long long int min(long long int a, long long int b)
{
    return a>b?b:a;
}

long long int max(long long int a, long long int b)
{
    return a>b?a:b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    if(n<7)
    {
        cout << "no\n";
    }
    else
    {
        int z = 0;
        char c = '0';
        for(int i = n; i>=0; i--)
        {
            if(s[i] == c)
            {
                z++;
            }
            if(z == 6)
            {
                c = '1';
            }
        }
        if(z >= 7)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
}
