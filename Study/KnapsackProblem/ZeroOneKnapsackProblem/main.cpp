//
// Created by keyanjie on 2022/3/27.
//
#include<bits/stdc++.h>
using namespace std;

/*
 * @params
 * weights：物品重量，从1开始记录
 * values：物品价值，从1开始记录
 * volume：背包重量
 *
 * @return
 * dp[volume]: 背包可装最大价值
 */
int ZeroOneKnapsackProblem(vector<int> &weights, vector<int> &values, int volume)
{
    vector<int> dp(volume + 1);

    // 初始化，这里默认为不需要全部装满
    // 如果未要求全部装满，则初始化为0
    // 如果要求必须全部装满，则除了dp[0]外，全部初始化为-inf
    dp[0] = 0;
    for (int i = 1; i <= volume; ++i) {
        dp[i] = 0;
    }

    int sum = 0;
    for (int j = 1; j < weights.size(); ++j) {
        sum += weights[j];
    }
    for (int i = 1; i < weights.size(); ++i) {
        sum -= weights[i];

        for (int j = volume; j >= max(volume - sum, weights[i]); --j) {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

    return dp[volume];
}

int main()
{
    freopen("input.txt", "r", stdin);

    vector<int> weights, values;

    int n, volume, t;
    cin >> n >> volume;

    for (int i = 0; i < n; ++i) {
        cin >> t;
        weights.push_back(t);
    }

    for (int i = 0; i < n; ++i) {
        cin >> t;
        values.push_back(t);
    }

    int res = ZeroOneKnapsackProblem(weights, values, volume);
    cout << res << endl;
    return 0;
}