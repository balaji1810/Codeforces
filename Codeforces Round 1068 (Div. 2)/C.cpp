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
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int U = a.size();
    unordered_map<ll, vector<ll>> mults;
    // mults.reserve(U * 2);
    for (ll v : a) {
        for (ll d = 1; d * d <= v; ++d) {
            if (v % d == 0) {
                mults[d].pb(v);
                ll d2 = v / d;
                if (d2 != d) mults[d2].pb(v);
            }
        }
    }
    vector<ll> candidates;
    candidates.reserve(mults.size());
    for (auto &p : mults) {
        ll d = p.first;
        ll needed = k / d;
        auto &vec = p.second;
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        if ((ll)vec.size() == needed) {
            candidates.pb(d);
        }
    }
    sort(candidates.begin(), candidates.end());
    unordered_set<ll> covered;
    // covered.reserve(U * 2);
    vector<ll> answer;
    for (ll d : candidates) {
        auto &vec = mults[d];
        bool any_uncovered = false;
        for (ll v : vec)
            if (!covered.count(v)) {
                any_uncovered = true;
                break;
            }
        if (any_uncovered) {
            answer.pb(d);
            for (ll v : vec)
                covered.insert(v);
        }
    }
    bool ok = true;
    for (ll v : a)
        if (!covered.count(v)) {
            ok = false;
            break;
        }
    if (!ok) {
        cout << -1 << nl;
    } else {
        cout << answer.size() << nl;
        for (int i = 0; i < answer.size(); i++) {
            if (i) cout << ' ';
            cout << answer[i];
        }
        cout << nl;
    }
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