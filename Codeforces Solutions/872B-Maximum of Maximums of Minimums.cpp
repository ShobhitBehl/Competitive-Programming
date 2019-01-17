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
    lli n,k;
    cin >> n >> k;
    int max = INT_MIN, min = INT_MAX;
    int f;
    int temp;
    for(int i = 0; i<n; i++)
    {
        cin >> temp;
        if(i == 0)
        {
            f = temp;
        }
        if(temp < min)
        {
            min = temp;
        }
        if(temp > max)
        {
            max = temp;
        }
    }
    if(k == 1)
    {
        cout << min << endl;
    }
    else if(k >= 3)
    {
        cout << max << endl;
    }
    else
    {
        if(temp > f)
        {
            cout << temp;
        }
        else
        {
            cout << f;
        }
    }
}
