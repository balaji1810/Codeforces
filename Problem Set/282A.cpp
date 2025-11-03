// https://codeforces.com/problemset/problem/282/A
// A. Bit++

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, x = 0;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        
        for (char c : s) {
            if (c == '+') {
                x++;
                break;
            }
            else if(c == '-') {
                x--;
                break;
            }
            else {
                continue;
            }
        }
    }
    cout << x << "\n";
}