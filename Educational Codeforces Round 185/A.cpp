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
    if(n == 1)
        cout << 1 << nl;
    else if(n == 2)
        cout << 9 << nl;
    else if(n == 3)
        cout << 29 << nl;
    else if(n == 4)
        cout << 56 << nl;
    else
        cout << 5 * (n*n - n - 1) << nl;
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