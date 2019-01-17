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
    lli n,x;
    cin >> n >> x;
    vector <int> arr(101,0);
    for(int i = 0; i<n ;i++)
    {
        lli temp;
        cin >> temp;
        arr[temp] = 1;
    }
    lli ans = 0;
    for(int i = 0; i<x; i++)
    {
        if(arr[i] == 0)
        {
            ans++;
        }
    }
    if(arr[x] == 1)
    {
        ans++;
    }
    cout << ans << endl;
    return 0;
}
