class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int>& candidates, int target, vector<int> &arr, int i, long current_sum){
        if(current_sum >= target){
            if(current_sum == target) ans.push_back(arr);
            return;
        }
        if(i == candidates.size()){
            return;
        }
        //previous element push
        arr.push_back(candidates[i]);
        helper(ans, candidates, target, arr, i, current_sum + candidates[i]);
        arr.pop_back();

        //current element push
        helper(ans, candidates, target, arr, i+1, current_sum);
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        helper(ans, candidates, target, arr, 0, 0);
        return ans;
    }
};