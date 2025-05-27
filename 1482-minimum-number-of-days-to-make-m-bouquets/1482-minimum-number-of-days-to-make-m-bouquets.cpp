class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int minimum = *min_element(bloomDay.begin(), bloomDay.end());
        int maximum = *max_element(bloomDay.begin(), bloomDay.end());
        int n = bloomDay.size();

        if ((long long)m * k > n) return -1; // Not enough flowers

        int s = minimum, e = maximum;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int cflower = 0, cnt = 0;

            for (int j = 0; j < n; j++) {
                if (bloomDay[j] <= mid) {
                    cflower++;
                    if (cflower == k) {
                        cnt++;
                        cflower = 0;
                    }
                } else {
                    cflower = 0;
                }
            }

            if (cnt >= m) {
                ans = mid;     // store current valid answer
                e = mid - 1;   // try to minimize the day
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};
