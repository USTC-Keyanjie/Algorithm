#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
//        vector<vector<int>> dp(12, vector<int>(numArrows + 1));
        int dp[12][100000 + 5][2];
//        vector<vector<int>> book(12, vector<int>(numArrows + 1));
        int needArrows = 0;
        vector<int> res(12);

        for (int j = numArrows; j >= 0; j--)
        {
            dp[0][j][1] = j;
        }

        for (int i = 1; i <= 11; i++)
        {
            dp[i][numArrows][1] = i;
        }

        for (int i = 1; i <= 11; i++)
        {
            for (int j = numArrows; j > 0; j--)
            {
                needArrows = aliceArrows[i] + 1;
                if (j - needArrows >= 0 && dp[i - 1][j - needArrows][0] + i >= dp[i - 1][j][0])
                {
                    dp[i][j][0] = dp[i - 1][j - needArrows][0] + i;
                    dp[i][j][1] = needArrows;
                }
                else
                {
                    dp[i][j][0] = dp[i - 1][j][0];
                    dp[i][j][1] = 0;
                }
            }
        }

        int j = numArrows;
        for(int i = 11; i >= 0 && j >= 0; i--)
        {
            res[i] = dp[i][j][1];
            j = j - dp[i][j][1];
        }
        return res;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);

    int numArrows, t;
    cin >> numArrows;
    vector<int> aliceArrows(12);
    for (int i = 0; i < 12; ++i) {
        cin >> t;
        aliceArrows[i] = t;
    }

    Solution s;
    vector<int> res = s.maximumBobPoints(numArrows, aliceArrows);
    for (int a : res)
    {
        cout << a << " ";
    }
    cout << endl;

}