// A. Circle of Apple Trees
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> S;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        S.insert(x);
    }
    // calculating the size of the set
    cout << S.size() << "\n";
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