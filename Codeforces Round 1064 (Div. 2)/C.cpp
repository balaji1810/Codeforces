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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll sum = 0;
    ll mx = 0;
    for (int i = 0; i < n; ++i) {
        ll nxt = a[(i+1)%n];
        ll w = max(a[i], nxt);
        sum += w;
        mx = max(mx, w);
    }
    cout << (sum - mx) << '\n';
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