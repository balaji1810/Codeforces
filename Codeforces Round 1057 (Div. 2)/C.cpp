#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end(), greater<ll>());

        vector<pair<ll,int>> freq;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && a[j] == a[i]) ++j;
            freq.push_back({a[i], j - i});
            i = j;
        }

        vector<ll> pairs;
        vector<ll> singles;
        for (auto &pr : freq) {
            ll L = pr.first;
            int cnt = pr.second;
            int p = cnt / 2;
            for (int k = 0; k < p; ++k) pairs.push_back(L);
            if (cnt % 2 == 1) singles.push_back(L);
        }

        sort(pairs.begin(), pairs.end(), greater<ll>());
        sort(singles.begin(), singles.end(), greater<ll>());

        int m = (int)pairs.size();
        vector<ll> pref(m+1,0);
        for (int i = 0; i < m; ++i) pref[i+1] = pref[i] + pairs[i];

        ll best = 0;

        auto valid = [](ll total, ll largest) {
            return (2 * largest < total);
        };

        for (int d = 0; d <= m; ++d) {
            int cp = m - d;
            ll sumPairs = pref[m] - pref[d]; // sum of pair lengths (each pair contributes length L; total side-sum contributed by those pairs is 2*sumPairs)

            if (cp >= 2) {
                ll largestPair = pairs[d]; // because pairs sorted descending and we have at least two
                if (sumPairs > largestPair) {
                    ll per = 2 * sumPairs;
                    best = max(best, per);
                }
            }
            struct Cand { ll val; bool breaksSelected; };
            vector<Cand> cand;
            if (!singles.empty()) cand.push_back({singles[0], false});
            if (singles.size() >= 2) cand.push_back({singles[1], false});
            if (d > 0) cand.push_back({pairs[d-1], false}); // break unselected pair -> doesn't reduce sumPairs
            if (cp > 0) cand.push_back({pairs[m-1], true});  // break smallest selected pair -> reduces sumPairs

            int C = (int)cand.size();
            for (int i = 0; i < C; ++i) {
                ll singleVal = cand[i].val;
                ll brokenSum = cand[i].breaksSelected ? cand[i].val : 0;
                int brokenCnt = cand[i].breaksSelected ? 1 : 0;
                ll sumPairs2 = sumPairs - brokenSum;
                int cp2 = cp - brokenCnt;
                if (cp2 >= 1) {
                    ll total = 2 * sumPairs2 + singleVal;
                    ll largest = singleVal;
                    if (cp2 > 0) largest = max(largest, pairs[d + ( (cand[i].breaksSelected && (m-1==d) ) ? 1 : 0 )]);
                    bool brokeLargest = false;
                    if (cand[i].breaksSelected) {
                    }
                    ll largestPairAfter = 0;
                    if (cp2 > 0) {
                        if (cand[i].breaksSelected && (m-1 >= d)) {
                            
                            if (d == m-1) {
                                largestPairAfter = 0;
                            } else {
                                largestPairAfter = pairs[d];
                            }
                        } else {
                            largestPairAfter = pairs[d];
                        }
                        largest = max(singleVal, largestPairAfter);
                    } else {
                        largest = singleVal;
                    }

                    if (valid(total, largest)) {
                        best = max(best, total);
                    }
                }
            }

            for (int i = 0; i < C; ++i) for (int j = i+1; j < C; ++j) {
                ll c1 = cand[i].val, c2 = cand[j].val;
                int brokenCnt = (cand[i].breaksSelected ? 1 : 0) + (cand[j].breaksSelected ? 1 : 0);
                ll brokenSum = (cand[i].breaksSelected ? cand[i].val : 0) + (cand[j].breaksSelected ? cand[j].val : 0);
                ll sumPairs2 = sumPairs - brokenSum;
                int cp2 = cp - brokenCnt;
                if (cp2 >= 1) {
                    ll total = 2 * sumPairs2 + c1 + c2;
                    ll largestPairAfter = 0;
                    if (cp2 > 0) {
                        largestPairAfter = pairs[d];
                    }
                    ll largest = max({c1, c2, largestPairAfter});
                    if (valid(total, largest)) {
                        best = max(best, total);
                    }
                }
            }
        }

        cout << best << "\n";
    }
    return 0;
}
