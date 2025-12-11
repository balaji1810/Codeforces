#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
#define INF LLONG_MAX
#define NEG_INF LLONG_MIN

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    ll min_pos = 0, max_pos = 0;
    bool have_pos = true;
    ll min_neg = 0, max_neg = 0;
    bool have_neg = false;
    for (int i = 0; i < n; ++i) {
        ll ai = a[i], bi = b[i];
        vector<ll> min_pos_cands, max_pos_cands;
        if (have_pos) {
            min_pos_cands.pb(min_pos - ai);
            max_pos_cands.pb(max_pos - ai);
        }
        if (have_neg) {
            min_pos_cands.pb(bi - max_neg);
            max_pos_cands.pb(bi - min_neg);
        }
        ll new_min_pos = 0, new_max_pos = 0;
        bool new_have_pos = false;
        if (!min_pos_cands.empty()) {
            new_have_pos = true;
            new_min_pos = *min_element(min_pos_cands.begin(), min_pos_cands.end());
            new_max_pos = *max_element(max_pos_cands.begin(), max_pos_cands.end());
        }
        vector<ll> min_neg_cands, max_neg_cands;
        if (have_neg) {
            min_neg_cands.pb(min_neg - ai);
            max_neg_cands.pb(max_neg - ai);
        }
        if (have_pos) {
            min_neg_cands.pb(bi - max_pos);
            max_neg_cands.pb(bi - min_pos);
        }
        ll new_min_neg = 0, new_max_neg = 0;
        bool new_have_neg = false;
        if (!min_neg_cands.empty()) {
            new_have_neg = true;
            new_min_neg = *min_element(min_neg_cands.begin(), min_neg_cands.end());
            new_max_neg = *max_element(max_neg_cands.begin(), max_neg_cands.end());
        }
        have_pos = new_have_pos;
        have_neg = new_have_neg;
        if (have_pos) { min_pos = new_min_pos; max_pos = new_max_pos; }
        if (have_neg) { min_neg = new_min_neg; max_neg = new_max_neg; }
    }
    ll ans = NEG_INF;
    if (have_pos) ans = max(ans, max_pos);
    if (have_neg) ans = max(ans, max_neg);
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