class Solution {
public:
    void findCombination(int ind, int target, vector<int>&arr, vector<vector<int>>&result, vector<int>&ds){
        if(ind == arr.size()){
            if(target == 0){
                result.push_back(ds);
            }
            return;
        }

        //pick
        if(arr[ind] <= target){
            ds.push_back(arr[ind]);
            findCombination(ind, target -arr[ind], arr, result, ds);
            ds.pop_back();
        }

        //not pick
        findCombination(ind +1, target, arr, result, ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>result;
        vector<int> ds;
        findCombination(0, target, candidates, result, ds);
        return result;

    }
};