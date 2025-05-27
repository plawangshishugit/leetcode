class Solution {
public:
    bool canShipWithCapacity(vector<int>& weights, int days, int capacity) {
        int requiredDays = 1;
        int currentLoad = 0;
        
        for (int weight : weights) {
            if (currentLoad + weight > capacity) {
                requiredDays++;
                currentLoad = 0;
            }
            currentLoad += weight;
        }
        return requiredDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canShipWithCapacity(weights, days, mid)) {
                result = mid;
                right = mid - 1; // try to minimize
            } else {
                left = mid + 1;  // need a bigger capacity
            }
        }
        
        return result;
    }
};
