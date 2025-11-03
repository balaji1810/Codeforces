// A. Way Too Long Words
// https://codeforces.com/problemset/problem/71/A
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    if (s.length() > 10) {
        cout << s[0] << s.length() - 2 << s.back() << "\n";
    } else {
        cout << s << "\n";
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