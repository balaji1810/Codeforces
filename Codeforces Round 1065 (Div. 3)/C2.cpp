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
    vector<int> a(n), b(n);
    for(int i=0;i<n;++i)
        cin >> a[i];
    for(int i=0;i<n;++i)
        cin >> b[i];
    int A = 0, B = 0;
    for(int x : a)
        A ^= x;
    for(int x : b)
        B ^= x;
    int X = A ^ B;
    if(X == 0) {
        cout << "Tie" << nl;
        return;
    }
    int h = 31 - __builtin_clz(X);
    int last = -1;
    for(int i = n-1; i >= 0; --i) {
        int d = a[i] ^ b[i];
        if( (d >> h) & 1 ) { last = i+1; break; }
    }
    if(last != -1) {
        if(last % 2 == 1) cout << "Ajisai" << nl;
        else cout << "Mai" << nl;
    } else {
        if( ((A >> h) & 1) ) cout << "Ajisai" << nl;
        else cout << "Mai" << nl;
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