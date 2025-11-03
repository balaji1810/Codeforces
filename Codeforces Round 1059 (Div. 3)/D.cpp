#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
#define INF LLONG_MAX
#define fl flush

ll query(int q, int l, int r) {
    ll res;
    cout << q _ l _ r << fl << nl;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    int diff = query(2, 1, n) - n*(n+1)/2;

    int l = 1, r = n;

    ll x, y;
    while(l < r) {
        int mid = (l + r) / 2;
        x = query(1, l, mid);
        y = query(2, l, mid);
        if(y > x) 
            r = mid;
        else
            l = mid + 1;
    }
    cout << "!" _ l _ l + diff - 1 << fl << nl;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}