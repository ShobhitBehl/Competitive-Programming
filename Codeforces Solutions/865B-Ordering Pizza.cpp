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
    long long int n,s;
    cin >> n >> s;
    long long int na = 0,nb = 0,ta = 0,tb = 0;
    vector < pair<long long int,long long int> > a;
    vector < pair<long long int,long long int> > b;
    long long int ans = 0;
    for(int i = 0; i<n; i++)
    {
        long long int si,ai,bi;
        cin >> si >> ai >> bi;
        if(ai > bi)
        {
            ans += ai*si;
            a.push_back(make_pair(ai-bi,si));
            na += si;
        }
        else
        {
            ans += bi*si;
            b.push_back(make_pair(bi-ai,si));
            nb += si;
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    na %= s;
    nb %= s;
    if(na + nb > s)
    {
        cout << ans << endl;
        return 0;
    }
    for(int i = 0;na > 0; i++)
    {
        ta += min(na,a[i].second)*a[i].first;
        na -= min(na,a[i].second);
    }
    for(int i = 0;nb>0; i++)
    {
        tb += min(nb,b[i].second)*b[i].first;
        nb -= min(nb,b[i].second);
    }
    cout << max(ans-ta,ans-tb) << endl;
}
