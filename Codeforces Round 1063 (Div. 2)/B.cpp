// Problem: B. Siga ta Kymata (CF Round 1063 Div.2)
// Constructive solution using at most 5 operations that always works when possible.
// Key facts:
// - An index i can be set to 1 iff i is not an endpoint (i!=1,n) and p[i] is not extremal (p[i]!=1,n).
// - Using positions a=pos of 1 and b=pos of n (let l0=min(a,b), r0=max(a,b)), the following 5 intervals cover all such indices:
//   [1,l0], [1,r0], [l0,r0], [l0,n], [r0,n].
//   Their union guarantees that for any i in (1,n) with p[i] in (1,n), at least one operation marks i.
// - If any required index violates the necessary condition above, answer is -1. If none required, answer is 0. Otherwise, output these intervals.

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; if(!(cin>>T)) return 0; while(T--){
		int n; cin>>n; vector<int> p(n+1);
		for(int i=1;i<=n;i++) cin>>p[i];
		string x; cin>>x; x=" "+x; // 1-index
		vector<int> need; need.reserve(n);
		bool bad=false;
		for(int i=1;i<=n;i++) if(x[i]=='1'){
			if(i==1 || i==n) {bad=true; break;} // endpoints cannot be set
			if(p[i]==1 || p[i]==n) {bad=true; break;} // extremal values cannot be interior in any operation
			need.push_back(i);
		}
		if(bad){ cout<<-1<<"\n"; continue; }
		if(need.empty()){ cout<<0<<"\n"; continue; }
		int pos1=-1,posN=-1; for(int i=1;i<=n;i++){ if(p[i]==1) pos1=i; if(p[i]==n) posN=i; }
		int l0=min(pos1,posN), r0=max(pos1,posN);
		// We can output exactly these 5 operations (some may be degenerate or duplicates; still valid and within limit)
		cout<<5<<"\n";
		cout<<1<<" "<<l0<<"\n";
		cout<<1<<" "<<r0<<"\n";
		cout<<l0<<" "<<r0<<"\n";
		cout<<l0<<" "<<n<<"\n";
		cout<<r0<<" "<<n<<"\n";
	}
	return 0;
}

