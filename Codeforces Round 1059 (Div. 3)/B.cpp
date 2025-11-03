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
    string s;
    cin >> n >> s;
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') pos.pb(i+1);
    }
    cout << pos.size() << nl;
    if (!pos.empty()) {
        for (int i = 0; i < (int)pos.size(); ++i) {
            if (i) cout << ' ';
            cout << pos[i];
        }
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