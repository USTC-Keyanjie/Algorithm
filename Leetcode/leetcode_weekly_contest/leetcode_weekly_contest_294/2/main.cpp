#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> left(capacity.size(), 0);
        for (int i = 0; i < left.size(); ++i) {
            left[i] = capacity[i] - rocks[i];
        }

        sort(left.begin(), left.end());
        int cnt = 0;
        for (int i = 0; i < left && additionalRocks > 0; ++i) {
            if (additionalRocks >= left[i]) {
                additionalRocks -= left[i];
                cnt++;
            }
        }
        return cnt;
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