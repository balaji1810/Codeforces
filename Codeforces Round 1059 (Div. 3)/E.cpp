#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
#define INF LLONG_MAX

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> present(n+1, 0);
    for (int x : a) if (1 <= x && x <= n) present[x] = 1;
    vector<int> ans;
    for (int v = 1; v <= n && (int)ans.size() < k; ++v)
        if (!present[v]) ans.push_back(v);
    for (int v = 1; (int)ans.size() < k; ++v) {
        int val = ((v-1) % n) + 1;
        ans.push_back(val);
    }
    for (int i = 0; i < (int)ans.size(); ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << nl;
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