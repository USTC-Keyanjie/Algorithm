#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        vector<int> next(1e6 + 10), pre(1e6 + 10);

        int a, b, c;
        for (int i = 0; i < operations.size(); ++i) {
            b = operations[i][0];
            c = operations[i][1];
            a = pre[b];


            if (a) {
                next[a] = c;
                pre[c] = a;

                pre[b] = 0;
                next[b] = 0;

            } else {
                next[b] = c;
                pre[c] = b;
            }

        }

        for (int &i: nums) {
            if (next[i])
                i = next[i];
        }
        return nums;
    }
};

int main() {
    vector<int> nums;
    for (int i = 1; i <= 100; ++i) {
        nums.push_back(i);
    }
    vector<vector<int>> operations;
    for (int j = 0; j < 990; ++j) {
        for (int i = 100; i >= 1; --i) {
            operations.push_back(vector<int>{i, i + 1});
        }
    }
    for (int i = 100; i >= 91; --i) {
        operations.push_back(vector<int>{i, i + 1});
    }


    Solution s;
    vector<int> res = s.arrayChange(nums, operations);

}