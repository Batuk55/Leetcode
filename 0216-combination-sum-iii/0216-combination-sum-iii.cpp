class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int>& nums, int k, int n, vector<int> &arr, int i, long current_sum){

        if(current_sum > n || arr.size() > k) return;
        if(current_sum== n && arr.size()== k){
            ans.push_back(arr);
            return;
        }
        if(i == nums.size()){
            return;
        }
        //include
        arr.push_back(nums[i]);
        helper(ans, nums, k, n, arr, i+1, current_sum + nums[i]); // used running sum(in recursion) we could have used a seperate sumofarr function in each recursive step as well, but increased SC due to increased O(k) sum calculation each time.
        arr.pop_back();

        //not-include
        helper(ans, nums, k, n, arr, i+1, current_sum);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans;
        vector<int> arr;

        helper(ans, nums, k, n, arr, 0, 0);

        return ans;        
    }
};