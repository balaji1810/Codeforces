#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
#define INF LLONG_MAX

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool anyZero = false;
    for (char c : s)
        if (c == '0') {
            anyZero = true;
            break;
        }
    if (!anyZero) {
        cout << 0 << nl;
        return;
    }
    vector<int> dist(n, INT_MAX);
    int last = INT_MIN;
    for (int i = 0; i < 2 * n; ++i) {
        int idx = i % n;
        if (s[idx] == '1') {
            last = i;
        } else {
            if (last > INT_MIN) {
                dist[idx] = min(dist[idx], i - last);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            ans = max(ans, dist[i]);
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}