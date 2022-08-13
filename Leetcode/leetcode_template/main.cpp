#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

class Solution {
public:
    int function() {
        return 0;
    }
};

void input_int_array(vector<int> &arr, string str) {
    string cache;
    for (char c: str) {
        switch (c) {
            case '[':
                cache = "";
                break;
            case ',':
                arr.push_back(stoi(cache));
                cache = "";
                break;
            case ']':
                arr.push_back(stoi(cache));
                break;
            default:
                cache += c;
                break;
        }
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
    Solution s;
    auto res = s.function();
    cout << res << endl;
    return 0;
}