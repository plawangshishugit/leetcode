#include <vector>
#include <numeric>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot == yRoot) return;
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);
        vector<pair<int, int>> indexedNums(n);
        for (int i = 0; i < n; ++i) {
            indexedNums[i] = {nums[i], i};
        }

        sort(indexedNums.begin(), indexedNums.end());

        for (int i = 0; i < n - 1; ++i) {
            int val1 = indexedNums[i].first;
            int idx1 = indexedNums[i].second;
            int val2 = indexedNums[i + 1].first;
            int idx2 = indexedNums[i + 1].second;
            if (val2 - val1 <= maxDiff) {
                dsu.unite(idx1, idx2);
            }
        }

        vector<bool> answer;
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            answer.push_back(dsu.find(u) == dsu.find(v));
        }

        return answer;
    }
};
