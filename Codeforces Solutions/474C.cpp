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

long long int min(long long int a, long long int b, lli c)
{
    if(a<=b && a<=c)
    {
        return a;
    }
    else if(b<=a && b<=c)
    {
        return b;
    }
    else
    {
        return c;
    }
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

lli power(lli a,lli b)
{
    lli ans = 1;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            ans *= a;
            ans = ans%1000000009;
        }
        b/=2;
        a*=a;
        a = a%1000000009;
    }
    return ans%1000000009;
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

bool digsum(lli n)
{
    int sum = 0;
    while(n > 0)
    {
        sum += (n%10);
        n/=10;
    }
    if(sum == 10)
    {
        return true;
    }
    return false;
}

pair <lli,lli> rotate(lli p[4][4], lli times, lli index)
{
    lli x,y;
    x = p[index][0]-p[index][2];
    y = p[index][1]-p[index][3];
    if(times == 0)
    {
        return make_pair(x + p[index][2],y + p[index][3]);
    }
    else if(times == 1)
    {
        return make_pair(-y + p[index][2],x + p[index][3]);
    }
    else if(times == 2)
    {
        return make_pair(-x + p[index][2],-y + p[index][3]);
    }
    else
    {
        return make_pair(y + p[index][2],-x + p[index][3]);
    }
}

lli dist(lli x1, lli y1, lli x2, lli y2)
{
    return ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1));
}

bool checkifsquare(lli x1, lli y1, lli x2, lli y2, lli x3, lli y3, lli x4, lli y4)
{
    lli distance[6];
    distance[0] = dist(x1,y1,x2,y2);
    distance[1] = dist(x1,y1,x3,y3);
    distance[2] = dist(x1,y1,x4,y4);
    distance[3] = dist(x2,y2,x3,y3);
    distance[4] = dist(x2,y2,x4,y4);
    distance[5] = dist(x3,y3,x4,y4);
    sort(distance,distance+6);
    if(distance[0] == distance[3] && distance[5] == distance[4] && distance[4] != distance[3])
    {
        /*for(lli i = 0;i<6; i++)
        {
            cout << distance[i] << " ";
        }
        cout << endl << endl;*/
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,m;
    cin >> n;
    lli p[4][4];
    for(int t = 0; t<n; t++)
    {
        for(int z = 0; z<4; z++)
        {
            cin >> p[z][0] >> p[z][1] >> p[z][2] >> p[z][3];
        }
        lli min = -1;
        for(int i = 0; i<4; i++)
        {
            for(int j = 0; j<4; j++)
            {
                for(int k = 0; k<4; k++)
                {
                    for(int l = 0; l<4; l++)
                    {
                        lli x1,y1,x2,y2,x3,y3,x4,y4;
                        x1 = rotate(p,i,0).first;
                        y1 = rotate(p,i,0).second;
                        x2 = rotate(p,j,1).first;
                        y2 = rotate(p,j,1).second;
                        x3 = rotate(p,k,2).first;
                        y3 = rotate(p,k,2).second;
                        x4 = rotate(p,l,3).first;
                        y4 = rotate(p,l,3).second;
                        /*if(i == 0 && j == 1 && k == 2 && l == 0)
                        {
                            cout << i << " " << j << " " << k << " " << l << endl;
                            cout << x1 << " " << y1 << endl;
                            cout << x2 << " " << y2 << endl;
                            cout << x3 << " " << y3 << endl;
                            cout << x4 << " " << y4 << endl;
                            cout << checkifsquare(x1,y1,x2,y2,x3,y3,x4,y4) << endl;
                        }*/
                        if(checkifsquare(x1,y1,x2,y2,x3,y3,x4,y4))
                        {
                            /*cout << i << " " << j << " " << k << " " << l << endl;
                            cout << x1 << " " << y1 << endl;
                            cout << x2 << " " << y2 << endl;
                            cout << x3 << " " << y3 << endl;
                            cout << x4 << " " << y4 << endl;
                            cout << endl << endl;*/
                            if(i+j+k+l < min || min == -1)
                            {
                                min = i+j+k+l;
                            }
                        }
                    }
                }
            }
        }
        cout << min << endl;
    }
}
