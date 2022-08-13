#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> record(26, 0);
        for (char c : s) {
            int idx = c - 'a';
            if (record[idx] == 0) {
                record[idx]++;
            } else {
                return c;
            }
        }
        return 0;
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