#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalSteps(vector<int> &nums) {
        int res = 0;
        stack<int> st; // pos
        vector<int> t(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            int curValley = 0;
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                curValley = max(curValley, t[st.top()]);
//                curValley = t[st.top()];
                st.pop();
            }
            if (!st.empty()) {
                t[i] = curValley + 1;
                res = max(res, t[i]);
            }
            st.push(i);
        }

        return res;
    }
};

int main() {
    vector<int> nums = {7, 14, 4, 14, 13, 2, 6, 13};
    Solution s;
    int res = s.totalSteps(nums);
    cout << res << endl;

}