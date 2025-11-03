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
    vector<ll> a(n);
    bool hasEven = false, hasOdd = false;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) hasEven = true;
        else hasOdd = true;
    }
    if (hasEven && hasOdd) sort(a.begin(), a.end());
    for(int i = 0; i < n; ++i) {
        if (i) cout << ' ';
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
}