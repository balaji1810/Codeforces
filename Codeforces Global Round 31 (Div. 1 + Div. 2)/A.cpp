#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
#define INF LLONG_MAX

void solve() {
    int l, a, b;
    cin >> l >> a >> b;
    int i = 0, ans = INT_MIN;
    set<int> s;
    for(int i = 0; i < l; i++) {
        ans = max(ans, (a + i * b) % l);
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