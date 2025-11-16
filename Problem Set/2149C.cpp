// https://codeforces.com/contest/2149/problem/C
// C. MEX rose
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
    cin >> n >> k;
    int countUnique = 0, countK = 0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(s.find(a) == s.end() && a < k) countUnique++;
        s.insert(a);
        if(a == k) countK++;
    }
    int diff = k - countUnique;
    cout << max(diff, countK) << nl;
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