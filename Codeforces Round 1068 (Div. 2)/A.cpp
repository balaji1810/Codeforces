#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
#define INF LLONG_MAX

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int awake_until = -1;
    int sleep_count = 0;
    for (int i = 0; i < n; ++i) {
        if (i <= awake_until) {
            if (s[i] == '1') {
                awake_until = max(awake_until, min(n - 1, i + k));
            }
        } else {
            if (s[i] == '1') {
                awake_until = min(n - 1, i + k);
            } else {
                sleep_count++;
            }
        }
    }
    cout << sleep_count << nl;
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