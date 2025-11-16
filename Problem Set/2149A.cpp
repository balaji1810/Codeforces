// https://codeforces.com/contest/2149/problem/A
// A. Be Positive
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
    vector<int> a(n);
    int zeros = 0, ones = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) zeros++;
        else if(a[i] == -1) ones++;
    }
    if(ones % 2 == 1) {
        cout << zeros + 2 << nl;
    } else {
        cout << zeros << nl;
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
}