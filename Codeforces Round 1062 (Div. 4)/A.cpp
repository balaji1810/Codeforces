#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a != b || b != c || c != d) {
        cout << "No" << nl;
    } else {
        cout << "Yes" << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}