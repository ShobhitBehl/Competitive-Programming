#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    double xa,ya,xb,yb,xc,yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    if(xb == xa && xc == xb)
    {
        cout << "No\n";
    }
    else if((yb-ya)/(xb-xa) == (yc - yb)/(xc-xb) && xb != xa && xc != xb)
    {
        cout << "No\n";
    }
    else
    {
        double dx = xb-xa;
        double dy = yb-ya;
        double ddx = xc- xb;
        double ddy = yc - yb;
        if(sqrt(dx*dx + dy*dy) != sqrt(ddx*ddx + ddy*ddy))
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
    }
}
