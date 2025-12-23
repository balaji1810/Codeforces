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

    vector<ll> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    ll answer = 0;
    int i = 0;

    while (i < n) {
        ll prev = 0;
        ll lo = 0, hi = INF;
        ll bestOdd = 0, bestEven = INF;
        bool parityOdd = true;

        i++;

        while (i < n) {
            ll gap = x[i] - x[i - 1];
            ll cur = gap - prev;

            bool nextParityOdd = !parityOdd;
            ll newLo = lo, newHi = hi;
            if (nextParityOdd) {
                newLo = max(newLo, -cur);
            } else {
                newHi = min(newHi, cur);
            }

            if (newLo >= newHi) break;

            ll extra = 0;
            ll prevBest = nextParityOdd ? bestOdd : bestEven;
            if (prevBest < INF) {
                extra = max<ll>(0, cur - prevBest);
            }

            bool canExtend = true;
            if (i + 1 < n) {
                ll nextGap = x[i + 1] - x[i];
                if (extra >= nextGap) {
                    canExtend = false;
                }
            }

            if (!canExtend) break;
            answer++;
            prev = cur;
            lo = newLo;
            hi = newHi;

            if (nextParityOdd) {
                bestOdd = min(bestOdd, cur);
            } else {
                bestEven = min(bestEven, cur);
            }

            parityOdd = nextParityOdd;
            i++;
        }
    }

    cout << answer << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
