#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <climits>
using namespace std;

int power(int a,int b)
{
    int ans;
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
    int n,k;
    cin >> n >> k;
    int p2[] = {1,2,4,8};
    int s = p2[k-1]*2;
    int arr[s];
    for(int i = 0; i<s; i++)
    {
        arr[i] = 0;
    }
    for(int i = 0; i<n; i++)
    {
        int temp = 0;
        for(int j = 0; j<k; j++)
        {
            int x;
            cin >> x;
            temp += p2[k-j-1]*x;
        }
        arr[temp] = 1;
    }
    if(arr[0] == 1)
    {
        cout << "YES\n";
        return 0;
    }
    else if(k == 1)
    {
        cout << "NO\n";
        return 0;
    }
    else if(k == 2)
    {
        if(arr[1] == 1 && arr[2] == 1)
        {
            cout << "YES\n";
            return 0;
        }
    }
    else if(k == 3)
    {
        if((arr[1] == 1 && (arr[6] == 1 || arr[4] == 1 || arr[2] == 1)) || (arr[2] == 1 && (arr[5] == 1 || arr[4] == 1)) || (arr[4] == 1 && (arr[3] == 1)))
        {
            cout << "YES\n";
            return 0;
        }
    }
    else
    {
        if((arr[1] == 1 && (arr[6] == 1 || arr[10] == 1 || arr[12] == 1 || arr[2] == 1 || arr[4] == 1 || arr[8] == 1 || arr[14] == 1)) || (arr[2] == 1 && (arr[12] == 1 || arr[5] == 1 || arr[9] == 1 || arr[4] == 1 || arr[8] == 1 || arr[13] == 1)) || (arr[4] == 1 && (arr[3] == 1 || arr[10] == 1 || arr[9] || arr[8] == 1 || arr[11] == 1)) || (arr[8] == 1 && (arr[6] == 1 || arr[3] == 1 || arr[5] == 1 || arr[7] == 1)))
        {
            cout << "YES\n";
            return 0;
        }
        else if((arr[3] == 1 && arr[12] == 1) || (arr[9] == 1 && arr[6] == 1) || (arr[10] == 1 && arr[5] == 1))
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}
