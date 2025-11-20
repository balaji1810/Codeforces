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
    char target = s[n-1];
    int ans = 0;
    for (int i = 0; i < n-1; ++i)
        if (s[i] != target) ++ans;
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
