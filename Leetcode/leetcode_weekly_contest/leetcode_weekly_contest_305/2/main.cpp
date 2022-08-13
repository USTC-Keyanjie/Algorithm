#include <bits/stdc++.h>

using namespace std;

class Solution {

    vector<int> parent;
    vector<int> size;

// 不同于 DisjointSetUnion_Rank 中的 Find 方法，后者通过递归将路径上的节点的parent都修改为根结点。
// 本方法 减少层数的访问，以便达提高 Find 的效率。
    int Find(int x) {
        while (x != parent[x]) {
            // 路径压缩, 下次查找时, 树的层数减少了。
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    }

    void Union(int x, int y) {
        int xRoot = Find(x);
        int yRoot = Find(y);

        if (xRoot == yRoot) {
            return;
        }

        if (size[xRoot] < size[yRoot]) {
            parent[xRoot] = yRoot;
            size[yRoot] += size[xRoot];
        } else {
            parent[yRoot] = xRoot;
            size[xRoot] += size[yRoot];
        }
    }

    bool IsConnect(int x, int y) {
        return Find(x) == Find(y);
    }

public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        unordered_set<int> restricted_set = unordered_set<int>(restricted.begin(), restricted.end());
        int src, dst;
        for (vector<int> edge: edges) {
            src = edge[0], dst = edge[1];
            if (restricted_set.find(src) != restricted_set.end() ||
                restricted_set.find(dst) != restricted_set.end()) {
                continue;
            }
            Union(src, dst);
        }
        return size[Find(0)];
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