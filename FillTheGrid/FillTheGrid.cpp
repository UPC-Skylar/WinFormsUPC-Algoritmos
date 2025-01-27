// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int solve(){
    int n, m; cin >> n >> m;
    if(n % 2 == 0 && m  % 2 == 0) return 0;
    if(n % 2 != 0 && m % 2 != 0) return (m + n - 1);
    else return ((n % 2 == 0) ? n : m);
}

int main() {
	int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}
