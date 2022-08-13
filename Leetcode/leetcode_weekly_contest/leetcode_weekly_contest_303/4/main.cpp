#include <bits/stdc++.h>

using namespace std;

class Solution {
    int hamming_weight(int n) {
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
        n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
        return n;
    }

public:
    long long countExcellentPairs(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int n = nums.size();
        long long res = 0;

        int n1, n2 = 0;
        for (auto it = nums.begin(); it != nums.end();) {
            if (hamming_weight(*it) >= k) {
                n2 += 1;
                it = nums.erase(it);
            } else {
                ++it;
            }
        }
        n1 = n - n2;
        res += n1 * n2 * 2;

        for (int i = 0; i < n1; ++i) {
            if (hamming_weight(nums[i] & nums[i]) + hamming_weight(nums[i] | nums[i]) >= k) {
                res += 1;
            }
        }


        for (int i = 0; i < n1; ++i) {
            for (int j = i + i; j < n1; ++j) {
                if (hamming_weight(nums[i] & nums[j]) + hamming_weight(nums[i] | nums[j]) >= k) {
                    res += 2;
                }
            }
        }

        return res;
    }
};

int main() {
//    freopen("input.txt", "r", stdin);
    vector<int> nums = {134217727, 7, 268435455, 3, 536870911, 1};
    int k = 30;
    Solution s;
    long long res = s.countExcellentPairs(nums, k);
    cout << res << endl;

}