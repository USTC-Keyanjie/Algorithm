#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        sort(nums.begin(), nums.end());
        int cnt = 1;
        int left = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - left > k) {
                left = nums[i];
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
    int discount;
    cin >> discount;
    Solution s;
    string res = s.discountPrices(str, discount);
    cout << res << endl;
}