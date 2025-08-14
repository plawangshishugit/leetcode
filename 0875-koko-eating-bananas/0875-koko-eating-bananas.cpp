class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long hours = 0;
            for (int p : piles) {
                hours += (p + mid - 1) / mid; // same as ceil(p / mid)
            }

            if (hours <= h) {
                ans = mid;
                high = mid - 1; // try smaller k
            } else {
                low = mid + 1; // need to eat faster
            }
        }
        return ans;
    }
};