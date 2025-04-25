class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int len = size(nums);
        int maxi =0;
        for (int i =0; i<len;i++){
            if(maxi <nums[i]){
                maxi = nums[i];
            }

        }
        cout<<maxi;
        vector<int>arr(maxi + 1, 0);
        int maxfreq =0;

        for ( int i =0; i< len ; i++){
            arr[nums[i]]++;
            if( maxfreq < arr[nums[i]]){
                maxfreq = arr[nums[i]];

            }
        }
       int ans = 0;
        for (int i =0; i<= maxi; i++){
            if (arr[i]== maxfreq){
                ans += maxfreq;
            }
        }

        return ans;

    }
    
};