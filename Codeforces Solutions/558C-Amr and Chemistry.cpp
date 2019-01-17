#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <climits>
#include <iomanip>
#include <queue>
#include <set>
#include <list>
#include <deque>
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define pi 3.141592653589793238
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back

struct comparator {
 bool operator()(lli i, lli j) {
 return i > j;
 }
};

bool sortpair(pair <lli,lli> &a, pair <lli,lli> &b)
{
    return (b.first-b.second) > (a.first - a.second);
}

lli gcd(lli a, lli b)
{
    if(b < a)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if(a == 0)
    {
        return b;
    }
    return gcd(b%a,a);
}

lli max(lli a, lli b, lli c)
{
    lli arr[3] = {a,b,c};
    sort(arr,arr+3);
    return arr[2];
}


lli lcm(lli a, lli b)
{
    return (a*b/gcd(a,b));
}

bool check(lli x)
{
    while(x%2 == 0)
    {
        x/=2;
    }
    while(x%3 == 0)
    {
        x/=3;
    }
    if(x != 1)
    {
        return false;
    }
    return true;
}

lli ans(int num, int n)
{
    if(n == 1)
    {
        return num;
    }
    else if(n == 2)
    {
        return num+1;
    }
    else if(n == 3)
    {
        return num+2;
    }
    else if(n%3 == 0)
    {
        return ans(num+2,(n-1)/2);
    }
    else if(n%2 == 0)
    {
        return ans(num+1,n/2);
    }
}

vector<lli> getprimes()
{
    vector <lli> pl(101,1);
    for(int i = 2; i<=100; i++)
    {
        if(pl[i] == 1)
        {
            for(int j = 2*i; j<=100; j+=i)
            {
                pl[j] = 0;
            }
        }
    }
    return pl;
}
lli ans(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else if(n == 1 || n == 2)
    {
        return 0;
    }
    else if(n<0)
    {
        return 0;
    }
    else
    {
        return (ans(n-7) | ans(n-3));
    }
}

lli primefactorise(int n)
{
    if(n == 1)
    {
        return 1;
    }
    lli ans = n;
    while (n%2 == 0)
    {
        n = n/2;
        if(n != 1)
        {
            ans += n;
        }
    }

    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            n = n/i;
            if(n != 1)
            {
                ans += n;
            }
        }
    }
    ans += 1;
    return ans;
}

bool check(lli n,lli a,lli b)
{
    while(n > 0)
    {
        if(n%10 == a || n%10 == b)
        {
            n/=10;
        }
        else
        {
            return false;
        }
    }
    return true;
}

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

lli product(lli i)
{
    lli ans = 1;
    while(i > 0)
    {
        if(i%10 != 0)
        {
            ans *= (i%10);

        }
        i/=10;
    }
    return ans;
}

bool isvowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
    {
        return true;
    }
    return false;
}

lli fact(lli x)
{
    lli ans = 1;
    if(x == 0)
    {
        return 1;
    }
    while(x > 0)
    {
        ans = (ans*x)%1000000007;
        x--;
    }
    return ans%1000000007;
}

lli power(lli a,lli b)
{
    lli ans = 1;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            ans *= a;
            ans = ans%1000000007;
        }
        b/=2;
        a*=a;
        a = a%1000000007;
    }
    return ans%1000000007;
}

struct c
{
    lli si,ai,bi;
};

lli N = 100005;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli l = 1, r = 100000;
    vector <lli> lst(N,0),rst(N,0),occur(N,0),above(N,0),level(N,0),ans(N,0);
    for(int i = 2; i<N; i++)
    {
        level[i] = level[i/2] + 1;
    }
    lli n;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        lli x;
        cin >> x;
        occur[x]++;
        ans[1] += level[x]-level[1];
        while(x>1)
        {
            if(x&1)
            {
                rst[x/2]++;
            }
            else
            {
                lst[x/2]++;
            }
            x/=2;
        }
    }
    lli out = ans[1];
    //cout << out << endl;
    for(int i = 1; i<N;)
    {
        if(lst[i] == 0 && above[i] == 0 && occur[i] == 0)
        {
            //cout << "right "  << i << endl;
            i = 2*i + 1;
        }
        else
        {
            //cout << "left " << i << endl;
            above[2*i] = occur[i] + rst[i] + above[i];
            i *= 2;
        }
        if(i > N)
        {
            break;
        }
        if(i&1)
        {
            //cout << ans[i/2] << " " << rst[i/2] << endl;
            ans[i] = ans[i/2] - rst[i/2];
        }
        else
        {
            //cout << ans[i/2] << " " << lst[i/2] << " " << above[i] << endl;
            ans[i] = ans[i/2] - lst[i/2] + above[i];
        }
        out = min(ans[i],out);
    }
    cout << out << endl;
}
