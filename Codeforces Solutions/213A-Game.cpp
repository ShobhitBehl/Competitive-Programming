#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pi 3.141592653589793238
typedef pair<lli,lli> pll;
typedef map<lli,lli> mll;
typedef set<lli> sl;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;
#define x first
#define y second
#define mp make_pair
#define pb push_back

lli M = 1000000007;

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

double distsqrd(double x1, double y1, double x2, double y2)
{
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
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
            ans = ans;
        }
        b/=2;
        a*=a;
        a = a;
    }
    return ans;
}

vector <int> getbinary(int x)
{
    vector <int> bin(10,0);
    int iter = 0;
    while(x > 0)
    {
        if(x%2 == 1)
        {
            bin[iter] = 1;
        }
        else
        {
            bin[iter] = 0;
        }
        iter++;
        x/=2;
    }
    return bin;
}

int getnum(vector <int> bin)
{
    int t = 1;
    int n = bin.size();
    int ret = 0;
    for(int i = 0; i<n; i++)
    {
        ret += t*bin[i];
        t*=2;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int home[n+1];
    map <int,vector<int> > req;
    for(int i = 1; i<=n; i++)
    {
        cin >> home[i];
    }
    for(int i = 1; i<=n; i++)
    {
        int temp;
        cin >> temp;
        for(int j = 0; j<temp; j++)
        {
            int r;
            cin >> r;
            req[i].pb(r);
        }
    }
    lli ans = INT_MAX;
    for(int s = 1; s<=3; s++)
    {
        vector <int> done(n+1,0);
        int curr = s;
        //cout << "starting at " << s << endl;
        int left = n;
        lli hours = 0;
        while(left)
        {
            //cout << "Currently at home " << curr << endl;
            for(int q = 0; q<n; q++)
            {
                for(int i = 1; i<=n; i++)
                {
                    //cout << "Looking at program " << i << "     ";
                    if(done[i] == 1)
                    {
                        //cout << "It's been done\n";
                        continue;
                    }
                    if(home[i] == curr)
                    {
                        //cout << "Yes correct home\n";
                        int can = 1;
                        for(auto p : req[i])
                        {
                            //cout << p << " ";
                            if(done[p] == 0)
                            {
                                //cout << "Haven't done program " << p << endl;
                                can = 0;
                                break;
                            }
                        }
                        //cout << endl;
                        if(can)
                        {
                            //cout << "Did program " << i << endl;
                            hours++;
                            left--;
                            done[i] = 1;
                            if(left == 0)
                            {
                                break;
                            }
                        }
                    }
                }
            }
            if(left == 0)
            {
                break;
            }
            curr++;
            if(curr == 4)
            {
                curr = 1;
            }
            hours++;
        }
        //cout << endl;
        ans = min(hours,ans);
    }
    cout << ans << endl;
}
