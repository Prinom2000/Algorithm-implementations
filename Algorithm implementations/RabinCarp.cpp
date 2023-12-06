#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const int MOD = 1e9 + 7;
const int BASE = 256;

vector<int> rabin_karp(const string &text, const string &pattern) {
    vector<int> positions;
    int n = text.size(), m = pattern.size();
    if (n < m) return positions;

    int pattern_hash = 0, current_hash = 0, h = 1;
    for (int i = 0; i < m - 1; i++) {
        h = (h * BASE) % MOD;
    }

    for (int i = 0; i < m; i++) {
        pattern_hash = (BASE * pattern_hash + pattern[i]) % MOD;
        current_hash = (BASE * current_hash + text[i]) % MOD;
    }

    for (int i = 0; i <= n - m; i++) {
        if (current_hash == pattern_hash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) positions.push_back(i);
        }
        if (i < n - m) {
            current_hash = (BASE * (current_hash - h * text[i]) + text[i + m]) % MOD;
            if (current_hash < 0) current_hash += MOD;
        }
    }

    return positions;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string text, pattern;
    cin >> text >> pattern;

    vector<int> positions = rabin_karp(text, pattern);

    if (positions.empty()) {
        cout << "Pattern not found in the text." << endl;
    } else {
        cout << "Pattern found at positions: ";
        for (int pos : positions) {
            cout << pos << " ";
        }
        cout << endl;
    }

    return 0;
}
