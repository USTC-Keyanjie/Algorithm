#include <bits/stdc++.h>

using namespace std;

class Solution {

public:
    int res = 0;
    vector<unordered_set<int>> g;

    void dfs(int cur_node, int pre_node) {
        res++;
        for (int it : g[cur_node]) {
            if (it != pre_node)
                dfs(it, cur_node);
        }
    }

    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted) {
        unordered_set<int> r(restricted.begin(),  restricted.end());

        g.resize(n);
        int src, dst;
        for (vector<int> &edge: edges) {
            src = edge[0], dst = edge[1];
            if (r.find(src) != r.end() || r.find(dst) != r.end()) {
                continue;
            }
            g[src].insert(dst);
            g[dst].insert(src);
        }
        dfs(0, -1);
        return res;
    }

};

void input_int_array(vector<int> &arr, string str) {
    string cache;
    for (char c: str) {
        switch (c) {
            case '[':
                cache = "";
                break;
            case ',':
                arr.push_back(stoi(cache));
                cache = "";
                break;
            case ']':
                arr.push_back(stoi(cache));
                break;
            default:
                cache += c;
                break;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    vector<vector<int>> edges;
    vector<int> restricted;

    cin >> n;
    edges.resize(6);
    string str;
    for (vector<int> &edge: edges) {
        cin >> str;
        input_int_array(edge, str);
    }
    cin >> str;
    input_int_array(restricted, str);


    Solution s;
    int res = s.reachableNodes(n, edges, restricted);
    cout << res << endl;
}