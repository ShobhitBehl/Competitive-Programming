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
    lli n,m;
    cin >> n >> m;
    vector <int> a(10,0),b(10,0);
    int temp;
    int min1 = INT_MAX,min2 = INT_MAX;
    for(int i = 0; i<n; i++)
    {
        cin >> temp;
        a[temp] = 1;
        if(temp < min1)
        {
            min1 = temp;
        }
    }
    for(int i = 0; i<m; i++)
    {
        cin >> temp;
        b[temp] = 1;
        if(temp < min2)
        {
            min2 = temp;
        }
    }
    for(int i = 0; i<10; i++)
    {
        if(a[i] && b[i])
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << min(min1,min2) << max(min2,min1) << endl;
}
