#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int> &special) {
        int max = 0, prev = bottom;
        special.insert(special.begin(), bottom - 1);
        special.push_back(top + 1);
        sort(special.begin(), special.end());


        for (int i = 1; i < special.size(); ++i) {
            int dis = special[i] - special[i - 1] - 1;
            max = max > dis ? max : dis;
        }
        return max;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    string str;
    cin >> str;
    Solution s;
    int res = s.countCollisions(str);
    cout << res << endl;
}