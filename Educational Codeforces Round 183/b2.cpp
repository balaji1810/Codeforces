#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
void solve() {
int n, k;
std::cin >> n >> k;
std::string s;
std::cin >> s;
int c0 = 0;
int c1 = 0;
for (char ch : s) {
if (ch == '0') c0++;
else if (ch == '1') c1++;
}
int c2 = k - c0 - c1;
std::string ans(n, '?');
for (int i = 0; i < c0; ++i) {
ans[i]
}
for (int i = n 1; i >= n - c1; --i) {
ans[i]
}
int n prime n - co - c1;
int k prime c2;
if (n_prime > 0 && n_prime == k_prime) {
for (int i = 0; i <= n c1 1; ++i) {
ans[i]
}
}else if (n_prime > k_prime) {
int start idx co+k_prime;
int end idx = n c1 c2 - 1;
for (int i = start_idx; i <= end_idx; ++i) {
ans[i] '+';
}
}
std::cout << ans << "\n";
}
int main() {
std::ios_base::sync_with_stdio(false);
std::cin. tie(NULL);
int t;
std::cin >> t;
while (t--) {
solve();
}
return 0;
}