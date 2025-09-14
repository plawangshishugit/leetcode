class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nsl(n), nsr(n), ngl(n), ngr(n);
        stack<int> st;

        // Next Smaller Left
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            nsl[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        // Next Smaller Right
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            nsr[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        // Next Greater Left
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            ngl[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        // Next Greater Right
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            ngr[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;
        for(int i=0; i<n; i++){
            long long maxCount = (long long)(i - ngl[i]) * (ngr[i] - i);
            long long minCount = (long long)(i - nsl[i]) * (nsr[i] - i);
            ans += (long long)nums[i] * (maxCount - minCount);
        }
        return ans;
    }
};
