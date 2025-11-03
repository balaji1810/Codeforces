// https://codeforces.com/contest/2147/problem/A
// A. Shortest Increasing Path
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, diff, div, step1;
    cin >> t;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        if(y > x) cout<<2<<endl;
        else if( y >= 2 && x - y >= 2) cout<<3<<endl;
        else {
            cout<<-1<<endl;
        }
        
    }
    return 0;
}
