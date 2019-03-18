#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() 
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int temp = s.size();
    if(k>temp)
    {
        cout << "impossible\n";
    }
    else
    {
        set <char> st;
        for(int i = 0; i<temp; i++)
        {
            st.insert(s[i]);
        }
        if(st.size() >= k)
        {
            cout << 0;
            return 0;
        }
        cout << k-st.size() << endl;
    }
}