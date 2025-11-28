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
    ll s = 0;
    int zeros = 0;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        s += x;
        if (x == 0) zeros++;
    }
    ll cnt_nonzero = n - zeros;
    ll max_by_sum = s - (n - 1);
    ll ans = min<ll>(cnt_nonzero, max_by_sum);
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