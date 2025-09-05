class Solution {
public:
    int nextgreater(vector<int>& nums2, int k, int n2) {
        int target = nums2[k];
        for (int i = k + 1; i < n2; i++) {
            if (nums2[i] > target) {
                return nums2[i];  // return first greater element
            }
        }
        return -1;  // no greater element found
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int>ans;
        
        for(int i = 0;i<n1;i++){
            int j = -1;
            for(int k = 0; k<n2; k++){
                if(nums1 [i] == nums2[k]){
                    j=  nextgreater(nums2, k,n2);
                    break;
                }
            }
            ans.push_back(j);
        }
        return ans;
    }
};