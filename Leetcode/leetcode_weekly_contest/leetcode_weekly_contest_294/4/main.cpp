#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int totalStrength(vector<int>& a)
    {
        int n = a.size();
        const long long MOD = 1000000007;

        vector<long long> b(n + 1);
        for (int i = 0; i < n; ++i) {
            b[i + 1] = (b[i] + a[i]) % MOD;
        }

        struct Seg {
            long long val;
            long long count;
            long long sum;
        };

        vector<Seg> s;
        s.push_back({0, 0});

        long long result = 0;
        long long s1 = 0;
        long long s2 = 0;
        for (int i = n - 1; i >= 0; --i) {
            Seg cur;
            cur.val = a[i];
            cur.count = 1;
            cur.sum = b[i + 1];
            while (s.back().val >= cur.val) {
                const auto& ss = s.back();
                s1 = (s1 - ss.val * ss.sum) % MOD;
                s2 = (s2 - ss.val * ss.count) % MOD;
                cur.sum += ss.sum;
                cur.count += ss.count;
                cur.sum %= MOD;
                s.pop_back();
            }
            s1 = (s1 + cur.val * cur.sum) % MOD;
            s2 = (s2 + cur.val * cur.count) % MOD;
            s.push_back(cur);
            result = (result + s1) % MOD;
            result = (result - s2 * b[i]) % MOD;
        }
        result %= MOD;
        result += MOD;
        result %= MOD;
        return (int)result;
    }
};

int main() {
//    freopen("input.txt", "r", stdin);
    vector<int> strength = {1, 3, 1, 2};
    Solution s;
    int res = s.totalStrength(strength);
    cout << res << endl;

}