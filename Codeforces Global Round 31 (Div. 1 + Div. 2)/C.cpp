#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
#define INF LLONG_MAX
#define NEG LLONG_MIN

int L = 31;
int n_global;
ll memo[35][2][2];
int choice_bit[35][2][2];
bool seen[35][2][2];

ll dfs(int pos, int ta, int tb) {
    if (pos < 0) return 0;
    if (seen[pos][ta][tb]) return memo[pos][ta][tb];
    seen[pos][ta][tb] = true;
    ll best = NEG;
    int nbit = (n_global >> pos) & 1;
    for (int abit = 0; abit <= 1; ++abit) {
        int bbit = abit ^ nbit;
        if (ta && abit > nbit) continue;
        if (tb && bbit > nbit) continue;
        int nta = ta && (abit == nbit);
        int ntb = tb && (bbit == nbit);
        ll add = ( (ll)(abit + bbit) << pos );
        ll val = dfs(pos - 1, nta, ntb);
        if (val == NEG) continue;
        val += add;
        if (val > best) {
            best = val;
            choice_bit[pos][ta][tb] = abit;
        }
    }
    memo[pos][ta][tb] = best;
    return best;
}

pair<ll,ll> best_pair(int n) {
    n_global = n;
    for (int i = 0; i < L; ++i)
        for (int a = 0; a < 2; ++a)
            for (int b = 0; b < 2; ++b) {
                seen[i][a][b] = false;
                memo[i][a][b] = NEG;
                choice_bit[i][a][b] = 0;
            }
    ll bestSum = dfs(L - 1, 1, 1);
    int ta = 1, tb = 1;
    ll a = 0, b = 0;
    for (int pos = L - 1; pos >= 0; --pos) {
        if (!seen[pos][ta][tb]) {
            break;
        }
        int abit = choice_bit[pos][ta][tb];
        int nbit = (n >> pos) & 1;
        int bbit = abit ^ nbit;
        if (abit) a |= (1 << pos);
        if (bbit) b |= (1 << pos);
        int nta = ta && (abit == nbit);
        int ntb = tb && (bbit == nbit);
        ta = nta; tb = ntb;
    }
    return {a, b};
}

void solve() {
    int n; int k;
    cin >> n >> k;
    if (k % 2 == 1) {
        for (int i = 0; i < k; ++i) {
            if (i) cout << ' ';
            cout << n;
        }
        cout << nl;
        return;
    }
    if (k == 2) {
        auto p = best_pair(n);
        cout << p.first << ' ' << p.second << nl;
        return;
    }
    auto p = best_pair(n);
    ll pairSum = p.first + p.second;
    if (pairSum > n) {
        for (int i = 0; i < k - 2; ++i) {
            cout << n << ' ';
        }
        cout << p.first << ' ' << p.second << nl;
    } else {
        for (int i = 0; i < k - 1; ++i) {
            if (i) cout << ' ';
            cout << n;
        }
        cout << ' ' << 0 << nl;
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
