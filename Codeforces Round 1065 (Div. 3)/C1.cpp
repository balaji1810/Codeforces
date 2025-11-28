#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
#define INF LLONG_MAX

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    int S = 0;
    int last = -1;
    for(int i = 0; i < n; ++i) {
        int d = a[i] ^ b[i];
        S ^= d;
        if(d) last = i + 1;
    }
    if(S == 0) {
        cout << "Tie" << nl;
    } else {
        if(last % 2 == 1) cout << "Ajisai" << nl;
        else cout << "Mai" << nl;
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