// https://codeforces.com/problemset/problem/2152/A
// A. Increase or Smash

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    set<int > s;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size() * 2 - 1 << "\n";
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