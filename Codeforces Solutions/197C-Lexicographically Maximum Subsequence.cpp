#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <climits>
using namespace std;

int power(int a,int b)
{
    int ans;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            ans *= a;
        }
        b /=2;
        a*=a;
    }
    return ans;
}

typedef long long int lli;

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

long long int max(long long int a, long long int b)
{
    return a>b?a:b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    lli s = str.size();
    char c;
    string out;
    out += str[s-1];
    c = str[s-1];
    for(int i = s-2; i>=0; i--)
    {
        if(c-'a' <= str[i]-'a')
        {
            out += str[i];
            c = str[i];
        }
    }
    reverse(out.begin(),out.end());
    cout << out << endl;
}
