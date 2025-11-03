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
    string s, t;

    cin >> n >> s >> t;
    vector<int> counts(26, 0);

	for (int i = 0; i < n; i++)
		counts[s[i] - 'a']++;
    for(auto c : t) {
        if(counts[c - 'a']) {
            counts[c - 'a']--;
        } else {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
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