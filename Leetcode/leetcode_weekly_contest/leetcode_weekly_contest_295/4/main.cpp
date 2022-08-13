#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 1; i < dp.size(); ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int j = 1; j < dp[0].size(); ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }


        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};

int main() {
//    freopen("input.txt", "r", stdin);
    vector<int> strength = {1, 3, 1, 2};
    Solution s;
    int res = s.totalStrength(strength);
    cout << res << endl;

}