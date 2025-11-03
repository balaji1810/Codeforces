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
    vector<int> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    cout << *max_element(a.begin(), a.end()) << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}