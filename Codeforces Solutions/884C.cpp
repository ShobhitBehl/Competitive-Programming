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
    lli a[n+1],v[n+1];
    for(int i = 1; i<=n; i++)
    {
        v[i] = 0;
        cin >> a[i];
    }
    vector <lli> nodes;
    lli count;
    for(int i = 1; i<=n; i++)
    {
        if(v[i] == 0)
        {
            count = 1;
            v[i] = 1;
            lli curr = i;
            lli next;
            while(1)
            {
                next = a[curr];
                if(v[next] == 1)
                {
                    break;
                }
                v[next] = 1;
                curr = next;
                count++;
            }
            nodes.push_back(count);
        }
    }
    sort(nodes.begin(),nodes.end());
    lli len = nodes.size();
    if(len == 1)
    {
        cout << nodes[0]*nodes[0] << endl;
        return 0;
    }
    nodes[len-2] += nodes[len-1];
    lli ans = 0;
    for(int i = 0; i<len-1; i++)
    {
        ans += (nodes[i]*nodes[i]);
    }
    cout << ans << endl;
}
