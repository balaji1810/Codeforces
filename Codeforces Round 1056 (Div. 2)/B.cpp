// B. Abraham's Great Escape

#include<bits/stdc++.h>
using namespace std;

void solveEscape() {
    int n, k;
    cin >> n >> k;
    if(k == (n * n) - 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        bool ok = false;
        for(int j = 0; j < n; j++) {
            if(k > 0) {
                cout << "U";
                k--;
                ok = true;
            }
            else {
                if(ok && j==n-1) cout << "D";
                else if(j < n-1) cout << "R";
                else cout << "L";
                ok = false;
            }
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) solveEscape();

    return 0;
}