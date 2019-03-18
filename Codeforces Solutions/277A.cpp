#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <climits>
#include <queue>
#include <set>
using namespace std;

typedef long long int lli;

lli power(lli a,lli b)
{
    lli ans;
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

long long int max(long long int a, long long int b)
{
    return a>b?a:b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector < set<int> > lang(m+1);
    vector < set<int> > g(n+1);
    int allzero = 0;
    for(int i = 0; i<n; i++)
    {
        int temp;
        cin >> temp;
        if(temp == 0)
        {
            allzero++;
        }
        for(int j = 0; j<temp; j++)
        {
            int l;
            cin >> l;
            set <int> :: iterator it;
            for(it = lang[l].begin(); it != lang[l].end(); it++)
            {
                g[i+1].insert(*it);
                g[*it].insert(i+1);
            }
            lang[l].insert(i+1);
        }
    }
    lli scc = 0;
    vector <int> col(n+1,0);
    stack <int> s;
    for(int i = 1; i <n+1; i++)
    {
        if(col[i] == 0)
        {
            scc++;
            col[i] = 1;
            s.push(i);
            while(!s.empty())
            {
                int temp = s.top();
                s.pop();
                set <int> ::iterator it;
                for(it = g[temp].begin(); it != g[temp].end(); it++)
                {
                    if(col[*it] == 0)
                    {
                        s.push(*it);
                        col[*it] = 1;
                    }
                }
            }
        }
    }
    if(allzero == n)
    {
        cout << scc << endl;
        return 0;
    }
    cout << scc-1 << endl;
}
