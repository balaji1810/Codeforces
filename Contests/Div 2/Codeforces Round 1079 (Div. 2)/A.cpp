// https://codeforces.com/contest/2197/problem/A
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

const ll INF = (ll)4e18;
const int INF_INT = 0x3f3f3f3f;

#ifdef LOCAL
  #define debug(...) cerr << "[DEBUG] ", _dbg(#__VA_ARGS__, __VA_ARGS__), cerr << '\n';
  template<class T> void _print(const T &x){ cerr<<x; }
  template<class H, class...T> void _dbg(const char *s, H h, T...t){
    const char *c = strchr(s+1, ',');
    cerr.write(s, c ? (c - s) : strlen(s));
    cerr << " = "; _print(h);
    if(sizeof...(t)) { cerr << ", "; _dbg(c+1, t...); }
  }
#else
  #define debug(...) (void)0
#endif

ll gcdll(ll a, ll b){ while(b){ ll t=a%b; a=b; b=t; } return llabs(a); }

// Compute x^y mod M
ll modpow(ll a, ll e, ll mod){ ll r=1%mod; a%=mod; while(e){ if(e&1) r=(__int128)r*a%mod; a=(__int128)a*a%mod; e>>=1;} return r; }
inline int pcnt(ull x){ return __builtin_popcountll(x); }

template<typename T>
vector<T> readvec(int n){ vector<T> v(n); for(int i=0;i<n;i++) cin>>v[i]; return v; }

int digitSum(ll n) {
  int s = 0;
  while (n > 0) {
    s += int(n % 10);
    n /= 10;
  }
  return s;
}

void solve() {
  ll x;
  cin >> x;

  int ans = 0;
  for (ll y = x; y <= x + 90; y++) {
    if (y - digitSum(y) == x) ans++;
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
