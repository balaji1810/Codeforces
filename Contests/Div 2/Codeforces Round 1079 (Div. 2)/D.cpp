// https://codeforces.com/contest/2197/problem/D
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

// #ifdef LOCAL
//   #define debug(...) cerr << "[DEBUG] ", _dbg(#__VA_ARGS__, __VA_ARGS__), cerr << '\n';
//   template<class T> void _print(const T &x){ cerr<<x; }
//   template<class H, class...T> void _dbg(const char *s, H h, T...t){
//     const char *c = strchr(s+1, ',');
//     cerr.write(s, c ? (c - s) : strlen(s));
//     cerr << " = "; _print(h);
//     if constexpr (sizeof...(t) > 0) { cerr << ", "; _dbg(c+1, t...); }
//   }
// #else
//   #define debug(...) (void)0
// #endif

ll gcdll(ll a, ll b){ while(b){ ll t=a%b; a=b; b=t; } return llabs(a); }

ll modpow(ll a, ll e, ll mod){ ll r=1%mod; a%=mod; while(e){ if(e&1) r=(__int128)r*a%mod; a=(__int128)a*a%mod; e>>=1;} return r; }
inline int pcnt(ull x){ return __builtin_popcountll(x); }

template<typename T>
vector<T> readvec(int n, bool from_one = false){ int i = 0; if(from_one){i++; n++;} vector<T> v(n); for(i;i<n;i++) cin>>v[i]; return v; }

void solve() {
    int n;
    cin >> n;
    auto a = readvec<int>(n, true);

    int B = 1;
    while ((ll)B * B < n) B++;

    ll ans = 0;

    vector<bool> has_val(B + 1, false);
    for (int i = 1; i <= n; i++)
        if (a[i] < B) has_val[a[i]] = true;

    for (int v = 1; v < B; v++) {
        if (!has_val[v]) continue;
        for (int j = 1; j <= n; j++) {
            ll ic = (ll)j - (ll)v * a[j];
            if (ic >= 1 && ic < j && a[(int)ic] == v)
                ans++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] < B) continue;
        for (ll k = 1; ; k++) {
            ll j = i + (ll)a[i] * k;
            if (j > n) break;
            if (a[(int)j] == k)
                ans++;
        }
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
