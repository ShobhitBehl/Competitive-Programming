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

double min(double a, double b, double c, double d)
{
    double arr[4] = {a,b,c,d};
    sort(arr,arr+4);
    return arr[0];
}

double min(double a, double b, double c)
{
    double arr[3] = {a,b,c};
    sort(arr,arr+3);
    return arr[0];
}

long long int max(long long int a, long long int b)
{
    return a>b?a:b;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,length,x,y;
    map <int,int> m;
    cin >> n >> length  >> x >> y;
    lli a[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    int l = 0,r = 0;
    int found = 0;
    while(r < n)
    {
        if(a[r] - a[l] < x)
        {
            r++;
        }
        else if(a[r] - a[l] > x)
        {
            l++;
        }
        else
        {
            found++;
            break;
        }
    }
    l = 0,r = 0;
    while(r < n)
    {
        if(a[r] - a[l] < y)
        {
            r++;
        }
        else if(a[r] - a[l] > y)
        {
            l++;
        }
        else
        {
            found+=2;
            break;
        }
    }
    if(found == 3)
    {
        cout << 0 << endl;
        return 0;
    }
    else if(found == 1)
    {
        cout << 1 << endl;
        cout << y << endl;
        return 0;
    }
    else if(found == 2)
    {
        cout << 1 << endl;
        cout << x << endl;
        return 0;
    }
    else
    {
        for(int i = 0; i<n; i++)
        {
            int addmark = a[i] + x;
            if(addmark <= length)
            {
                if(m[addmark + y] == 1 || m[addmark-y] == 1)
                {
                    cout << 1 << endl;
                    cout << addmark << endl;
                    return 0;
                }
            }
            addmark = a[i]-x;
            if(addmark >= 0)
            {
                if(m[addmark - y] == 1 || m[addmark+y] == 1)
                {
                    cout << 1 << endl;
                    cout << addmark << endl;
                    return 0;
                }
            }
            addmark = a[i] + y;
            if(addmark <= length)
            {
                if(m[addmark + x] == 1 || m[addmark-x] == 1)
                {
                    cout << 1 << endl;
                    cout << addmark << endl;
                    return 0;
                }
            }
            addmark = a[i]-y;
            if(addmark >= 0)
            {
                if(m[addmark - x] == 1 || m[addmark+x] == 1)
                {
                    cout << 1 << endl;
                    cout << addmark << endl;
                    return 0;
                }
            }
        }
    }
    cout << 2 << endl;
    cout << x << " " << y;
}
