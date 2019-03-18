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
    lli n;
    cin >> n;
    lli a[n];
    vector<lli> track(200001,-1);
    set <int> s;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
        track[a[i]] = i;
        s.insert(a[i]);
    }
    lli min = INT_MAX,ans;
    for(int i = 0; i<200001 ;i++)
    {
        if(track[i] != -1)
        {
            if(track[i] < min)
            {
                ans = i;
                min = track[i];
            }
        }
    }
    cout << ans << endl;
}
