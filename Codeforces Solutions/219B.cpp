#include <iostream>
using namespace std;
int main(){

    long long int ip, max;
    cin >> ip >> max;
    long long int x = 10;
    long long int ans = ip;
    while(true)
    {
        long long int can = ip % x;
        if((can+1)%x > max)
        {
        	break;
        }
        ans = ip-((can+1)%x);
        x *= 10;
    }
    cout << ans << endl;
}