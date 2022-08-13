#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        if (nums.size() < 2)
        {
            return 0;
        }

        int cnt = 0;
        int status = 0;
        int i = 1;
//        if(nums[0] != nums[1])
//        {
//            status = nums[i - 1] < nums[i] ? 1 : -1;
//        }

        while(i < nums.size())
        {
            if (nums[i - 1] < nums[i])
            {
                if (status == -1)
                {
                    cnt += 1;
                }
                status = 1;
            }
            else if (nums[i - 1] > nums[i])
            {
                if (status == 1)
                {
                    cnt += 1;
                }
                status = -1;
            }

            i++;
        }

        return cnt;
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