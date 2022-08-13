#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        if (directions.size() <= 1)
            return 0;

        int res = 0;
        char status = directions[0];
        int cache = status == 'R' ? 1 : 0;

        for (int i = 1; i < directions.size(); i++)
        {
            char cur = directions[i];
            switch (cur) {
                case 'R':
                    cache += 1;
                    break;
                case 'S':
                    switch (status) {
                        case 'R':
                            res += cache;
                            cache = 0;
                            break;
                        case 'S':
                            break;
                        case 'L':
                            break;
                        default:
                            break;
                    }
                    break;
                case 'L':
                    switch (status) {
                        case 'R':
                            res += cache + 1;
                            cache = 0;
                            break;
                        case 'S':
                            res += 1;
                            break;
                        case 'L':
                            if (cache > 0)
                            {
                                res += cache + 1;
                                cache = 0;
                            }
                            else if (res > 0) {
                                res += 1;
                            }
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;

            }
            status = cur;

        }
        return res;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    string str;
    cin >> str;
    Solution s;
    int res = s.countCollisions(str);
    cout << res << endl;
}