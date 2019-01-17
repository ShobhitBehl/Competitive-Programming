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
    int f = 0;
    for(int i = 0; i<n; i++)
    {
        if(s[i] == 'N')
        {
            if(s[i+1] == 'i' && s[i+2] == 'k' && s[i+3] == 'i' && s[i+4] == 't' && s[i+5] == 'a')
            {
                f++;
            }
        }
        else if(s[i] == 'D')
        {
            if(s[i+1] == 'a' && s[i+2] == 'n' && s[i+3] == 'i' && s[i+4] == 'l')
            {
                f++;
            }
        }
        else if(s[i] == 'O')
        {
            if(s[i+1] == 'l' && s[i+2] == 'y' && s[i+3] == 'a')
            {
                f++;
            }
        }
        else if(s[i] == 'S' && s[i+1] == 'l' && s[i+2] == 'a' && s[i+3] == 'v' && s[i+4] == 'a')
        {
            f++;
        }
        else if(s[i] == 'A' && s[i+1] == 'n' && s[i+2] == 'n')
        {
            f++;
        }
    }
    if(f == 1)
    {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
}
