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
typedef vector<double> vd;
typedef pair<int,double> pid;
typedef vector< pid > vdd;
#define INF 0x3f3f3f3f

bool check(double mid,lli n, lli l, lli v1, lli v2, lli k, lli groups)
{
    if(v1*mid >= l)
    {
        return 1;
    }
    double t = 0;
    double q = (l - v1*mid)/(v2-v1);
    double z = q*(v2-v1)/(v1+v2);
    for(int i = 0; i<groups; i++)
    {
        t += q;
        if(t >mid)
        {
            return 0;
        }
        t += z;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli n,num1 = 0,num2 = 0;
    cin >> n;
    n*=2;
    lli a[n];
    set <lli> s1,s2;
    vector <lli> ans(n,0);
    map <lli,lli> m;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    for(int i = 0; i<=100; i++)
    {
        if(m[i] >= 2)
        {
            for(int j = 0; j<n; j++)
            {
                if(a[j] == i && ans[j] == 0)
                {
                    if(s1.find(i) == s1.end())
                    {
                        s1.insert(i);
                        ans[j] = 1;
                        num1++;
                    }
                    else if(s2.find(i) == s2.end())
                    {
                        s2.insert(i);
                        ans[j] = 2;
                        num2++;
                    }
                }
            }
        }
    }
    for(int i = 0; i<=100; i++)
    {
        if(m[i] == 1)
        {
            for(int j = 0; j<n; j++)
            {
                if(a[j] == i && ans[j] == 0)
                {
                    if(num1 <= num2)
                    {
                        s1.insert(i);
                        ans[j] = 1;
                        num1++;
                    }
                    else
                    {
                        s2.insert(i);
                        ans[j] = 2;
                        num2++;
                    }
                }
            }
        }
    }
    for(int i = 0; i<=100; i++)
    {
        if(m[i] >= 3)
        {
            for(int j = 0; j<n; j++)
            {
                if(a[j] == i && ans[j] == 0)
                {
                    if(num1 <= num2)
                    {
                        s1.insert(i);
                        ans[j] = 1;
                        num1++;
                    }
                    else
                    {
                        s2.insert(i);
                        ans[j] = 2;
                        num2++;
                    }
                }
            }
        }
    }
    cout << s1.size()*s2.size() << endl;
    for(int i = 0; i<n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
