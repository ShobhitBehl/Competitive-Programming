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
    lli x;
    cin >> x;
    if(x == 3)
    {
        cout << 5 << endl;
        return 0;
    }
    for(int i = 1; i<50; i+=2)
    {
        lli num = ((i*i) + 1)/2;
        if(num >= x)
        {
            cout << i << endl;
            return 0;
        }
    }
}
