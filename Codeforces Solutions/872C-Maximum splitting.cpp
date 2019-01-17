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
    lli q;
    cin >> q;
    for(int i = 0; i<q; i++)
    {
        int n;
        cin >> n;
        if(n%4 == 0)
        {
            cout << n/4 << endl;
        }
        else if(n%4 == 1)
        {
            if(n<9)
            {
                cout << -1 << endl;
                continue;
            }
            cout << 1 + (n-9)/4 << endl;
        }
        else if(n%4 == 2)
        {
            if(n<6)
            {
                cout << -1 << endl;
                continue;
            }
            cout << 1 + (n-6)/4 << endl;
        }
        else
        {
            if(n<15)
            {
                cout << -1 << endl;
                continue;
            }
            cout << 2 + (n-15)/4 << endl;
        }
    }
}
