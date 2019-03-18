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
using namespace std;



typedef long long int lli;

#include <bits/stdc++.h>


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
        }
        b /=2;
        a*=a;
    }
    return ans;
}

lli DFS(vector< vector<lli> > g, lli top, vector <lli> col, stack <lli> s2)
{
    col[top] = 1;
    lli size = g[top].size();
    for(int i = 0; i<size; i++)
    {
        if(col[g[top][i]] == 0)
        {
            col[g[top][i]] = 1;
            DFS(g,g[top][i],col,s2);
        }
    }
    s2.push(top);
}


lli ans1 = 1;
lli mincost = 0;
lli mini = INT_MAX;
lli num = 0;
vector <lli> c;

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // An array of adjacency lists

    // Fills Stack with vertices (in increasing order of finishing
    // times). The top element of stack has the maximum finishing
    // time
    void fillOrder(int v, bool visited[], stack<int> &Stack);

    // A recursive function to print DFS starting from v
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);

    // The main function that finds and prints strongly connected
    // components
    void printSCCs();

    // Function that returns reverse (or transpose) of this graph
    Graph getTranspose();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    if(c[v] < mini)
    {
        num = 1;
        mini = c[v];
    }
    else if(c[v] == mini)
    {
        num++;
    }
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited and print it
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            fillOrder(*i, visited, Stack);

    // All vertices reachable from v are processed by now, push v
    Stack.push(v);
}

// The main function that finds and prints all strongly connected
// components
void Graph::printSCCs()
{
    stack<int> Stack;

    // Mark all the vertices as not visited (For first DFS)
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Fill vertices in stack according to their finishing times
    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            fillOrder(i, visited, Stack);

    // Create a reversed graph
    Graph gr = getTranspose();

    // Mark all the vertices as not visited (For second DFS)
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false)
    {
        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();
        mini = INT_MAX;
        num = 0;
        // Print Strongly connected component of the popped vertex
        if (visited[v] == false)
        {
            gr.DFSUtil(v, visited);
            mincost += mini;
            ans1 = (num*ans1)%(1000000007);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli a,b;
    cin >> a >> b;
    vector <lli> arr(10,0),brr,crr(10,0);
    vector <lli> e;
    while(a > 0)
    {
        arr[a%10]++;
        e.push_back(a%10);
        a/=10;
    }
    brr = arr;
    vector <lli> c;
    while(b > 0)
    {
        crr[b%10]++;
        c.push_back(b%10);
        b/=10;
    }
    lli n1 = c.size(),n2 = e.size();
    if(n2 < n1)
    {
        for(int i = 9; i>=0; i--)
        {
            while(arr[i] != 0)
            {
                cout << i;
                arr[i]--;
            }
        }
        return 0;
    }
    else
    {
        int flag = 0;
        for(int i = 0; i<10; i++)
        {
            //cout << e[i] << " " << c[i] << endl;
            if(arr[i] != crr[i])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            //cout << "here\n";
            for(int i = n1-1; i>=0; i--)
            {
                cout << c[i];
            }
            return 0;
        }
        else
        {
            lli m = -1;
            for(int i = n1-1; i>=0; i--)
            {
                arr = brr;
                //cout << "if " << i <<"th position differs\n";
                int flag1 = 0;
                lli temp = 0;
                for(int j = n1-1; j>i ; j--)
                {
                    if(arr[c[j]] != 0)
                    {
                        temp *= 10;
                        temp += c[j];
                        arr[c[j]]--;

                    }
                    else
                    {
                        flag1 = 1;
                        break;
                    }
                }
                if(flag1 == 1)
                {
                    //cout << "not possible\n\n\n";
                    continue;
                }
                else
                {
                    //cout << "temp after giving same " << temp << endl;
                    int flag2 = 0;
                    for(int j = c[i]-1; j>=0; j--)
                    {
                        if(arr[j] != 0)
                        {
                            temp *= 10;
                            temp += j;
                            arr[j]--;
                            flag2 = 1;
                            break;
                        }
                    }
                    //cout << "temp after assigning less " << temp << endl;
                    if(flag2 == 0)
                    {
                        continue;
                    }
                    int flag3 = 0;
                    for(int j = i-1; j>=0; j--)
                    {
                        flag2 = 0;
                        for(int k = 9; k>=0; k--)
                        {
                            if(arr[k] != 0)
                            {
                                temp*=10;
                                temp += k;
                                arr[k]--;
                                flag2 = 1;
                                break;
                            }
                        }
                        if(flag2 == 0)
                        {
                            flag3 = 1;
                            break;
                        }
                    }
                    if(flag3 == 1)
                    {
                        continue;
                    }
                    else
                    {
                        //cout << "final temp " << temp << endl << endl << endl;
                        if(temp > m)
                        {
                            m = temp;
                        }
                    }
                }
            }
            cout << m << endl;
        }
    }
}
