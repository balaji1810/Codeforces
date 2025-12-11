

#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
#define INF LLONG_MAX

void solve() {
    string s, t;
    cin >> s >> t;
    vector<int> cnt(26,0);
    for(char ch: t) cnt[ch-'a']++;
    for(char ch: s) cnt[ch-'a']--;
    for(int x: cnt) if (x < 0) {
        cout << "Impossible" << nl;
        return;
    }

    string r;
    r.reserve(t.size());
    for(int i=0;i<26;++i) if (cnt[i] > 0) r.append(cnt[i], char('a'+i));

    char c = s[0];
    int pos1 = r.size(), pos2 = r.size();
    for (int i = 0; i < (int)r.size(); ++i) {
        if (r[i] >= c) { pos1 = i; break; }
    }
    for (int i = 0; i < (int)r.size(); ++i) {
        if (r[i] > c) { pos2 = i; break; }
    }
    string cand1 = r.substr(0,pos1) + s + r.substr(pos1);
    string cand2 = r.substr(0,pos2) + s + r.substr(pos2);
    cout << min(cand1, cand2) << nl;
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