#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        unsigned int x, y, z;
        cin >> x >> y >> z;

        bool ok = true;
        for (int i = 0; i < 32; ++i) {
            int xi = (x >> i) & 1;
            int yi = (y >> i) & 1;
            int zi = (z >> i) & 1;

            if ((xi == 0 && yi == 1 && zi == 1) ||
                (xi == 1 && yi == 0 && zi == 1) ||
                (xi == 1 && yi == 1 && zi == 0)) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
