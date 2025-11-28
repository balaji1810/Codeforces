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
    ll k;
    cin >> n >> k;
    vector<ll> q(n);
    for (int i = 0; i < n; i++) cin >> q[i];
    vector<ll> r(n);
    for (int i = 0; i < n; i++) cin >> r[i];
    sort(q.begin(), q.end());
    vector<ll> limits;
    limits.reserve(n);
    for (int i = 0; i < n; i++) {
        if (r[i] >= k) continue;
        ll L = (k - r[i]) / (r[i] + 1);
        if (L >= 1) limits.push_back(L);
    }
    sort(limits.begin(), limits.end());
    priority_queue<ll> pq;
    int j = 0;
    int matches = 0;
    for (ll L : limits) {
        while (j < n && q[j] <= L) {
            pq.push(q[j]);
            j++;
        }
        if (!pq.empty()) {
            pq.pop();
            matches++;
        }
    }
    cout << matches << nl;
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