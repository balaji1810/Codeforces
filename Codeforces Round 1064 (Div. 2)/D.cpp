#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
#define INF LLONG_MAX

const int MOD = 998244353;

int addmod(int a, int b) {
    a += b;
    if(a >= MOD) a -= MOD;
    return a;
}

int mulmod(ll a, ll b) {
    return int((a * b) % MOD);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i < n; i++) cin >> a[i];

    vector<int> freq(n+1,0);
    for(int x: a) freq[x]++;

    vector<int> cnt(n);
    int M = 0;
    int total = 0;
    for(int v = 1; v <= n; v++) {
        if(freq[v] > 0) {
            cnt.pb(freq[v]);
            M = max(M, freq[v]);
            total += freq[v];
        }
    }

    vector<int> dp(total + 1, 0);
    dp[0] = 1;
    for(int c: cnt) {
        for(int s = total - c; s >= 0; s--) {
            if(dp[s]==0) continue;
            int add = mulmod(dp[s], c);
            dp[s + c] = addmod(dp[s + c], add);
        }
    }
    int ans = 0;
    for(int s = M; s <= total; s++) {
        ans = addmod(ans, dp[s]);
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
