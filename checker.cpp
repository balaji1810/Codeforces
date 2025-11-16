// checker.cpp
// Compile: g++ -std=c++17 -O2 checker.cpp -o checker
// Usage: checker.exe output.txt test.txt [--ignore-ws] [--float-eps=1e-6] [--max-diffs=100]

#include <bits/stdc++.h>
using namespace std;

static string progName;

void usage() {
    cerr << "Usage: " << progName << " actual_file expected_file [--ignore-ws] [--float-eps=1e-6] [--max-diffs=100]\n";
    exit(2);
}

string normalize_ws(const string &s) {
    string out;
    bool in_space = false;
    for (char c : s) {
        if (isspace((unsigned char)c)) {
            if (!in_space) { out.push_back(' '); in_space = true; }
        } else {
            out.push_back(c);
            in_space = false;
        }
    }
    // trim leading/trailing space
    if (!out.empty() && out.front()==' ') out.erase(out.begin());
    if (!out.empty() && out.back()==' ') out.pop_back();
    return out;
}

vector<string> split_ws(const string &s) {
    vector<string> tokens;
    istringstream iss(s);
    string tok;
    while (iss >> tok) tokens.push_back(tok);
    return tokens;
}

bool looks_like_number(const string &t) {
    // simple check: contains digit or '.' or 'e' or '-' or '+'
    bool has_digit = false;
    for (char c : t) if (isdigit((unsigned char)c)) has_digit = true;
    if (!has_digit) return false;
    for (char c : t) {
        if (!(isdigit((unsigned char)c) || c=='.' || c=='e' || c=='E' || c=='+' || c=='-')) return false;
    }
    return true;
}

bool almost_equal_double(const string &a, const string &b, double eps) {
    try {
        long double va = stold(a);
        long double vb = stold(b);
        long double diff = fabsl(va - vb);
        long double denom = max((long double)1.0L, fabsl(vb));
        return diff <= eps * denom || diff <= eps;
    } catch(...) {
        return false;
    }
}

string show_invisibles(const string &s) {
    string r;
    for (char c : s) {
        if (c == ' ') r += "·";
        else if (c == '\t') r += "\\t";
        else if (c == '\r') r += "\\r";
        else r.push_back(c);
    }
    return r;
}

int main(int argc, char** argv) {
    progName = argv[0];
    if (argc < 3) usage();

    string actual_path = argv[1];
    string expected_path = argv[2];

    bool ignore_ws = false;
    double float_eps = 0.0; // 0 means disabled
    int max_diffs = 100;

    for (int i = 3; i < argc; ++i) {
        string a = argv[i];
        if (a == "--ignore-ws") ignore_ws = true;
        else if (a.rfind("--float-eps=", 0) == 0) {
            string val = a.substr(strlen("--float-eps="));
            try { float_eps = stod(val); } catch(...) { cerr<<"Invalid float eps\n"; return 2; }
        } else if (a.rfind("--max-diffs=", 0) == 0) {
            string val = a.substr(strlen("--max-diffs="));
            try { max_diffs = stoi(val); } catch(...) { cerr<<"Invalid max-diffs\n"; return 2; }
        } else {
            usage();
        }
    }

    ifstream fa(actual_path);
    ifstream fb(expected_path);
    if (!fa.is_open()) { cerr << "Can't open actual file: " << actual_path << "\n"; return 2; }
    if (!fb.is_open()) { cerr << "Can't open expected file: " << expected_path << "\n"; return 2; }

    string A, B;
    long long lineno = 0;
    int diff_count = 0;
    bool mismatch_found = false;

    while (true) {
        bool ra = static_cast<bool>(getline(fa, A));
        bool rb = static_cast<bool>(getline(fb, B));
        if (!ra && !rb) break; // both EOF
        lineno++;

        string a_line = A;
        string b_line = B;
        if (ignore_ws) {
            a_line = normalize_ws(A);
            b_line = normalize_ws(B);
        }

        if (a_line == b_line) {
            continue;
        }

        // not equal -> more analysis
        mismatch_found = true;
        diff_count++;
        if (diff_count <= max_diffs) {
            cout << "Difference #" << diff_count << " at line " << lineno << ":\n";
            cout << "  Actual  : \"" << show_invisibles(A) << "\"\n";
            cout << "  Expected: \"" << show_invisibles(B) << "\"\n";

            // character-level first differing position
            size_t n = min(A.size(), B.size());
            size_t pos = 0;
            while (pos < n && A[pos] == B[pos]) ++pos;
            if (pos < n || A.size() != B.size()) {
                cout << "  First differing character index: " << pos << "\n";
                string caret(pos, ' ');
                caret += '^';
                cout << "  " << show_invisibles(A) << "\n";
                cout << "  " << caret << "\n";
            }

            // token-level analysis
            vector<string> toksA = split_ws(a_line);
            vector<string> toksB = split_ws(b_line);
            size_t tn = min(toksA.size(), toksB.size());
            bool token_diff_reported = false;
            for (size_t i=0;i<tn;i++) {
                if (toksA[i] == toksB[i]) continue;
                // if numeric tolerance configured and both look numeric, compare numerically
                if (float_eps > 0.0 && looks_like_number(toksA[i]) && looks_like_number(toksB[i]) &&
                    almost_equal_double(toksA[i], toksB[i], float_eps)) {
                    continue; // treat as equal
                }
                cout << "  Token mismatch at token index " << (i+1) << ":\n";
                cout << "    Actual token  : " << toksA[i] << "\n";
                cout << "    Expected token: " << toksB[i] << "\n";
                token_diff_reported = true;
                break;
            }
            if (!token_diff_reported) {
                if (toksA.size() != toksB.size()) {
                    cout << "  Token counts differ: actual=" << toksA.size() << " expected=" << toksB.size() << "\n";
                } else {
                    // tokens same but lines differ (likely whitespace differences)
                    cout << "  Lines differ but tokens are identical (likely whitespace differences or invisible chars).\n";
                }
            }
            cout << "\n";
        }

        if (diff_count >= max_diffs) {
            cout << "Reached max-diffs (" << max_diffs << "), stopping further reports.\n";
            break;
        }
    }

    // If one file still has more lines, count remaining
    long long extraA = 0, extraB = 0;
    string tmp;
    while (getline(fa, tmp)) extraA++;
    while (getline(fb, tmp)) extraB++;

    if (extraA > 0 || extraB > 0) {
        mismatch_found = true;
        cout << "Extra lines after line " << lineno << ":\n";
        if (extraA > 0) cout << "  Actual has " << extraA << " extra line(s).\n";
        if (extraB > 0) cout << "  Expected has " << extraB << " extra line(s).\n";
    }

    if (!mismatch_found) {
        cout << "OK: files are identical (given the options used).\n";
        return 0;
    } else {
        cout << "SUMMARY: total differences found (lines): " << diff_count + extraA + extraB << "\n";
        return 1;
    }
}
