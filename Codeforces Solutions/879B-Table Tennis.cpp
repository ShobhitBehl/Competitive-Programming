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
    lli n,k;
    cin >> n >> k;
    int arr[n];
    lli curr,req = k;
    cin >> curr;
    for(int i = 1; i<n ;i++)
    {
        cin >> arr[i];
        if(arr[i] < curr)
        {
            req--;
            if(req == 0)
            {
                cout << curr << endl;
                return 0;
            }
        }
        else
        {
            curr = arr[i];
            req = k-1;
        }
    }
    cout << n << endl;

}
