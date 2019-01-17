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
    lli n;
    cin >> n;
    lli a[2*n];
    for(int i = 0; i<2*n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+2*n);
    lli ans = INT_MAX,temp = 0;
    for(int i = 0; i<2*n; i++)
    {
        for(int j = i+1; j<2*n; j++)
        {
            temp = 0;
            for(int k = 0; k<2*n; k++)
            {
                if(k == i || k == j)
                {
                    continue;
                }
                else
                {
                    int x = 1;
                    while(k+x == i || k+x == j)
                    {
                        x++;
                    }
                    temp += a[k+x] - a[k];
                    k+=x;
                }
            }
            if(temp < ans)
            {
                ans = temp;
            }
        }
    }
    cout << ans << endl;
}
