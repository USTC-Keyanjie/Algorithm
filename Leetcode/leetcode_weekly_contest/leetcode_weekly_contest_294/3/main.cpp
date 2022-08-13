#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        if (stockPrices.size() < 3) {
            return stockPrices.size() - 1;
        }


        sort(stockPrices.begin(), stockPrices.end(), cmp);
        long long  x1, x2, x3, y1, y2, y3;
        long long  cnt = 1;
        long long t1, t2;
        double rate;
        for (int i = 2; i < stockPrices.size(); ++i) {
            x1 = stockPrices[i-2][0];
            y1 = stockPrices[i-2][1];
            x2 = stockPrices[i-1][0];
            y2 = stockPrices[i-1][1];
            x3 = stockPrices[i][0];
            y3 = stockPrices[i][1];
            t1 = (y2 - y1) * (x3 - x2);
            t2 = (y3 - y2) * (x2 - x1);
            if (t1 != t2) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
//    freopen("input.txt", "r", stdin);
    vector<vector<int>> stockPrices;
    stockPrices.emplace_back(vector<int>{1,1000000000});
    stockPrices.emplace_back(vector<int>{2,999999999});
    stockPrices.emplace_back(vector<int>{999999999,1});
    stockPrices.emplace_back(vector<int>{1000000000,1000000000});
//    stockPrices.emplace_back(vector<int>{4, 4});
//    stockPrices.emplace_back(vector<int>{5, 4});
//    stockPrices.emplace_back(vector<int>{6, 3});
//    stockPrices.emplace_back(vector<int>{7, 2});
//    stockPrices.emplace_back(vector<int>{8, 1});



    Solution s;
    int res = s.minimumLines(stockPrices);
    cout << res << endl;

}