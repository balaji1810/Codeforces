// B. Deck of Cards
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN=1e6+5, inf=1e16;

ll t, n, k, topOp, bottomOp, bothOp;

void solveDeck() {
    cin >> n >> k;
    string s;
    cin >> s;
    
    if(k == n) {
        for(ll i = 0; i < n; i++)
            cout << '-';
        return;
    }
    topOp = bottomOp = bothOp = 0;
    for(auto c : s) {
        if(c == '0') topOp++;
        else if(c == '1') bottomOp++;
        else bothOp++;
    }
    
    for(ll i = 0; i < n; i++) {
        if(i < topOp || i >= n - bottomOp) cout << '-';
        else if(i < topOp + bothOp || i >= n - bothOp - bottomOp) cout << '?';
        else cout << '+';
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        solveDeck();
        cout << endl;
    }
    return 0;
}