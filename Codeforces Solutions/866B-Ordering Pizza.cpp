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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,s;
    cin >> n >> s;
    c a[n];
    pair <lli,lli> b[n];
    lli sum = 0;
    lli sa = 0,sb = 0;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i].si >> a[i].ai >> a[i].bi;
        if(a[i].ai > a[i].bi)
        {
            sa += a[i].si;
        }
        else
        {
            sb += a[i].si;
        }
        sum += a[i].si;
        b[i] = make_pair(a[i].bi-a[i].ai,i);
    }
    sort(b,b+n);
    if(sum%s == 0)
    {
        sum/=s;
    }
    else
    {
        sum += s;
        sum /=s;
    }
    /*cout << endl << endl;
    for(int i = 0; i<n; i++)
    {
        cout << a[b[i].second].si << " " << a[b[i].second].ai << " " << a[b[i].second].bi << endl;
    }*/
    sa = (sa/s)*s;
    sb = (sb/s)*s;
    //cout << endl << sa << " "  << sb << endl << endl;
    int r = n-1;
    int l = 0;
    lli ans = 0;
    int flag;
    while(sa>0)
    {
        if(b[l].first <= 0)
        {
            if(sa >= a[b[l].second].si)
            {
                //cout << "a1 " << b[l].second << endl;
                ans += a[b[l].second].ai * a[b[l].second].si;
                sa -= a[b[l].second].si;
                flag = 1;
                l++;
            }
            else
            {
                //cout << "a2 "<< b[l].second << endl;
                ans += a[b[l].second].ai * sa;
                a[b[l].second].si -= sa;
                sa = 0;
                break;
            }
        }
    }
    while(sb>0)
    {
        if(b[r].first >= 0)
        {
            if(sb >= a[b[r].second].si)
            {
                //cout << "b1 " << b[r].second << endl;
                flag = 1;
                ans += a[b[r].second].bi * a[b[r].second].si;
                sb -= a[b[r].second].si;
                r--;
            }
            else
            {
                //cout << "b2 " << b[r].second << endl;
                ans += a[b[r].second].bi * sb;
                a[b[r].second].si -= sb;
                sb = 0;
                break;
            }
        }
    }
    lli temp1 = 0, temp2 = 0;
    sum = 0;
    //cout << l << " " << r << endl;
    int l1 = l;
    while(l <= r)
    {
        sum += a[b[l].second].si;
        //cout << "both\n";
        temp1 += a[b[l].second].ai * a[b[l].second].si;
        temp2 += a[b[l].second].bi * a[b[l].second].si;
        l++;
    }
    lli temp3 = 0;
    if(sum > s)
    {
        sa = s,sb = s;
        while(sa>0 && l1 <= r)
        {
            if(b[l1].first <= 0)
            {
                if(sa >= a[b[l1].second].si)
                {
                    //cout << "a1 " << b[l].second << endl;
                    temp3 += a[b[l1].second].ai * a[b[l1].second].si;
                    sa -= a[b[l1].second].si;
                    l1++;
                }
                else
                {
                    //cout << "a2 "<< b[l].second << endl;
                    temp3 += a[b[l1].second].ai * sa;
                    a[b[l1].second].si -= sa;
                    sa = 0;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        while(sb>0 && r>=l1)
        {
            if(b[r].first >= 0)
            {
                if(sb >= a[b[r].second].si)
                {
                    //cout << "b1 " << b[r].second << endl;
                    temp3 += a[b[r].second].bi * a[b[r].second].si;
                    sb -= a[b[r].second].si;
                    r--;
                }
                else
                {
                    //cout << "b2 " << b[r].second << endl;
                    temp3 += a[b[r].second].bi * sb;
                    a[b[r].second].si -= sb;
                    sb = 0;
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    if(sum > s)
    {

    }
    //cout << "temp1 " << temp1 << " temp2 " << temp2 << endl;
    cout << ans + max(temp1,temp2,temp3) << endl;
}
