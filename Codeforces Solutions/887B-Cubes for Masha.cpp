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
    lli n;
    cin >> n;
    if(n == 1)
    {
        vector <int> a(10,0);
        for(int i = 0; i<6; i++)
        {
            int temp;
            cin >> temp;
            a[temp]++;
        }
        int ans = 0;
        for(int i = 1; i<10; i++)
        {
            if(a[i] >= 1)
            {
                ans = i;
            }
            else
            {
                cout << ans << endl;
                return 0;
            }
        }
    }
    else if(n == 2)
    {
        int arr[2][10];
        for(int i = 0; i<2; i++)
        {
            for(int j = 0; j<10; j++)
            {
                arr[i][j] = 0;
            }
        }
        for(int i = 0;i <n; i++)
        {
            for(int j = 0; j<6; j++)
            {
                int temp;
                cin >> temp;
                arr[i][temp]++;
            }
        }
        int ans = 0;
        for(int i = 1; i<10; i++)
        {
            if(arr[1][i] >= 1 || arr[0][i] >= 1)
            {
                ans = i;
            }
            else
            {
                cout << ans << endl;
                return 0;
            }
        }
        for(int i = 10; i<100; i++)
        {
            int f = i%10;
            int s = i/10;
            if((arr[0][f] >= 1 && arr[1][s] >= 1) || (arr[1][f] >= 1 && arr[0][s]>=1))
            {
                ans = i;
            }
            else
            {
                cout << ans << endl;
                return 0;
            }
        }
    }
    else if(n == 3)
    {
        int arr[3][10];
        for(int i = 0; i<3; i++)
        {
            for(int j = 0; j<10; j++)
            {
                arr[i][j] = 0;
            }
        }
        for(int i = 0;i<3; i++)
        {
            for(int j = 0; j<6; j++)
            {
                int temp;
                cin >> temp;
                arr[i][temp]++;
            }
        }
        int ans = 0;
        for(int i = 1; i<10; i++)
        {
            if(arr[1][i] >= 1 || arr[0][i] >= 1 || arr[2][i] >= 1)
            {
                ans = i;
            }
            else
            {
                cout << ans << endl;
                return 0;
            }
        }
        for(int i = 10; i<100; i++)
        {
            int f = i%10;
            int s = i/10;
            if((arr[0][f] >= 1 && arr[1][s] >= 1) || (arr[1][f] >= 1 && arr[0][s]>=1) || (arr[1][f] >= 1 && arr[2][s]>=1) || (arr[2][f] >= 1 && arr[1][s]>=1) || (arr[0][f] >= 1 && arr[2][s]>=1) || (arr[2][f] >= 1 && arr[0][s]>=1))
            {
                ans = i;
            }
            else
            {
                cout << ans << endl;
                return 0;
            }
        }
        for(int i = 100; i<1000; i++)
        {
            int f = i%10;
            int s = (i/10)%10;
            int t = i/100;
            if((arr[0][f] >= 1 && arr[1][s] >= 1 && arr[2][t] >= 1) || (arr[0][f] >= 1 && arr[2][s] >= 1 && arr[1][t] >= 1) || (arr[1][f] >= 1 && arr[0][s] >= 1 && arr[2][t] >= 1) || (arr[1][f] >= 1 && arr[2][s] >= 1 && arr[0][t] >= 1) || (arr[2][f] >= 1 && arr[0][s] >= 1 && arr[1][t] >= 1) || (arr[2][f] >= 1 && arr[1][s] >= 1 && arr[0][t] >= 1))
            {
                ans = i;
            }
            else
            {
                cout << ans << endl;
                return 0;
            }
        }
    }
}
