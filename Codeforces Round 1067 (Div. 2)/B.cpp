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
    int len = 2 * n;
    unordered_map<int,int> cnt;
    for (int i = 0; i < len; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int oddCount = 0;
    for (auto &p : cnt)
        if (p.second % 2 == 1)
            oddCount++;
    int distinct = (int)cnt.size();
    int evenCount = distinct - oddCount;
    int rem = min(evenCount, n);
    if ((n - rem) % 2  != 0) {
        if (oddCount == 0 || rem == n) {
            rem--;
        }
    }
    if (rem < 0) rem = 0;
    int ans = oddCount + 2 * rem;
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