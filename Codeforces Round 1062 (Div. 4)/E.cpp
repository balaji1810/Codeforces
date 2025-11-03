#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

struct Seg {
    int type;
    int64 L, R;
    int64 cur_d;
    int64 remaining;
    int64 maxd;
    int64 used_count;
    int64 total_len;   
    Seg() {}
};

struct HeapEntry {
    int64 dist;
    int id;
    bool operator<(HeapEntry const& o) const {
        return dist < o.dist;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while(T--){
        int n; int64 k, x;
        cin >> n >> k >> x;
        vector<int64> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(), a.end());
        vector<int64> b;
        for(int i=0;i<n;i++){
            if(i==0 || a[i]!=a[i-1]) b.push_back(a[i]);
        }
        a.swap(b);
        n = (int)a.size();

        vector<Seg> segs;
        // left
        if(n==0){
            // no friends: whole [0,x] available. distances are huge; we can output first k integers 0..k-1
        } else {
            if(a[0] > 0){
                Seg s;
                s.type = 0;
                s.L = 0; s.R = a[0]-1;
                s.total_len = a[0];
                s.maxd = a[0];
                s.cur_d = s.maxd;
                s.remaining = 1;
                s.used_count = 0;
                segs.push_back(s);
            }

            for(int i=0;i+1<n;i++){
                int64 m = a[i+1] - a[i] - 1;
                if(m <= 0) continue;
                Seg s;
                s.type = 1;
                s.L = a[i];
                s.R = a[i+1];
                s.total_len = m;
                s.maxd = (m + 1) / 2;
                s.cur_d = s.maxd;
                if(m % 2 == 1) s.remaining = 1;
                else s.remaining = 2;
                s.used_count = 0;
                segs.push_back(s);
            }

            if(a.back() < x){
                Seg s;
                s.type = 2;
                s.L = a.back();
                s.R = x;
                s.total_len = x - a.back();
                s.maxd = x - a.back();
                s.cur_d = s.maxd;
                s.remaining = 1;
                s.used_count = 0;
                segs.push_back(s);
            }
        }

        priority_queue<HeapEntry> pq;
        for(int i=0;i<(int)segs.size();++i){
            if(segs[i].total_len > 0 && segs[i].cur_d >= 1){
                pq.push({segs[i].cur_d, i});
            }
        }

        vector<int64> answer;
        answer.reserve((size_t)k);

        auto produce_pos = [&](int seg_id)->int64{
            Seg &s = segs[seg_id];
            int64 pos = -1;
            if(s.type == 0){
                int64 a1 = s.R + 1;
                int64 d = s.cur_d;
                pos = a1 - d;
                s.used_count++;
                s.cur_d = s.maxd - s.used_count;
                if(s.cur_d < 1) s.cur_d = 0;
            } else if(s.type == 2){
                int64 an = s.L;
                int64 d = s.cur_d;
                pos = an + d;
                s.used_count++;
                s.cur_d = s.maxd - s.used_count;
                if(s.cur_d < 1) s.cur_d = 0;
            } else {
                int64 d = s.cur_d;
                if(s.remaining == 1){
                    pos = s.L + d;
                    s.remaining = 0;
                    s.cur_d--;
                    if(s.cur_d >= 1){
                        s.remaining = 2;
                    } else {
                        s.remaining = 0;
                    }
                } else if(s.remaining == 2){
                    if(s.used_count % 2 == 0){
                        pos = s.L + d;
                        s.remaining = 1;
                    } else {
                        pos = s.R - d;
                        s.remaining = 0;
                        s.cur_d--;
                        if(s.cur_d >= 1) s.remaining = 2;
                    }
                    s.used_count++;
                } else {
                    pos = s.L + 1;
                }
            }
            return pos;
        };

        while((int)answer.size() < (int)k && !pq.empty()){
            auto top = pq.top(); pq.pop();
            int idx = top.id;
            int64 d = top.dist;
            int64 pos = produce_pos(idx);
            if(pos < 0) pos = 0;
            if(pos > x) pos = x;
            answer.push_back(pos);
            Seg &s = segs[idx];
            if(s.cur_d >= 1){
                pq.push({s.cur_d, idx});
            }
        }

        if((int)answer.size() < (int)k){
            unordered_set<int64> forbid;
            forbid.reserve(n*2 + answer.size()*2);
            for(auto v : a) forbid.insert(v);
            for(auto v : answer) forbid.insert(v);
            for(int64 v = 0; v <= x && (int)answer.size() < (int)k; ++v){
                if(forbid.find(v) == forbid.end()){
                    answer.push_back(v);
                    forbid.insert(v);
                }
            }
            for(int64 v = 0; v <= x && (int)answer.size() < (int)k; ++v){
                bool already = false;
                for(auto w : answer) if(w==v) { already = true; break; }
                if(!already) answer.push_back(v);
            }
        }

        for(int i=0;i<(int)k;i++){
            if(i) cout << ' ';
            cout << answer[i];
        }
        cout << '\n';
    }
    return 0;
}
