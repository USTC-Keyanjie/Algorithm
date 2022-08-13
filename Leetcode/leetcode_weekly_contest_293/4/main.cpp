#include <bits/stdc++.h>

using namespace std;

class CountIntervals {
public:
    set<pair<int, int>> s;
    int cnt = 0;
    CountIntervals() {

    }

    void add(int left, int right) {
        auto it = s.lower_bound(make_pair(left, right));
        if (it != s.begin()) it--;
        vector<pair<int, int>> to_erase;

        int l = left, r = right;
        while (it != s.end() && it->first <= right + 1) {
            if (it->second >= left - 1) {
                to_erase.push_back(*it);
                l = l < it->first ? l : it->first;
                r = r > it->second ? r : it->second;
            }
            it++;
        }

        for (pair<int, int> &p : to_erase) {
            s.erase(p);
            cnt -= p.second - p.first + 1;
        }
        s.insert(make_pair(l, r));
        cnt += r - l + 1;
    }

    int count() {
        return cnt;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    CountIntervals *obj = new CountIntervals();
    obj->add(2, 3);
    obj->add(7, 10);
    cout << obj->count() << endl;
    obj->add(4, 8);
    cout << obj->count() << endl;
}