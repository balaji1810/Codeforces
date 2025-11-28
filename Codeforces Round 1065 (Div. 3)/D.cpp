#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
#define INF LLONG_MAX

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll cur_min = INF;
    bool ans = true;
    for (int i = 0; i < n - 1; i++) {
        cur_min = min(cur_min, v[i]);
        if (cur_min == n - (ll)i) {
            ans = false;
            break;
        }
    }
    if(ans)
        cout << "Yes" << nl;
    else
        cout << "No" << nl;
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