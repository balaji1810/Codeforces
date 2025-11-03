#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"
#define _ << ' ' <<

void solve() {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << 0 << nl;
        }
        else if(__builtin_clz(a) > __builtin_clz(b)) {
            cout << -1 << nl;
        }
        else if(__builtin_clz(a) == __builtin_clz(b)) {
            cout << 1 << nl;
            cout << (b ^ a) << nl;
        }
        else {
            cout << 2 << nl;
            int c = 1 << (31 - __builtin_clz(a));
            cout << (a ^ b ^ c) _ c << nl;
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