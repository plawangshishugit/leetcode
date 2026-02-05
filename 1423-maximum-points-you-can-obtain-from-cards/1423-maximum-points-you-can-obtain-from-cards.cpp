class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, rsum = 0;
        int maxS = 0;
        int n = cardPoints.size();

        // take first k cards from left
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }

        maxS = lsum;

        // slide: remove from left, add from right
        for (int i = k - 1; i >= 0; i--) {
            lsum -= cardPoints[i];
            rsum += cardPoints[n - (k - i)];
            maxS = max(maxS, lsum + rsum);
        }

        return maxS;
    }
};
