// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void solve(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j + 1 + i + 1 >= n + 1) cout << "#";
            else cout << " ";
        }
        cout << endl;
    }
}

int main() {
	int n; cin >> n;
    solve(n);
}
