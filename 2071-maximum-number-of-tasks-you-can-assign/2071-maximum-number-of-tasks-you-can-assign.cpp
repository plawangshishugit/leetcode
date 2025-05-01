class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        
        int left = 0;
        int right = min(tasks.size(), workers.size());
        int answer = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canComplete(tasks, workers, pills, strength, mid)) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return answer;
    }
    
private:
    bool canComplete(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k) {
        if (k == 0) return true;
        if (k > workers.size()) return false;
        
        multiset<int> workerSet(workers.end() - k, workers.end());
        int usedPills = 0;
        
        for (int i = k - 1; i >= 0; --i) {
            auto it = workerSet.lower_bound(tasks[i]);
            if (it != workerSet.end()) {
                workerSet.erase(it);
            } else {
                if (usedPills >= pills) {
                    return false;
                }
                it = workerSet.lower_bound(tasks[i] - strength);
                if (it != workerSet.end()) {
                    workerSet.erase(it);
                    usedPills++;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};