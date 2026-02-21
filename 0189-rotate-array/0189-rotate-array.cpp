class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
/*
        //left rotation
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
        */
        //right rotation
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};