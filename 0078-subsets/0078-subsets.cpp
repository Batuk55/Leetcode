class Solution {
public:
void helper(vector<vector<int>> &ans, vector<int>&arr, vector<int>&nums, int i){
        if(i == nums.size()){
            ans.push_back({arr});
            return;
        }
        //include
        arr.push_back(nums[i]);
        helper(ans, arr, nums, i+1);
        arr.pop_back();

        //not-included
        helper(ans, arr, nums, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        helper(ans, arr, nums, 0);

        return ans;
    }
};