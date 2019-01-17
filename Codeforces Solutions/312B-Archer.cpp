#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <fstream>
#include <cmath>
#include <sstream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

struct compare
{
	bool operator()(int a, int b)
	{
		return a<b;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long double a,b,c,d,pra,prb,r;
	cin >> a >> b >> c >> d;
	pra = a/b;
	prb = c/d;
	r = (1.00000-a/b)*(1.00000-c/d);
	cout << pra*(1/(1-r)) << endl;
}

