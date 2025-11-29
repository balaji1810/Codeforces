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
    int y, r;
    cin >> y >> r;
    int by_red = r;
    int remaining_players = n - by_red;
    int by_yellow = min(y / 2, max(0, remaining_players));
    cout << by_red + by_yellow << nl;
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