#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <climits>
#include <queue>
#include <set>
using namespace std;

typedef long long int lli;

lli power(lli a,lli b)
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
}


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
    int a[6];
    int sum = 0;
    for(int i = 0; i<6; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if(sum%2 == 1)
    {
        cout << "NO\n";
        return 0;
    }
    for(int i = 0; i<6; i++)
    {
        for(int j = i+1; j<6; j++)
        {
            for(int k = j+1; k<6; k++)
            {
                if(a[i]+a[j]+a[k] == sum/2)
                {
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }
    cout << "NO\n";
}
