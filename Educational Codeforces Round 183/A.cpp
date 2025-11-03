// A. Candies for Nephews
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int mod = n % 3;
    if (mod == 0) cout << 0 << endl;
    else cout << 3 - mod << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}