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
    long long int n,k;
    cin >> n >> k;
    int flag = 0;
    if(n==1 && k!=0)
    {
        cout << -1 << endl;
        return 0;
    }
    else if(n==1 && k == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    if(n%2 == 1)
    {
        n--;
        flag = 1;
    }
    if(k<n/2)
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        int x = n/2;
        k -= n/2;
        k++;
        cout << k << " " << 2*k << " ";
        int a = k,b = 2*k;
        int curr = 1;
        for(int i = 1; i<n-2; i+=2)
        {
            if(curr == a || curr == b || curr+1 == a || curr+1 == b)
            {
                curr+=2;
                i-=2;
            }
            else
            {
                cout << curr << " " << curr + 1 << " ";
                curr += 2;
            }
        }
        if(flag == 1)
        {
            while(true)
            {
                if(curr != a && curr != b)
                {
                    cout << curr << endl;
                    break;
                }
                curr++;
            }
        }
    }
}
