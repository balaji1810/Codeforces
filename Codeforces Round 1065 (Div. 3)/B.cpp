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
    vector<int> a(n);
    for(int i=0;i<n;++i) cin >> a[i];
    if(a[0] == -1 && a[n-1] == -1) {
        a[0] = 0;
        a[n-1] = 0;
    } else if(a[0] == -1) {
        a[0] = a[n-1];
    } else if(a[n-1] == -1) {
        a[n-1] = a[0];
    }
    for(int i=1;i<n-1;++i) if(a[i] == -1) a[i] = 0;
    long long ans = llabs(1LL * a[n-1] - 1LL * a[0]);
    cout << ans << nl;
    for(int i=0;i<n;++i) {
        if(i) cout << ' ';
        cout << a[i];
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