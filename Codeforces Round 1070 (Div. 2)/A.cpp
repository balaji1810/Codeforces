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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n <= 1) {
        cout << 0 << nl;
        return;
    }
    int mx = a[0];
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < mx) {
            ++ans;
        } else if (a[i] > mx) {
            mx = a[i];
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