#include <iostream>
#include <string>
#include <set>
using namespace std;

long long int power(long long int a, long long int b)
{
    long long int ans = 1;
    while(b>0)
    {
        if(b%2 == 1)
        {
            ans *= a;
        }
        a *= a;
        b /= 2;
    }
    return ans;
}

int main() 
{
    long long int d[51];
    for(int i = 1; i<51; i++)
    {
        d[i] = power(2,i) - 1;
    }
    d[0] = 0;
    long long int n,m;
    cin >> n >> m;
    long long int arr [n][m];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m ; j++)
        {
            cin >> arr[i][j];
        }
    }
    long long int ans = 0,one = 0,zero = 0;
    for(int i = 0; i<n; i++)
    {
        one = 0;
        zero = 0;
        for(int j = 0; j<m; j++)
        {
            if(arr[i][j] == 1)
            {
                one++;
            }
            else
            {
                zero++;
            }
        }
        ans += d[one] + d[zero];
    }
    for(int i = 0; i<m; i++)
    {
        one = 0;
        zero = 0;
        for(int j = 0; j<n; j++)
        {
            if(arr[j][i] == 1)
            {
                one++;
            }
            else
            {
                zero++;
            }
        }
        ans += d[one] + d[zero];
    }
    cout << ans-(n*m) << endl;
}