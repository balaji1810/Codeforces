#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> primes;
int current_limit = 0;

void build_primes_up_to(int limit){
    if(limit <= current_limit) return;
    vector<char> sieve(limit + 1, true);
    sieve[0] = sieve[1] = false;
    int r = (int)floor(sqrt(limit));
    for(int p = 2; p <= r; ++p){
        if(sieve[p]){
            for(long long j = 1LL*p*p; j <= limit; j += p) sieve[(int)j] = false;
        }
    }
    primes.clear();
    for(int i = 2; i <= limit; ++i) if(sieve[i]) primes.push_back(i);
    current_limit = limit;
}

ll smallest_prime_not_dividing(ll g){
    int limit = max(100, current_limit);
    while(true){
        build_primes_up_to(limit);
        for(int p : primes){
            if(g % p != 0) return p;
        }
        limit = max(limit * 2, limit + 100);
        if(limit > 1000000) limit = 1000000;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; if(!(cin >> t)) return 0;
    while(t--){
        int n; cin >> n;
        long long g = 0;
        for(int i = 0; i < n; ++i){
            long long x; cin >> x;
            g = (i==0 ? x : std::gcd(g, x));
        }
        cout << smallest_prime_not_dividing(g) << '\n';
    }
    return 0;
}
