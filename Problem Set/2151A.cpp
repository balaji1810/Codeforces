// https://codeforces.com/problemset/problem/2151/A
// A. Incremental Subarray

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll n, m;
    cin >> n >> m;
    ll a[m];
    for(ll i = 0; i < m; i++) cin >> a[i];
    if(m == 1 || (a[0] < a[m-1] && m <= a[m-1])) {
        cout << n - a[m-1] + 1 << "\n";
        return;
    }
    else {
        cout << 1 << "\n";
        return;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}