class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int minimum = *min_element(bloomDay.begin(), bloomDay.end());
        int maximum = *max_element(bloomDay.begin(), bloomDay.end());
        int n = bloomDay.size();

        if((long long) m * k > n) {
            return -1;
        }

        int s = minimum;
        int e = maximum;
        int ans = -1;

        while(s <= e){
            int mid = s + (e - s )/2;
            int cnt = 0;
            int cflower = 0;
            for(int i = 0; i<n;i++ ){
                if(bloomDay[i] <= mid){
                    cflower += 1;
                    if(cflower == k){
                        cflower =0;
                        cnt += 1;
                    }
                }
                else{
                    cflower = 0;
                }
            }
            if(cnt >= m){
                ans = mid;
                e = mid -1;
            }
            else{
                s = mid +1;
            }
        }
        return ans;
    }
};