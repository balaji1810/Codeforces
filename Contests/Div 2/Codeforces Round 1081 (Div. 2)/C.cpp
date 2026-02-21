#include <bits/stdc++.h>
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
  #define debug(...) (cerr << "[DEBUG] ", _dbg(#__VA_ARGS__, __VA_ARGS__), cerr << nl)
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
    ll n, h, k;
    cin >> n >> h >> k;
    auto a = readvec<ll>(n);
    ll S = 0;
    for (ll x : a)
        S += x;

    vector<ll> pre(n + 1, 0);
    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + a[i];

    vector<ll> suf_max(n + 2, 0);
    suf_max[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        suf_max[i] = max(a[i], suf_max[i + 1]);

    vector<ll> pre_min(n + 1, INF);
    for (int i = 0; i < n; i++)
        pre_min[i + 1] = min(pre_min[i], a[i]);

    ll ans = INF;
    for (int p = 1; p <= n; p++) {
        ll gain = (suf_max[p] == 0) ? 0LL : max(0LL, suf_max[p] - pre_min[p]);
        ll best = pre[p] + gain;
        ll r;
        if (best >= h) {
            r = 0;
        } else {
            r = (h - best + S - 1) / S;
        }
        ll t = r * (n + k) + p;
        ans = min(ans, t);
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
