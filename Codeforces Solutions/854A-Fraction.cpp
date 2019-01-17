#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

long long int dot(long long int a[5],long long int b[5])
{
    long long int ans = 0;
    for(int i = 0; i<5; i++)
    {
        ans += a[i]*b[i];
    }
    return ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    cin >> n;
    long long int a,b;

    if(n%2 == 1)
    {
        a = n/2;
        b = (n/2) + 1;
    }
    else if(n%4 != 0 && n%2 == 0)
    {
        a = (n/2) - 2;
        b = (n/2) + 2;
    }
    else
    {
        a = n/2 -1;
        b = n/2 + 1;
    }

    cout << a << " " << b << endl;
}
