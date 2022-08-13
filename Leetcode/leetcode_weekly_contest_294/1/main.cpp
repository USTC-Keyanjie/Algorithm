#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        float cnt = 0;
        for (char c: s) {
            if (c == letter) cnt++;

        }
        int res = cnt / s.size() * 100;
        return res;
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