#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool ok(string &s) {
        if (s[0] != '$' || s.length() == 1) return 0;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] < '0' || s[i] > '9') return 0;
        }
        return 1;
    }

    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string s, ret = "";
        bool flag = 0;
        discount = 100 - discount;
        while (ss >> s) {
            if (flag) ret += ' ';
            flag = 1;
            if (ok(s)) {
                long long v = 0;
                for (int i = 1; i < s.length(); ++i) {
                    v = v * 10 + (s[i] - '0');
                }
                v = v * discount;
                ret += '$' + to_string(v / 100) + ".";
                v %= 100;
                if (v == 0) {
                    ret += "00";
                } else if (v % 10 == 0) {
                    ret += to_string(v / 10) + "0";
                } else if (v < 10) {
                    ret += "0" + to_string(v);
                } else {
                    ret += to_string(v);
                }
            } else {
                ret += s;
            }
        }
        return ret;
    }
};


int main() {
    freopen("input.txt", "r", stdin);
    string str;
    cin >> str;
    int discount;
    cin >> discount;
    Solution s;
    string res = s.discountPrices(str, discount);
    cout << res << endl;
}