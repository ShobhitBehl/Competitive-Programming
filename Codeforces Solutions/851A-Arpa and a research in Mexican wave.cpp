#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,t;
    cin >> n >> k >> t;
    if(t <= k)
    {
        cout << t << endl;
    }
    else if(t > k && t<= n)
    {
        cout << k << endl;
    }
    else
    {
        cout << k-(t-n) << endl;
    }
}
