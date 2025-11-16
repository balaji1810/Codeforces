#include <bits/stdc++.h>
using namespace std;

void computePrefixSuffix(const vector<int>& u, const vector<int>& d, vector<int>& prefixMinimum, vector<int>& prefixMaximum, vector<int>& suffixMinimum, vector<int>& sufMaximum) {
    int n = u.size() - 1;
    for (int i = 1; i <= n; ++i) {
        prefixMinimum[i] = (i == 1) ? u[i] : min(prefixMinimum[i - 1], u[i]);
        prefixMaximum[i] = (i == 1) ? u[i] : max(prefixMaximum[i - 1], u[i]);
    }
    for (int i = n; i >= 1; --i) {
        suffixMinimum[i] = (i == n) ? d[i] : min(suffixMinimum[i + 1], d[i]);
        sufMaximum[i] = (i == n) ? d[i] : max(sufMaximum[i + 1], d[i]);
    }
}

long long calculateAnswer(int n, const vector<int>& prefMinimum, const vector<int>& prefixMaximum, const vector<int>& suffixMinimum, const vector<int>& sufMaximum) {
    int m = 2 * n;
    vector<vector<int>> byMin(m + 2);
    for (int t = 1; t <= n; ++t) {
        int mn = min(prefMinimum[t], suffixMinimum[t]);
        int mx = max(prefixMaximum[t], sufMaximum[t]);
        byMin[mn].push_back(mx);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    long long total = 0;
    for (int l = m; l >= 1; --l) {
        for (int x : byMin[l]) pq.push(x);
        if (!pq.empty()) {
            total += static_cast<long long>(m - pq.top() + 1);
        }
    }
    return total;
}

void solveTestCase() {
    int n;
    cin >> n;
    vector<int> u(n + 1), d(n + 1);
    for (int i = 1; i <= n; ++i) cin >> u[i];
    for (int i = 1; i <= n; ++i) cin >> d[i];

    vector<int> prefMinimum(n + 1), prefixMaximum(n + 1), suffixMinimum(n + 2), sufMaximum(n + 2);
    computePrefixSuffix(u, d, prefMinimum, prefixMaximum, suffixMinimum, sufMaximum);
    cout << calculateAnswer(n, prefMinimum, prefixMaximum, suffixMinimum, sufMaximum) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solveTestCase();
    }
    return 0;
}