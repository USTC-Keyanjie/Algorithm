#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

class Solution {
public:
    ull wrap(ull x, ull y) {
        return (x * x ^ y * y) - y;
    }

    ull nextHash(ull cur_hash, ull left, ull left2, ull rightp, ull right, ull B, ull Bn) {
        cout << setbase(16) << (((cur_hash ^ wrap(left, rightp)) - Bn * left) * B + right * B) << " ^ " << wrap(left2, right) << " = ";

        return (((cur_hash ^ wrap(left, rightp)) - Bn * left) * B + right * B) ^ wrap(left2, right);
    }

    ull getHash(string s, ull Bs[]) {
        ull res = 0;
        for (int i = 0; i < s.length(); ++i) {
            res += Bs[s.length() - i] * s[i];
        }
        cout << setbase(16) << res << " ^ " << wrap(s[0], s[s.length() - 1]) << " = ";

        return res ^ wrap(s[0], s[s.length() - 1]);
    }

    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> res;
        int s_len = s.length();
        int n = words.size();
        int word_len = words[0].length();
        ull Bs[word_len + 1], B = 998244353;
        Bs[0] = 1;
        for (int i = 1; i <= word_len; ++i) {
            Bs[i] = Bs[i - 1] * B;
        }
        ull Hs[s_len + 1];
        cout << s.substr(0, word_len) << " ";
        Hs[0] = getHash(s.substr(0, word_len), Bs);
        cout << Hs[0] << endl;
        for (int i = 1; i <= s_len - word_len; ++i) {
            cout << s.substr(i, word_len) << " ";
            Hs[i] = nextHash(Hs[i - 1], s[i - 1], s[i], s[i + word_len - 2], s[i + word_len - 1], B, Bs[word_len]);
            cout << Hs[i] << endl;
        }
        ull target = 0;
        for (auto s: words) {
            cout << s << " ";
            ull t = getHash(s, Bs);
            cout << setbase(16) << t << endl;
            target += t;
        }
        cout << setbase(16) << target << endl;

        int total = word_len * n;
        for (int start = 0; start < word_len && start + total <= s_len; ++start) {
            ull cur_hash = 0;
            for (int i = 0; i < n; ++i) {
                ull t = Hs[start + i * word_len];
                cout << setbase(16) << t << endl;
                cur_hash += t;
            }
            cout << setbase(16) << cur_hash << endl;

            if (cur_hash == target) {
                res.push_back(start);
            }
            int left = start, right = start + n * word_len;
            while (right < s_len) {
                cur_hash += Hs[right] - Hs[left];
                left += word_len;
                right += word_len;
                if (cur_hash == target) {
                    res.push_back(left);
                }
            }
        }
        return res;
    }
};

int main() {
//    freopen("input.txt", "r", stdin);
    Solution s;
    vector<string> words{"abz", "aez"};
    vector<int> res = s.findSubstring(
            "aczadz",
            words
    );
    return 0;
}