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
    unordered_set<int> S;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        S.insert(x);
    }
    while(true) {
        int m = S.size();
        if(S.count(m)) {
            cout << m << nl;
            break;
        }
        S.insert(m);
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