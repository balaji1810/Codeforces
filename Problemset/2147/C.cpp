// https://codeforces.com/contest/2147/problem/C
// C. Rabbits
#include <bits/stdc++.h>
#include <bit>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf push_front
#define _ << ' ' <<
#define all(x) (x).begin(), (x).end()

const ll INF = LLONG_MAX;
const int INF_INT = INT_MAX;

#ifdef LOCAL
  #define debug(...) (cerr << "[DEBUG] ", _dbg(#__VA_ARGS__, __VA_ARGS__), cerr << '\n')
  template<class T> void _print(const T &x) { cerr << x; }

  template<class A, class B> void _print(const pair<A,B> &p) {
    cerr << '{'; _print(p.first); cerr << ','; _print(p.second); cerr << '}';
  }
  template<typename T> void _print(const vector<T> &v) {
    cerr << '[';
    for (size_t i = 0; i < v.size(); ++i) {
      if (i) cerr << ", ";
      _print(v[i]);
    }
    cerr << ']';
  }

  template<class H, class... T>
  void _dbg(const char *s, H h, T... t) {
    const char *c = strchr(s + 1, ',');
    cerr.write(s, c ? (c - s) : strlen(s));
    cerr << " = ";
    _print(h);
    if constexpr (sizeof...(t) > 0) {
      cerr << ", ";
      _dbg(c + 1, t...);
    }
  }
#else
  #define debug(...) (void)0
#endif


ll gcdll(ll a, ll b){ while(b){ ll t=a%b; a=b; b=t; } return llabs(a); }
inline int pcnt(ull x) {return popcount(x);}
template <integral T>
constexpr T modpow(T base, T exp, T mod) noexcept {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp /= 2;
    }
    return static_cast<T>(res);
}

template<typename T>
vector<T> readvec(int n, bool from_one = false){ int i = 0; if(from_one){i++; n++;} vector<T> v(n); for(i;i<n;i++) cin>>v[i]; return v; }

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> z;
    for (int i = 0; i < n; ++i)
        if (s[i] == '0')
            z.pb(i);
    if (z.empty()) {
        cout << "YES" << nl;
        return;
    }

    vector<char> canL(n, 0), canR(n, 0);
    for (int i : z) {
        canL[i] = (i == 0) || (s[i-1] == '0') || (i >= 2 && s[i-1] == '1' && s[i-2] == '0');
        canR[i] = (i == n-1) || (s[i+1] == '0') || (i + 2 < n && s[i+1] == '1' && s[i+2] == '0');
    }

    int m = z.size();
    int idx = 0;
    while (idx < m) {
        int j = idx;
        while (j + 1 < m && z[j+1] == z[j] + 2 && s[z[j] + 1] == '1')
            ++j;

        int first = z[idx];
        int cur = (canL[first] ? 1 : 0) | (canR[first] ? 2 : 0);
        if (!cur) {
            cout << "NO" << nl;
            return;
        }

        for (int t = idx + 1; t <= j; ++t) {
            int i = z[t];
            int nxt = 0;
            if ((cur & 1) && canR[i])
                nxt |= 2;
            if ((cur & 2) && canL[i])
                nxt |= 1;
            cur = nxt;
            if (!cur) {
                cout << "NO" << nl;
                return;
            }
        }
        idx = j + 1;
    }
    cout << "YES" << nl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
