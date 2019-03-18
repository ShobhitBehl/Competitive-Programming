#include <iostream>
using namespace std;

int main() {
    long long int n, i;
    cin>>n;
    for(i=1;i<=n/2;i++){
        cout<<i<<" "<<n-i+1<<" ";
    }
    if(n%2!=0){
        cout<<n/2+1;
    }
}