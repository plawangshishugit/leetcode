class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_set<string> buildingSet;
        unordered_map<int, vector<int>> rowMap; 
        unordered_map<int, vector<int>> colMap; 

        for (const auto& building : buildings) {
            int x = building[0];
            int y = building[1];
            buildingSet.insert(to_string(x) + "," + to_string(y));
            rowMap[x].push_back(y);
            colMap[y].push_back(x);
        }

        for (auto& entry : rowMap) {
            sort(entry.second.begin(), entry.second.end());
        }
        for (auto& entry : colMap) {
            sort(entry.second.begin(), entry.second.end());
        }

        int covered = 0;
        for (const auto& building : buildings) {
            int x = building[0];
            int y = building[1];

            // Check left
            bool hasLeft = false;
            auto rowIt = rowMap.find(x);
            if (rowIt != rowMap.end()) {
                const auto& cols = rowIt->second;
                auto it = lower_bound(cols.begin(), cols.end(), y);
                if (it != cols.begin()) {
                    hasLeft = true;
                }
            }

            // Check right
            bool hasRight = false;
            if (rowIt != rowMap.end()) {
                const auto& cols = rowIt->second;
                auto it = upper_bound(cols.begin(), cols.end(), y);
                if (it != cols.end()) {
                    hasRight = true;
                }
            }

            // Check above
            bool hasAbove = false;
            auto colIt = colMap.find(y);
            if (colIt != colMap.end()) {
                const auto& rows = colIt->second;
                auto it = lower_bound(rows.begin(), rows.end(), x);
                if (it != rows.begin()) {
                    hasAbove = true;
                }
            }

            // Check below
            bool hasBelow = false;
            if (colIt != colMap.end()) {
                const auto& rows = colIt->second;
                auto it = upper_bound(rows.begin(), rows.end(), x);
                if (it != rows.end()) {
                    hasBelow = true;
                }
            }

            if (hasLeft && hasRight && hasAbove && hasBelow) {
                covered++;
            }
        }

        return covered;
    }
};