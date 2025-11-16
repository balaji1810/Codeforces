// https://codeforces.com/contest/2149/problem/D
// D. A and B

#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
#define INF LLONG_MAX

int costInMiddle(vector<int> &pos, int avg) {
    int numLessThanAvg = 0;
    for(int p : pos) {
        if(p < avg) numLessThanAvg++;
    }
    int n = pos.size();
    int cost = 0;
    for(int i = 0; i < n; i++)
        cost += abs(pos[i] - (avg - (numLessThanAvg - i)));
    return cost;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if(n == 1 || n == 2) {
        cout << 0 << nl;
        return;
    }
    vector<int> posA, posB;
    double avgA = 0, avgB = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') {
            posA.pb(i);
        } else {
            posB.pb(i);
        }
    }
    if(posA.size() == 0 || posB.size() == 0) {
        cout << 0 << nl;
        return;
    }
    // avgA = ceil(avgA / posA.size());
    // avgB = ceil(avgB / posB.size());
    // avgA = (int)posA.size() / 2;
    // avgB = (int)posB.size() / 2;
    avgA = ceil((double)posA.size() / 2);
    avgB = ceil((double)posB.size() / 2);
    int costAa = costInMiddle(posA, 0);
    int costBb = costInMiddle(posB, 0);
    int costBaB = costInMiddle(posA, avgA);
    int costAbA = costInMiddle(posB, avgB);
    cout << min({costBaB, costAbA, costAa, costBb}) << nl;
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
