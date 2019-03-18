#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
typedef set<lli> sl;
//typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;
#define x first
#define y second
#define mp make_pair
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n,l,x,y;
    cin >> n >> l >> x >> y;
    lli a[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    lli xf = 0,yf = 0;
    lli left = 0,right = 0;
    while(right < n)
    {
        if(a[right] - a[left] == x)
        {
            xf = 1;
            break;
        }
        else if(a[right] - a[left] < x)
        {
            right++;
        }
        else
        {
            left++;
        }
    }
    left = 0,right = 0;
    while(right < n)
    {
        if(a[right] - a[left] == y)
        {
            yf = 1;
            break;
        }
        else if(a[right] - a[left] < y)
        {
            right++;
        }
        else
        {
            left++;
        }
    }
    if(yf || xf)
    {
        if(yf && xf)
        {
            cout << 0 << endl;
            return 0;
        }
        else if(yf)
        {
            cout << 1 << endl;
            cout << x << endl;
            return 0;
        }
        else
        {
            cout << 1 << endl;
            cout << y << endl;
            return 0;
        }
    }
    left = 0,right = 0;
    while(right < n)
    {
        if(a[right] - a[left] == y+x)
        {
            cout << 1 << endl;
            cout << a[left] + x << endl;
            return 0;
        }
        else if(a[right] - a[left] < y+x)
        {
            right++;
        }
        else
        {
            left++;
        }
    }
    left = 0,right = 0;
    while(right < n)
    {
        if(a[right] - a[left] == y-x)
        {
            if(a[left] + y <= l)
            {
                cout << 1 << endl;
                cout << a[left] + y << endl;
                return 0;
            }
            else if(a[right]-y >= 0)
            {
                cout << 1 << endl;
                cout << a[right]-y << endl;
                return 0;
            }
            else
            {
                left++;
                right++;
            }
        }
        else if(a[right] - a[left] < y-x)
        {
            right++;
        }
        else
        {
            left++;
        }
    }
    cout << 2 << endl;
    cout << x << " " << y << endl;
}
