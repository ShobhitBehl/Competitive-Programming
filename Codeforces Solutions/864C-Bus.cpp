#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <climits>
using namespace std;

long long int power(long long int n)
{
    long long int a = 1;
    while(1)
    {
        if(a>=n)
        {
            return a;
        }
        a*=2;
    }
}

long long int min(long long int a, long long int b)
{
    return a>b?b:a;
}

long long int max(long long int a, long long int b)
{
    return a>b?a:b;
}

struct t
{
    long long int si,fi,se;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,f,k;
    cin >> a >> b >> f >> k;
    int ans = 0,fuel = b;
    if(b < f)
    {
        cout << -1 << endl;
        return 0;
    }
    fuel -= f;
    for(int i = 0; i<(k-1)/2; i++)
    {
        if(fuel < 2*(a-f))
        {
            if(b < 2*(a-f))
            {
                cout << -1 << endl;
                return 0;
            }
            ans++;
            fuel = b;
        }
        fuel -= 2*(a-f);
        if(fuel < 2*f)
        {
            if(b < 2*f)
            {
                cout << -1 << endl;
                return 0;
            }
            ans++;
            fuel = b;
        }
        fuel -= 2*f;
    }
    if(k%2 == 0)
    {
        if(fuel < 2*(a-f))
        {
            if(b < 2*(a-f))
            {
                cout << -1 << endl;
                return 0;
            }
            ans++;
            fuel = b;
        }
        fuel -= 2*(a-f);
        if(fuel < f)
        {
            if(b < f)
            {
                cout << -1 << endl;
                return 0;
            }
            ans ++;
            fuel = b;
        }
    }
    else
    {
        if(fuel < a-f)
        {
            if(b < a-f)
            {
                cout << -1 << endl;
                return 0;
            }
            ans++;
            fuel = b;
        }
    }
    cout << ans << endl;
}
