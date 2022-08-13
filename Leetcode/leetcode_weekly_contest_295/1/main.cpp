#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> cnt(26, 0);
        vector<int> cnt2(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        for (char c: target) {
            cnt2[c - 'a']++;
        }

        int num = INT_MAX;
        for (char c: target) {
            if (cnt2[c - 'a'] > 0) {
                int t = cnt[c - 'a'] / cnt2[c - 'a'];
                num = num < t ? num : t;
            }
        }
        if (num == INT_MAX)
            num = 0;
        return num;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    vector<int> arr;
    int a;
    while(cin >> a)
    {
        arr.push_back(a);
    }

    Solution s;
    int res = s.countHillValley(arr);
    cout << res << endl;
}