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

lli min(lli a, lli b, lli c, lli d)
{
    lli arr[4] = {a,b,c,d};
    sort(arr,arr+4);
    return arr[0];
}

lli max(lli a, lli b, lli c, lli d)
{
    lli arr[4] = {a,b,c,d};
    sort(arr,arr+4);
    return arr[3];
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

lli lcm(lli a, lli b)
{
    return (a*b/gcd(a,b));
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

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
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

lli mini(lli a, lli b, lli c, lli d)
{
    if(min(a,b,c,d) == a)
    {
        return 1;
    }
    else if(min(a,b,c,d) == b)
    {
        return 2;
    }
    else if(min(a,b,c,d) == c)
    {
        return 3;
    }
    else if(min(a,b,c,d) == d)
    {
        return 4;
    }
}

lli maxi(lli a, lli b, lli c, lli d)
{
    if(max(a,b,c,d) == 0)
    {
        return 0;
    }
    else if(max(a,b,c,d) == a)
    {
        return 1;
    }
    else if(max(a,b,c,d) == b)
    {
        return 2;
    }
    else if(max(a,b,c,d) == c)
    {
        return 3;
    }
    else if(max(a,b,c,d) == d)
    {
        return 4;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i<n; i++)
    {
        int num = 0,max1 = -1,max2 = -1,max3 = -1;
        while(i<n && a[i] != 0)
        {
            if(a[i] > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = a[i];
            }
            else if(a[i] > max2)
            {
                max3 = max2;
                max2 = a[i];
            }
            else if(a[i] > max3)
            {
                max3 = a[i];
            }
            num++;
            i++;
        }
        if(num>=3)
        {
            for(int j = i-num; j<i; j++)
            {
                if(a[j] == max1)
                {
                    max1 = -1;
                    cout << "pushStack\n";
                }
                else if(a[j] == max2)
                {
                    max2 = -1;
                    cout << "pushQueue\n";
                }
                else if(a[j] == max3)
                {
                    max3 = -1;
                    cout << "pushFront\n";
                }
                else
                {
                    cout << "pushBack\n";
                }
            }
            if(i == n && a[n-1] != 0)
            {
                continue;
            }
            cout << "3 popStack popQueue popFront\n";
        }
        else if(num == 2)
        {
            cout << "pushStack\npushQueue\n";
            if(i == n && a[n-1] != 0)
            {
                continue;
            }
            cout << "2 popStack popQueue\n";
        }
        else if(num == 1)
        {
            cout << "pushStack\n";
            if(i == n && a[n-1] != 0)
            {
                continue;
            }
            cout << "1 popStack\n";
        }
        else if(num == 0)
        {
            cout << "0\n";
        }
    }
}
