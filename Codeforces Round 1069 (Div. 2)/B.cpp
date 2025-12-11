#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
#define INF LLONG_MAX

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> p(n+1);
    for (int i = 0; i <= n; ++i)
        p[i] = i;
    p[r] = l - 1;
    for (int i = 1; i <= n; ++i) {
        int ai = p[i-1] ^ p[i];
        cout << ai << ' ';
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
    return 0;
}