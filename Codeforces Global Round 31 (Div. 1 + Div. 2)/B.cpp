#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define pf push_front
#define _ << ' ' <<
#define INF LLONG_MAX

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    string s = "";
    for (int i = 0; i < n; i++) {
        string front = a[i] + s;
        string back = s + a[i];
        if (front < back) {
            s = front;
        } else {
            s = back;
        }
    }
    
    cout << s << nl;
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