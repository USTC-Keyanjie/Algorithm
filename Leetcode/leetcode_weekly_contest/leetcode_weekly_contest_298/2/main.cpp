#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool valid (int n, int num, int k) {
        return (num - n * k >= 0) && (((num - n * k) % 10) == 0);
    }
    int minimumNumbers(int num, int k) {
        if (num == 0) {
            return 0;
        }
        if (!(k & 1) && (num & 1)) {
            return -1;
        }
        for (int n = 1; n <= num; ++n) {
            if (valid(n, num, k)) {
                return n;
            }
            if (n * k > num) {
                break;
            }
        }
        return -1;
    }
};



int main() {
//    freopen("input.txt", "r", stdin);

    Solution s;
    int res = s.minimumNumbers(10, 8);
    cout << res << endl;
}