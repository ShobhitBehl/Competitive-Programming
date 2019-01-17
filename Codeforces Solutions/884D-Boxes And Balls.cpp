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
    if(n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    priority_queue<lli, vector<lli>,comparator> heap;

    for(int i = 0; i<n; i++)
    {
        lli temp;
        cin >> temp;
        heap.push(temp);
    }
    if(n%2 == 0)
    {
        heap.push(0);
    }
    lli x;
    lli ans = 0;
    while(heap.size() > 1)
    {
        x = 0;
        for(int i = 0; i<3; i++)
        {
            x += heap.top();
            heap.pop();
            if(heap.empty())
            {
                break;
            }
        }
        heap.push(x);
        ans += x;
    }
    cout << ans << endl;
}
