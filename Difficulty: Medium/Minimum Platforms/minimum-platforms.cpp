class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int plat = 0, maxPlat = 0;
        int i = 0, j = 0;
        int n = arr.size();

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                plat++;      // train arrives → need platform
                i++;
            } else {
                plat--;      // train departs → free platform
                j++;
            }
            maxPlat = max(maxPlat, plat);
        }
        return maxPlat;
    }
};
