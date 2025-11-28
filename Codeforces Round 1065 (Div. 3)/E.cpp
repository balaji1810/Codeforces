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

    vector<int> div6, div3, evenNot3, oddNot;
    for (int x = 1; x <= n; ++x) {
        if (x % 6 == 0) div6.pb(x);
        else if (x % 3 == 0) div3.pb(x);
        else if (x % 2 == 0) evenNot3.pb(x);
        else oddNot.pb(x);
    }

    vector<int> s;
    s.insert(s.end(), div3.begin(), div3.end());
    s.insert(s.end(), div6.begin(), div6.end());
    s.insert(s.end(), evenNot3.begin(), evenNot3.end());

    vector<int> result;
    size_t sp = 0, wp = 0;

    while (sp + 1 < s.size() && wp < oddNot.size()) {
        result.pb(s[sp++]);
        result.pb(s[sp++]);
        result.pb(oddNot[wp++]);
    }

    while (sp < s.size()) result.pb(s[sp++]);
    while (wp < oddNot.size()) result.pb(oddNot[wp++]);

    if ((int)result.size() < n) {
        vector<char> seen(n+1, 0);
        for (int v : result) seen[v] = 1;
        for (int x = 1; x <= n; ++x) if (!seen[x]) result.pb(x);
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << result[i];
    }
    cout << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
