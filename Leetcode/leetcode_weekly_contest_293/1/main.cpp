#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<string> removeAnagrams(vector<string>& words) {
            vector<string> res;
            if (words.empty()) {
                return res;
            }
            vector<string> words_copy = words;
            for (string& word : words_copy) {
                sort(word.begin(), word.end());
            }
            res.push_back(words[0]);
            for (int i = 1; i < words_copy.size(); ++i) {
                if (words_copy[i] != words_copy[i - 1]) {
                    res.push_back(words[i]);
                }
            }
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