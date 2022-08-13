#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int cnt = 0, max_cnt = 0, num;
        for (int i = 0; i <= 24; ++i) {
            num = 1 << i;
            cnt = 0;

            for (int can : candidates) {
                if (can & num) {
                    cnt++;
                }
            }
            max_cnt = max_cnt > cnt ? max_cnt : cnt;
            if (max_cnt == candidates.size()) {
                break;
            }
        }
        return max_cnt;
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