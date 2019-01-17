#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <climits>
#include <queue>
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

struct comparator {
 bool operator()(lli i, lli j) {
 return i > j;
 }
};

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
    int size = s.size();
    int l = 0;
    for(int i = size-1; i>=0; i--)
    {
        if(s[i] == '0')
        {
            l++;
        }
        else
        {
            break;
        }
    }
    size -= l;
    int r;
    if(size%2 == 0)
    {
        l = (size/2) - 1;
        r = size/2;
    }
    else
    {
        l = (size/2) - 1;
        r = (size/2) + 1;
    }
    int flag = 1;
    while(l >= 0 && r <size)
    {
        if(s[l] != s[r])
        {
            flag = 0;
            break;
        }
        l--;
        r++;
    }
    if(flag == 0)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
}
